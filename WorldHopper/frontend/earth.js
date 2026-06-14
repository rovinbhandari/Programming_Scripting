import * as THREE from 'three';

const backendUrl = import.meta.env.VITE_BACKEND_URL ?? 'http://localhost:8080'; // override via VITE_BACKEND_URL
const earthRadius = 6;
const flyerExtensions = ['svg', 'png', 'jpg', 'jpeg', 'webp'];
const flyerLevitation = 0.6; // lift sprites just clear of the surface so they aren't clipped
const flyerTextureSize = 256; // rasterize flyers to this square size for reliable WebGL upload
const flyerScale = earthRadius * 0.18; // sprite size at the rest distance; scaled with distance for a steady on-screen size
const flyerClusterRadius = earthRadius * 0.08; // when flyers share a spot, fan them on a ring this far from the shared anchor
const targetDurationSeconds = 200; // wall-clock seconds to replay the whole timeline at 1× (Phase 4 externalizes this)
const msPerDay = 86_400_000;
const hopDuration = 1.5;       // seconds a flyer takes to travel one hop arc
const arcLift = 0.25;          // arc bulge above the surface, as a fraction of the radius
const shortHopLiftFloor = 0.24; // tiny hops still bulge to at least this fraction of arcLift, so they read as an arc
const arcClearance = earthRadius * 0.075; // draw the arc this far below the flyer so it reads as a trail beneath, not through, it
const arcFadeSeconds = 0.5;    // fade the arc out over this long after arrival
const arcSegments = 48;
const arcShaftHalfWidth = earthRadius * 0.02;  // half-width of the flat arrow ribbon (wider + flatter than a tube)
const arcHeadHalfWidth = earthRadius * 0.06;   // half-width of the broad, flat arrowhead base
const arcHeadLength = earthRadius * 0.14;      // how far back from the tip the arrowhead reaches
const arcShortHopWidthScale = 2.2;             // short hops widen their arrow up to this factor so the tiny arc stays legible
const longHopColor = 0xff3b30; // red
const shortHopColor = 0x0a84ff; // blue
const shortHopDuration = 1.0;  // seconds per leg of a short hop — a touch quicker than a long hop
const shortHopStay = 0.6;      // seconds paused at the visited place before heading home
const blueTimeSlowdown = 0.8;  // slow the clock to (1 - this) of normal while a short hop plays, so the brief trip stays legible
const loopHoldSeconds = 3;     // hold on the final hop (so its arc can play) before looping
const centerSlewRate = 5;      // how briskly the globe slews to centre the active hop (higher = snappier)
const idleSpinRate = 0.15;     // radians/second of natural eastward spin when nothing is hopping
const reverseAngleCap = Math.PI / 3; // re-centring may turn west by at most this much; wider gaps take the eastward long way (note #1)
const tiltEaseRate = 1.5;      // how briskly the polar-axis tilt eases toward its target (flyer latitude band, or upright)
const maxAxisTilt = THREE.MathUtils.degToRad(45); // cap the axial lean so framing favours flyers without flipping toward a pole (note #3)
const lookaheadSeconds = 2.5;  // wall-clock seconds before a hop to begin pre-rotating toward it, so it's framed on arrival (note #2)
const lookaheadSlewRate = 1.5; // gentle slew while pre-positioning for an upcoming hop, vs the snappier centerSlewRate mid-hop
const cameraMinDistance = earthRadius * 1.3;  // closest dolly, for nearby short hops — a moderate zoom-in that keeps surrounding context
const cameraRestFill = 0.82;   // fraction of the limiting half-FOV the whole globe fills at rest (leaves a buffer)
const cameraFitFill = 0.8;     // fraction of the view a framed hop fills (lower leaves more margin)
const cameraZoomRate = 3.5;    // how briskly the camera dollies toward its target distance
const yAxis = new THREE.Vector3(0, 1, 0);
const xAxis = new THREE.Vector3(1, 0, 0);

const scene = new THREE.Scene();
const camera = new THREE.PerspectiveCamera(75, window.innerWidth / window.innerHeight, 0.1, 1000);
const renderer = new THREE.WebGLRenderer({ antialias: true });
renderer.setSize(window.innerWidth, window.innerHeight);
document.body.appendChild(renderer.domElement);

const earth = new THREE.Mesh(
    new THREE.SphereGeometry(earthRadius, 64, 64),
    new THREE.MeshBasicMaterial({ map: new THREE.TextureLoader().load('/static/earth/earth-satellite.jpg') }),
);
// Start with Greenwich (0° longitude) facing the camera (see spinAngle below).
scene.add(earth);

camera.position.z = restCameraDistance();

