import * as THREE from 'three';

const backendPort = 8080; // TODO: obtain from env variable or config
const earthRadius = 6;
const flyerExtensions = ['svg', 'png', 'jpg', 'jpeg', 'webp'];
const flyerLevitation = 0.6; // lift sprites just clear of the surface so they aren't clipped
const flyerTextureSize = 256; // rasterize flyers to this square size for reliable WebGL upload
const targetDurationSeconds = 200; // wall-clock seconds to replay the whole timeline at 1× (Phase 4 externalizes this)
const msPerDay = 86_400_000;

const scene = new THREE.Scene();
const camera = new THREE.PerspectiveCamera(75, window.innerWidth / window.innerHeight, 0.1, 1000);
const renderer = new THREE.WebGLRenderer({ antialias: true });
renderer.setSize(window.innerWidth, window.innerHeight);
document.body.appendChild(renderer.domElement);

const earth = new THREE.Mesh(
    new THREE.SphereGeometry(earthRadius, 64, 64),
    new THREE.MeshBasicMaterial({ map: new THREE.TextureLoader().load('/static/earth/earth-satellite.jpg') }),
);
// Start with Greenwich (0° longitude) facing the camera.
earth.rotation.y = -Math.PI / 2;
scene.add(earth);

camera.position.z = 15;

let spinSpeed = 0;
const travellers = [];

// Simulated clock: the whole itinerary (earliest..latest hop across all
// characters) plays in targetDurationSeconds at 1×, i.e. 1 second = N days.
let timelineStart = 0; // epoch-day of the earliest hop
let timelineEnd = 0;   // epoch-day of the latest hop
let daysPerSecond = 0; // base advance rate at 1× (0 when the span is empty)
let hopDays = [];      // sorted unique hop dates (epoch-days) for prev/next stepping
let simDay = 0;        // current simulated time (epoch-days)
let speed = 1;         // playback multiplier
let playing = true;
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

document.getElementById('refreshButton')?.addEventListener('click', refreshSpin);
window.addEventListener('resize', onResize);

loadTravellers();
requestAnimationFrame(animate);

function animate(now) {
    requestAnimationFrame(animate);
    const dt = Math.min((now - lastFrame) / 1000, 0.1); // clamp to ignore long stalls (tab switch, etc.)
    lastFrame = now;
    if (playing && daysPerSecond > 0) {
        simDay += dt * daysPerSecond * speed;
        if (simDay > timelineEnd) {
            simDay = timelineStart; // loop the timeline
        }
    }
    updateTravellers();
    updateReadouts();
    earth.rotation.y += spinSpeed;
    renderer.render(scene, camera);
}

// Fetch every character, drop its flyer at its first location, then start the clock.
async function loadTravellers() {
    let characters;
    try {
        const response = await fetch(`http://localhost:${backendPort}/characters`);
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
                sprite,
                lat: start.lat,
                lon: start.lon,
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

// Move each flyer to its home for the current time: the last LONG hop reached so
// far, or its starting place before any long hop. (Short hops arrive in Step 4.)
function updateTravellers() {
    for (const traveller of travellers) {
        const home = resolveHome(traveller, simDay);
        if (home.lat !== traveller.lat || home.lon !== traveller.lon) {
            placeOnGlobe(traveller.sprite, home.lat, home.lon);
            traveller.lat = home.lat;
            traveller.lon = home.lon;
        }
    }
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
    sprite.scale.setScalar(earthRadius * 0.18);
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

// The /cameraangles endpoint hands back a small random spin speed (kept from the original demo).
async function refreshSpin() {
    try {
        const response = await fetch(`http://localhost:${backendPort}/cameraangles`);
        const angles = await response.json();
        spinSpeed = angles[0].y;
    } catch (error) {
        console.error('Could not refresh the spin speed.', error);
    }
}

function onResize() {
    camera.aspect = window.innerWidth / window.innerHeight;
    camera.updateProjectionMatrix();
    renderer.setSize(window.innerWidth, window.innerHeight);
}