let spinAngle = -Math.PI / 2; // accumulated eastward spin about the polar axis; starts with Greenwich (0° lon) facing the camera
let axisTilt = 0;             // pitch of the polar axis toward/away from the camera, framing the focus latitude (no roll)
applyEarthOrientation();      // set the starting orientation before the first frame renders
let cameraDistance = camera.position.z; // dollied toward the framed hop each frame
const travellers = [];
const arcs = new Map(); // shared hop arcs keyed by endpoints+kind, so identical simultaneous hops draw one arrow; refcounted by the flyers riding them

// Simulated clock: the whole itinerary (earliest..latest hop across all
// characters) plays in targetDurationSeconds at 1×, i.e. 1 second = N days.
let timelineStart = 0; // epoch-day of the earliest hop
let timelineEnd = 0;   // epoch-day of the latest hop
let daysPerSecond = 0; // base advance rate at 1× (0 when the span is empty)
let hopDays = [];      // sorted unique hop dates (epoch-days) for prev/next stepping
let simDay = 0;        // current simulated time (epoch-days)
let speed = 1;         // playback multiplier
let playing = true;
let forceSnap = false; // when set, the next update snaps flyers home instead of animating (jumps/loop)
let endHold = 0;       // seconds held on the final hop before the timeline loops
let lastFrame = performance.now();

const ui = {
    play: document.getElementById('playButton'),
    slower: document.getElementById('slowerButton'),
    faster: document.getElementById('fasterButton'),
    prev: document.getElementById('prevHopButton'),
    next: document.getElementById('nextHopButton'),
    speed: document.getElementById('speedReadout'),
    date: document.getElementById('dateReadout'),
};
ui.play?.addEventListener('click', togglePlay);
ui.slower?.addEventListener('click', () => setSpeed(speed / 2));
ui.faster?.addEventListener('click', () => setSpeed(speed * 2));
ui.prev?.addEventListener('click', () => stepHop(-1));
ui.next?.addEventListener('click', () => stepHop(1));

window.addEventListener('resize', onResize);

loadTravellers();
requestAnimationFrame(animate);

function animate(now) {
    requestAnimationFrame(animate);
    const dt = Math.min((now - lastFrame) / 1000, 0.1); // clamp to ignore long stalls (tab switch, etc.)
    lastFrame = now;
    const prevSimDay = simDay;
    if (playing && daysPerSecond > 0) {
        const timeScale = blueActive() ? 1 - blueTimeSlowdown : 1; // brief short hops slow the clock so they stay legible
        simDay += dt * daysPerSecond * speed * timeScale;
        if (simDay >= timelineEnd) {
            simDay = timelineEnd; // hold on the final hop so its arc can play out
            endHold += dt;
            if (endHold >= loopHoldSeconds) {
                simDay = timelineStart; // loop the timeline
                endHold = 0;
                forceSnap = true;       // don't animate the wrap-around
            }
        } else {
            endHold = 0;
        }
    }
    updateTravellers(dt, prevSimDay);
    updateReadouts();
    updateEarthOrientation(dt);
    updateCamera(dt);
    renderer.render(scene, camera);
}

// Fetch every character, drop its flyer at its first location, then start the clock.
async function loadTravellers() {
    let characters;
    try {
        const response = await fetch(`${backendUrl}/characters`);
        characters = await response.json();
    } catch (error) {
        console.error('Could not load characters from the backend.', error);
        return;
    }

    const allDays = [];
    for (const character of characters) {
        const hops = (character.hops ?? []).map((hop) => ({ ...hop, day: toDay(hop.date) }));
        if (hops.length === 0) {
            continue;
        }
        try {
            const sprite = await makeFlyer(character.name);
            const start = hops[0];
            placeOnGlobe(sprite, start.lat, start.lon);
            earth.add(sprite);
            travellers.push({
                name: character.name,
                start,
                longHops: hops.filter((hop) => hop.kind === 'long'),
                shortHops: hops.filter((hop) => hop.kind === 'short').sort((a, b) => a.day - b.day),
                sprite,
                homeLat: start.lat,
                homeLon: start.lon,
                posVec: latLongToVector3(start.lat, start.lon, 1),
                renderRadius: earthRadius + flyerLevitation,
                transition: null,
            });
            hops.forEach((hop) => allDays.push(hop.day));
        } catch (error) {
            console.warn(`Skipping '${character.name}': ${error.message}`);
        }
    }
    initClock(allDays);
}

// Derive the timeline extent and base rate from every hop date we loaded.
function initClock(allDays) {
    if (allDays.length === 0) {
        return;
    }
    timelineStart = Math.min(...allDays);
    timelineEnd = Math.max(...allDays);
    const span = timelineEnd - timelineStart;
    daysPerSecond = span > 0 ? span / targetDurationSeconds : 0;
    hopDays = [...new Set(allDays)].sort((a, b) => a - b);
    simDay = timelineStart;
}

// Advance each flyer toward its home for the current time: the last LONG hop
// reached so far, or its starting place before any long hop. A natural change
// animates along a red arc; jumps and the loop wrap snap instantly.
function updateTravellers(dt, prevSimDay) {
    const snap = forceSnap;
    forceSnap = false;
    for (const traveller of travellers) {
        const home = resolveHome(traveller, simDay);
        const moved = home.lat !== traveller.homeLat || home.lon !== traveller.homeLon;
        if (moved) {
            traveller.homeLat = home.lat;
            traveller.homeLon = home.lon;
            if (snap) {
                settle(traveller, home.lat, home.lon);
            } else {
                startTransition(traveller, [{ lat: home.lat, lon: home.lon }], 'long');
            }
        } else if (snap) {
            settle(traveller, traveller.homeLat, traveller.homeLon);
        } else if (!traveller.transition) {
            const trip = crossedShortHop(traveller, prevSimDay); // a brief tour away from home and back
            if (trip) {
                startTransition(traveller, [{ lat: trip.lat, lon: trip.lon }, ...(trip.via ?? [])], 'short');
            }
        }
        if (playing && traveller.transition) {
            advanceTransition(traveller, dt);
        }
    }
    if (snap) {
        clearAllArcs(); // a jump or loop wraps the timeline; no arc should linger across the cut
    }
    layoutFlyers();
    updateArcs(dt);
}

// The short hop, if any, whose date the clock crossed since the previous frame.
function crossedShortHop(traveller, prevSimDay) {
    return traveller.shortHops.find((hop) => hop.day > prevSimDay && hop.day <= simDay);
}

// True while any flyer is out on a short hop, so the clock slows until it's home again.
function blueActive() {
    for (const arc of arcs.values()) {
        if (!arc.fading && !arc.isLong) {
            return true;
        }
    }
    return false;
}

// Orient the globe with longitude (an eastward-biased spin about the polar axis) and
// latitude (a capped, no-roll tilt of that axis) kept independent, so it always turns
// the natural way. Active hop: centre it. At rest: pre-rotate toward the next hop (note
// #2) and lean toward the flyers' latitude band so they keep screen time (note #3).
function updateEarthOrientation(dt) {
    const focus = focusDirection();
    if (focus) {
        const ease = 1 - Math.exp(-centerSlewRate * dt);
        spinAngle += (eastwardTarget(spinAngle, focusYaw(focus)) - spinAngle) * ease;
        axisTilt += (clampTilt(focusPitch(focus)) - axisTilt) * ease;
    } else {
        const soon = upcomingFocus();
        if (soon) {
            spinAngle += (eastwardTarget(spinAngle, focusYaw(soon)) - spinAngle) * (1 - Math.exp(-lookaheadSlewRate * dt));
        } else {
            spinAngle += idleSpinRate * dt; // no hop imminent: a free, natural eastward drift
        }
        axisTilt += (favorPitch() - axisTilt) * (1 - Math.exp(-tiltEaseRate * dt));
    }
    applyEarthOrientation();
}

// Compose the orientation: spin about the polar (Y) axis, then tilt that axis about X —
// a planet with a steerable axial lean, so latitude is framed without ever rolling.
function applyEarthOrientation() {
    const spin = new THREE.Quaternion().setFromAxisAngle(yAxis, spinAngle);
    const tilt = new THREE.Quaternion().setFromAxisAngle(xAxis, axisTilt);
    earth.quaternion.copy(tilt.multiply(spin));
}

// The yaw that brings the focus longitude to face the camera, and the pitch that lifts
// its latitude to centre — the two independent halves of the old combined slerp.
function focusYaw(d) {
    return Math.atan2(-d.x, d.z);
}
function focusPitch(d) {
    return Math.atan2(d.y, Math.hypot(d.x, d.z));
}

// Choose the spin angle to ease toward, biased to Earth's natural eastward turn: go
// eastward unless a reverse is both shorter and small (<= reverseAngleCap), so minor
// re-centres nudge back while larger gaps still sweep the long way round (note #1).
function eastwardTarget(current, targetYaw) {
    const eastDist = mod2pi(targetYaw - current); // forward (eastward) sweep, in [0, 2π)
    const westDist = 2 * Math.PI - eastDist;       // the reverse sweep, in (0, 2π]
    if (eastDist <= westDist || westDist > reverseAngleCap) {
        return current + eastDist;                 // natural eastward turn (the short way, or a forced long way)
    }
    return current - westDist;                      // a small reverse to re-centre
}

function mod2pi(angle) {
    const twoPi = 2 * Math.PI;
    return ((angle % twoPi) + twoPi) % twoPi;
}

// The framing direction of the soonest upcoming hop, but only once it falls within
// lookaheadSeconds — so the globe pre-rotates to meet the flyer at its destination
// instead of lurching when the hop fires. Null when nothing is due that soon (note #2).
function upcomingFocus() {
    if (daysPerSecond <= 0) {
        return null;
    }
    const window = lookaheadSeconds * daysPerSecond * speed; // sim-days covered in the lookahead's wall-clock lead
    let best = null;
    for (const traveller of travellers) {
        const next = soonestHop(traveller);
        if (next && (!best || next.day < best.day)) {
            best = { day: next.day, posVec: traveller.posVec, hop: next };
        }
    }
    if (!best || best.day - simDay > window) {
        return null;
    }
    const dest = latLongToVector3(best.hop.lat, best.hop.lon, 1);
    const sum = best.posVec.clone().add(dest); // frame the midpoint of the imminent arc, as the active hop will
    return sum.lengthSq() < 1e-6 ? dest : sum.normalize();
}

// A flyer's earliest still-future hop, long or short (scanned, not assuming sort order).
function soonestHop(traveller) {
    let best = null;
    for (const hop of [...traveller.longHops, ...traveller.shortHops]) {
        if (hop.day > simDay && (!best || hop.day < best.day)) {
            best = hop;
        }
    }
    return best;
}

// Pitch that leans the polar axis toward the flyers' mean latitude, capped — so at rest
// the globe still favours where the flyers are rather than snapping bolt upright (note #3).
function favorPitch() {
    const sum = new THREE.Vector3();
    for (const traveller of travellers) {
        sum.add(traveller.posVec);
    }
    return sum.lengthSq() < 1e-6 ? 0 : clampTilt(focusPitch(sum.normalize()));
}

function clampTilt(pitch) {
    return THREE.MathUtils.clamp(pitch, -maxAxisTilt, maxAxisTilt);
}

// Dolly the camera so the framed hop fills the view: closer for nearby hops, back
// out toward the full-globe rest view for globe-spanning ones (never wider than
// rest). Flyers are scaled with the distance so they keep a steady on-screen size.
function updateCamera(dt) {
    const rest = restCameraDistance();
    const focus = focusDirection();
    const target = focus ? Math.min(fitCameraDistance(focusSpread(focus), framedOuterRadius()), rest) : rest;
    cameraDistance += (target - cameraDistance) * (1 - Math.exp(-cameraZoomRate * dt));
    camera.position.z = cameraDistance;
    const spriteScale = flyerScale * (cameraDistance / rest);
    for (const traveller of travellers) {
        traveller.sprite.scale.setScalar(spriteScale);
    }
}

// Distance at which the whole globe fills cameraRestFill of the limiting screen
// axis, leaving a buffer on all sides — the default view when nothing is hopping.
// Recomputed each frame so it adapts to the window's shape.
function restCameraDistance() {
    return earthRadius / Math.sin(limitingHalfFov() * cameraRestFill);
}

// Camera distance at which a cap of the given angular radius fills cameraFitFill of
// the view, accounting for the levitated arc bulge and the narrower screen axis.
function fitCameraDistance(spread, outerRadius) {
    const limiting = limitingHalfFov() * cameraFitFill;
    const distance = earthRadius * Math.cos(spread) + (outerRadius * Math.sin(spread)) / Math.tan(limiting);
    return Math.max(distance, cameraMinDistance);
}

// Outer radius of the framed hop's bulge, derived from each arc's real lift — a gently
// arcing short hop lets the camera dolly closer than a tall long-hop arc would.
function framedOuterRadius() {
    let maxLift = 0;
    for (const arc of framingArcs()) {
        maxLift = Math.max(maxLift, arcLiftFor(arc.fromVec, arc.toVec));
    }
    return earthRadius + flyerLevitation + earthRadius * maxLift;
}

// Half-angle of the narrower screen axis (vertical, or horizontal on a portrait
// window), which is what limits how much of a round globe we can frame.
function limitingHalfFov() {
    const halfFov = THREE.MathUtils.degToRad(camera.fov / 2);
    return Math.min(halfFov, Math.atan(Math.tan(halfFov) * camera.aspect));
}

// The active arcs that drive framing: prefer long (red) hops, else all active arcs.
// Each shared arc counts once however many flyers ride it.
function framingArcs() {
    const active = [...arcs.values()].filter((arc) => !arc.fading);
    const reds = active.filter((arc) => arc.isLong);
    return reds.length ? reds : active;
}

// Local-space direction the globe should face: the geometric mean of the framed
// arcs' endpoints. Null when nothing is hopping, or when the arcs roughly cancel
// out (near-antipodal — a rare case left for later).
function focusDirection() {
    const chosen = framingArcs();
    if (chosen.length === 0) {
        return null;
    }
    const sum = new THREE.Vector3();
    for (const arc of chosen) {
        sum.add(arc.fromVec).add(arc.toVec);
    }
    return sum.lengthSq() < 1e-6 ? null : sum.normalize(); // TODO: handle near-antipodal arcs
}

// Angular radius of the framed hop: the widest angle from the focus centre to any
// framed endpoint, so a single short hop frames tight and divergent arcs frame wide.
function focusSpread(focus) {
    let maxAngle = 0;
    for (const arc of framingArcs()) {
        for (const endpoint of [arc.fromVec, arc.toVec]) {
            maxAngle = Math.max(maxAngle, Math.acos(THREE.MathUtils.clamp(focus.dot(endpoint), -1, 1)));
        }
    }
    return maxAngle;
}

function settle(traveller, lat, lon) {
    endTransition(traveller);
    traveller.posVec = latLongToVector3(lat, lon, 1);
    traveller.renderRadius = earthRadius + flyerLevitation;
}

function resolveHome(traveller, day) {
    let home = traveller.start;
    for (const hop of traveller.longHops) {
        if (hop.day > day) {
            break; // longHops are sorted, so nothing later qualifies
        }
        home = hop;
    }
    return home;
}

// Start a flyer travelling a tour. A long hop is a one-way trip to a new home. A short hop is a
// blue tour: it leaves home, visits each stop in order (pausing at each), and returns home — so a
// lone trip is just home → place → home, while connected/nested travels string several stops into
// one outing. Each leg becomes a fresh arc, acquired as the flyer reaches it and held until the
// tour ends; identical hops at the same time (in either direction) share one arc.
function startTransition(traveller, stops, kind) {
    endTransition(traveller);
    const fromVec = traveller.posVec.clone();
    const points = [fromVec, ...stops.map((s) => latLongToVector3(s.lat, s.lon, 1))];
    if (kind === 'short') {
        points.push(fromVec.clone()); // a tour ends back home
    }
    const lifts = [];
    for (let i = 0; i < points.length - 1; i++) {
        lifts.push(arcLiftFor(points[i], points[i + 1]));
    }
    traveller.transition = {
        points,
        lifts,
        kind,
        legIndex: 0,
        phase: 'fly',  // fly → (pause → fly)* → done
        elapsed: 0,
        arcKeys: [],
    };
    enterLeg(traveller);
}

// Draw (or rejoin) the arc for the leg the flyer is about to fly, holding it until the tour ends.
function enterLeg(traveller) {
    const t = traveller.transition;
    const from = t.points[t.legIndex];
    const to = t.points[t.legIndex + 1];
    t.arcKeys.push(acquireArc(from, to, t.lifts[t.legIndex], t.kind));
}

// Lift scales with how far apart the two places are: short hops arc gently,
// long hops rise high. Normalized so a quarter-globe hop reaches the full arcLift,
// with a floor so tiny hops still read as an arc and a cap for half-globe+ hops.
function arcLiftFor(fromVec, toVec) {
    const theta = Math.acos(THREE.MathUtils.clamp(fromVec.dot(toVec), -1, 1));
    return arcLift * THREE.MathUtils.clamp(theta / (Math.PI / 2), shortHopLiftFloor, 1);
}

// Short hops widen their arrow so the tiny arc still reads; the boost tapers to 1 by a
// quarter-globe, matching the lift normalization, so long hops keep their slim arrow.
function arrowScaleFor(fromVec, toVec) {
    const theta = Math.acos(THREE.MathUtils.clamp(fromVec.dot(toVec), -1, 1));
    const n = THREE.MathUtils.clamp(theta / (Math.PI / 2), 0, 1);
    return THREE.MathUtils.lerp(arcShortHopWidthScale, 1, n);
}

// Fly the flyer along the current leg; on arrival it either pauses (more stops to
// come) or, at the final point, settles. Long hops have a single leg and no pause.
function advanceTransition(traveller, dt) {
    const t = traveller.transition;
    if (t.phase === 'fly') {
        const legDuration = t.kind === 'long' ? hopDuration : shortHopDuration;
        t.elapsed += dt;
        const raw = Math.min(t.elapsed / legDuration, 1);
        const progress = easeInOut(raw);
        const from = t.points[t.legIndex];
        const to = t.points[t.legIndex + 1];
        traveller.posVec = slerpVec(from, to, progress);
        traveller.renderRadius = earthRadius + flyerLevitation + earthRadius * t.lifts[t.legIndex] * Math.sin(Math.PI * progress);
        if (raw >= 1) {
            t.elapsed = 0;
            t.legIndex++;
            if (t.legIndex >= t.points.length - 1) {
                finishTransition(traveller);
            } else {
                t.phase = 'pause';
            }
        }
    } else if (t.phase === 'pause') {
        t.elapsed += dt;
        if (t.elapsed >= shortHopStay) {
            t.elapsed = 0;
            t.phase = 'fly';
            enterLeg(traveller);
        }
    }
}

// The flyer has finished its tour: settle it at the final point (a long hop's new
// home, or back home for a short tour) and release every arc it was riding.
function finishTransition(traveller) {
    const t = traveller.transition;
    traveller.posVec = t.points[t.points.length - 1].clone();
    traveller.renderRadius = earthRadius + flyerLevitation;
    t.arcKeys.forEach(releaseArc);
    traveller.transition = null;
}

// Drop a flyer's in-progress transition (interrupted by a new hop or a snap),
// releasing its hold on every arc it was riding.
function endTransition(traveller) {
    if (!traveller.transition) {
        return;
    }
    traveller.transition.arcKeys.forEach(releaseArc);
    traveller.transition = null;
}

// A raised great-circle arc from one place to another, drawn as a flat, wide
// ribbon lying roughly tangent to the globe, capped by a broad flat arrowhead at
// the destination — so it reads as a clear arrow head-on rather than a round tube.
function buildArcGroup(fromVec, toVec, lift, color) {
    const material = new THREE.MeshBasicMaterial({ color, transparent: true, side: THREE.DoubleSide });
    const group = new THREE.Group();
    const { shaft, head } = arcArrowGeometry(fromVec, toVec, lift);
    group.add(new THREE.Mesh(shaft, material));
    group.add(new THREE.Mesh(head, material));
    earth.add(group);
    return group;
}

// Build the flat shaft ribbon and flat arrowhead triangle for one arc. The
// arrowhead sits a fixed distance back from the tip (clamped on very short hops),
// and the shaft stops exactly where the head begins so the two never overlap.
function arcArrowGeometry(fromVec, toVec, lift) {
    const widthScale = arrowScaleFor(fromVec, toVec);
    const points = [];
    for (let i = 0; i <= arcSegments; i++) {
        points.push(arcPoint(fromVec, toVec, i / arcSegments, lift));
    }
    const cumulative = [0];
    for (let i = 1; i < points.length; i++) {
        cumulative.push(cumulative[i - 1] + points[i].distanceTo(points[i - 1]));
    }
    const total = cumulative[cumulative.length - 1];
    const headLength = Math.min(arcHeadLength * widthScale, total * 0.6);
    const baseLength = total - headLength;

    const shaftPoints = points.filter((_, i) => cumulative[i] < baseLength);
    const baseCenter = pointAtLength(points, cumulative, baseLength);
    shaftPoints.push(baseCenter);
    const shaft = ribbonGeometry(shaftPoints, arcShaftHalfWidth * widthScale);

    const tip = points[points.length - 1];
    const side = tangentSide(tip.clone().sub(baseCenter), baseCenter).multiplyScalar(arcHeadHalfWidth * widthScale);
    const baseLeft = baseCenter.clone().add(side);
    const baseRight = baseCenter.clone().sub(side);
    const head = new THREE.BufferGeometry();
    head.setAttribute('position', new THREE.Float32BufferAttribute([
        tip.x, tip.y, tip.z,
        baseLeft.x, baseLeft.y, baseLeft.z,
        baseRight.x, baseRight.y, baseRight.z,
    ], 3));
    head.setIndex([0, 1, 2]);
    return { shaft, head };
}

// A flat ribbon centred on the given points: at each point we step sideways along
// the in-surface perpendicular, so the strip lies tangent to the globe (facing
// outward) rather than bulging like a tube.
function ribbonGeometry(centre, halfWidth) {
    const positions = [];
    for (let i = 0; i < centre.length; i++) {
        const prev = centre[Math.max(0, i - 1)];
        const next = centre[Math.min(centre.length - 1, i + 1)];
        const side = tangentSide(next.clone().sub(prev), centre[i]).multiplyScalar(halfWidth);
        const left = centre[i].clone().add(side);
        const right = centre[i].clone().sub(side);
        positions.push(left.x, left.y, left.z, right.x, right.y, right.z);
    }
    const index = [];
    for (let i = 0; i < centre.length - 1; i++) {
        const a = i * 2;
        index.push(a, a + 1, a + 2, a + 1, a + 3, a + 2); // two triangles per ribbon quad
    }
    const geometry = new THREE.BufferGeometry();
    geometry.setAttribute('position', new THREE.Float32BufferAttribute(positions, 3));
    geometry.setIndex(index);
    return geometry;
}

// Unit vector perpendicular to the travel direction and lying in the globe's
// tangent plane at `at` — the direction to fan the ribbon's width along.
function tangentSide(tangent, at) {
    return new THREE.Vector3().crossVectors(tangent.normalize(), at.clone().normalize()).normalize();
}

// Point a given arc-length along a sampled polyline (clamped to its ends).
function pointAtLength(points, cumulative, target) {
    const total = cumulative[cumulative.length - 1];
    if (target <= 0) {
        return points[0].clone();
    }
    if (target >= total) {
        return points[points.length - 1].clone();
    }
    let i = 1;
    while (i < cumulative.length && cumulative[i] < target) {
        i++;
    }
    const span = cumulative[i] - cumulative[i - 1];
    const fraction = span > 0 ? (target - cumulative[i - 1]) / span : 0;
    return points[i - 1].clone().lerp(points[i], fraction);
}

// --- Shared hop arcs ---------------------------------------------------------
// Identical hops taken at the same time share one arc, so two flyers never stack
// arrows that z-fight. Each arc is refcounted by the flyers riding it and fades
// once the last one lets go.

function acquireArc(fromVec, toVec, lift, kind) {
    const key = arcKeyFor(fromVec, toVec, kind);
    // A leg flown in reverse (a tour's return home, or a sub-trip back to its base) rejoins the
    // arc already drawn the other way instead of stacking an opposing arrowhead over it.
    const reverseKey = arcKeyFor(toVec, fromVec, kind);
    const usedKey = arcs.has(key) ? key : arcs.has(reverseKey) ? reverseKey : key;
    let arc = arcs.get(usedKey);
    if (!arc) {
        const color = kind === 'long' ? longHopColor : shortHopColor;
        arc = {
            group: buildArcGroup(fromVec, toVec, lift, color),
            fromVec: fromVec.clone(),
            toVec: toVec.clone(),
            isLong: kind === 'long',
            refs: 0,
            fading: false,
            fadeElapsed: 0,
        };
        arcs.set(usedKey, arc);
    }
    arc.refs++;
    arc.fading = false; // a fresh rider revives an arc that had begun to fade
    arc.fadeElapsed = 0;
    setGroupOpacity(arc.group, 1);
    return usedKey;
}

function releaseArc(key) {
    const arc = arcs.get(key);
    if (!arc) {
        return;
    }
    arc.refs = Math.max(0, arc.refs - 1);
    if (arc.refs === 0) {
        arc.fading = true; // the last rider left; start fading out
    }
}

// Fade and dispose any arc no flyer is riding any more.
function updateArcs(dt) {
    for (const [key, arc] of arcs) {
        if (!arc.fading) {
            continue;
        }
        arc.fadeElapsed += dt;
        setGroupOpacity(arc.group, Math.max(0, 1 - arc.fadeElapsed / arcFadeSeconds));
        if (arc.fadeElapsed >= arcFadeSeconds) {
            disposeArc(arc);
            arcs.delete(key);
        }
    }
}

function clearAllArcs() {
    for (const arc of arcs.values()) {
        disposeArc(arc);
    }
    arcs.clear();
}

function disposeArc(arc) {
    earth.remove(arc.group);
    arc.group.traverse((object) => {
        object.geometry?.dispose();
        object.material?.dispose();
    });
}

function arcKeyFor(fromVec, toVec, kind) {
    return `${vecKey(fromVec)}>${vecKey(toVec)}:${kind}`;
}

function vecKey(v) {
    return `${v.x.toFixed(4)},${v.y.toFixed(4)},${v.z.toFixed(4)}`;
}

// --- Flyer layout ------------------------------------------------------------
// Position every flyer for the frame. Flyers sharing a spot (resting in the same
// place, or riding the same arc) are fanned on a small ring so each stays visible
// while the cluster as a whole sits exactly where a lone flyer would.

function layoutFlyers() {
    const clusters = new Map();
    for (const traveller of travellers) {
        const key = posKey(traveller.posVec, traveller.renderRadius);
        const cluster = clusters.get(key);
        if (cluster) {
            cluster.push(traveller);
        } else {
            clusters.set(key, [traveller]);
        }
    }
    for (const members of clusters.values()) {
        const center = members[0].posVec.clone().multiplyScalar(members[0].renderRadius);
        if (members.length === 1) {
            members[0].sprite.position.copy(center);
            continue;
        }
        members.sort((a, b) => (a.name < b.name ? -1 : 1)); // stable seats so flyers don't swap places each frame
        const [u, v] = tangentBasis(members[0].posVec);
        for (let i = 0; i < members.length; i++) {
            const angle = (2 * Math.PI * i) / members.length;
            const offset = u.clone().multiplyScalar(Math.cos(angle) * flyerClusterRadius)
                .add(v.clone().multiplyScalar(Math.sin(angle) * flyerClusterRadius));
            members[i].sprite.position.copy(center.clone().add(offset));
        }
    }
}

// Two orthonormal vectors spanning the tangent plane at a point on the sphere.
function tangentBasis(dir) {
    const reference = Math.abs(dir.y) < 0.99 ? yAxis : xAxis;
    const u = new THREE.Vector3().crossVectors(reference, dir).normalize();
    const v = new THREE.Vector3().crossVectors(dir, u).normalize();
    return [u, v];
}

// Quantized world position, so flyers at (nearly) the same point share a cluster.
function posKey(dir, radius) {
    return `${(dir.x * radius).toFixed(2)},${(dir.y * radius).toFixed(2)},${(dir.z * radius).toFixed(2)}`;
}

function arcPoint(fromVec, toVec, t, lift) {
    const radius = earthRadius + flyerLevitation - arcClearance + earthRadius * lift * Math.sin(Math.PI * t);
    return slerpVec(fromVec, toVec, t).multiplyScalar(radius);
}

// Spherical-linear interpolation between two unit vectors.
function slerpVec(a, b, t) {
    const theta = Math.acos(THREE.MathUtils.clamp(a.dot(b), -1, 1));
    if (theta < 1e-6) {
        return a.clone();
    }
    const sinTheta = Math.sin(theta);
    return a.clone().multiplyScalar(Math.sin((1 - t) * theta) / sinTheta)
        .add(b.clone().multiplyScalar(Math.sin(t * theta) / sinTheta));
}

function easeInOut(t) {
    return t < 0.5 ? 2 * t * t : 1 - ((-2 * t + 2) ** 2) / 2;
}

function setGroupOpacity(group, opacity) {
    group.traverse((object) => {
        if (object.material) {
            object.material.opacity = opacity;
        }
    });
}

function updateReadouts() {
    if (ui.date) {
        ui.date.textContent = hopDays.length ? formatDay(simDay) : '—';
    }
    if (ui.speed) {
        ui.speed.textContent = formatSpeed(speed);
    }
}

function togglePlay() {
    playing = !playing;
    if (ui.play) {
        ui.play.textContent = playing ? 'Pause' : 'Play';
    }
}

function setSpeed(value) {
    speed = Math.min(16, Math.max(0.125, value));
}

// Jump the clock to the previous/next hop date across all characters (wrapping).
function stepHop(direction) {
    if (hopDays.length === 0) {
        return;
    }
    const epsilon = 1e-6;
    if (direction > 0) {
        simDay = hopDays.find((day) => day > simDay + epsilon) ?? hopDays[0];
    } else {
        const earlier = hopDays.filter((day) => day < simDay - epsilon);
        simDay = earlier.length ? earlier[earlier.length - 1] : hopDays[hopDays.length - 1];
    }
    forceSnap = true; // a manual jump should land instantly, not animate
}

function toDay(dateString) {
    return Date.parse(dateString) / msPerDay; // yyyy-MM-dd parses as UTC midnight
}

function formatDay(day) {
    return new Date(Math.round(day) * msPerDay).toISOString().slice(0, 10);
}

function formatSpeed(value) {
    return value >= 1 ? `${value}×` : `1/${Math.round(1 / value)}×`;
}

async function makeFlyer(name) {
    const texture = await loadFlyerTexture(name);
    const sprite = new THREE.Sprite(new THREE.SpriteMaterial({ map: texture, transparent: true }));
    sprite.scale.setScalar(flyerScale);
    return sprite;
}

// Try the supported extensions in order; resolve with the first flyer that loads.
function loadFlyerTexture(name) {
    return new Promise((resolve, reject) => {
        let index = 0;
        const tryNext = () => {
            if (index >= flyerExtensions.length) {
                reject(new Error(`no flyer image at /static/flyers/${name}.*`));
                return;
            }
            const image = new Image();
            image.onload = () => resolve(rasterizeToTexture(image));
            image.onerror = tryNext;
            image.src = `/static/flyers/${name}.${flyerExtensions[index++]}`;
        };
        tryNext();
    });
}

// Rasterize onto a fixed-size canvas so SVG flyers (which can report zero
// intrinsic size and fail a direct WebGL upload) render reliably.
function rasterizeToTexture(image) {
    const canvas = document.createElement('canvas');
    canvas.width = canvas.height = flyerTextureSize;
    canvas.getContext('2d').drawImage(image, 0, 0, flyerTextureSize, flyerTextureSize);
    const texture = new THREE.CanvasTexture(canvas);
    texture.colorSpace = THREE.SRGBColorSpace;
    return texture;
}

function placeOnGlobe(object, lat, lon) {
    object.position.copy(latLongToVector3(lat, lon, earthRadius + flyerLevitation));
}

// Matches Three.js SphereGeometry's default UVs for a standard equirectangular
// texture: 0° longitude at +X, east toward -Z, north pole at +Y. The leading
// minus on x is what the previous version was missing (it mirrored east/west).
function latLongToVector3(lat, lon, radius) {
    const polar = ((90 - lat) / 180) * Math.PI;
    const azimuth = ((lon + 180) / 180) * Math.PI;
    return new THREE.Vector3(
        -radius * Math.sin(polar) * Math.cos(azimuth),
        radius * Math.cos(polar),
        radius * Math.sin(polar) * Math.sin(azimuth),
    );
}

function onResize() {
    camera.aspect = window.innerWidth / window.innerHeight;
    camera.updateProjectionMatrix();
    renderer.setSize(window.innerWidth, window.innerHeight);
}
