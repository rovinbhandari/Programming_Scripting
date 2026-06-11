import * as THREE from 'three';

const backendPort = 8080; // TODO: obtain from env variable or config
const earthRadius = 6;
const flyerExtensions = ['svg', 'png', 'jpg', 'jpeg', 'webp'];
const flyerLevitation = 0.6; // lift sprites just clear of the surface so they aren't clipped
const flyerTextureSize = 256; // rasterize flyers to this square size for reliable WebGL upload

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

const refreshButton = document.getElementById('refreshButton');
refreshButton?.addEventListener('click', refreshSpin);
window.addEventListener('resize', onResize);

loadTravellers();
animate();

function animate() {
    requestAnimationFrame(animate);
    earth.rotation.y += spinSpeed;
    renderer.render(scene, camera);
}

// Fetch each character and drop its flyer onto the globe at its first hop.
async function loadTravellers() {
    let characters;
    try {
        const response = await fetch(`http://localhost:${backendPort}/characters`);
        characters = await response.json();
    } catch (error) {
        console.error('Could not load characters from the backend.', error);
        return;
    }

    for (const character of characters) {
        const hops = character.hops ?? [];
        if (hops.length === 0) {
            continue;
        }
        try {
            const sprite = await makeFlyer(character.name);
            const start = hops[0];
            placeOnGlobe(sprite, start.lat, start.lon);
            earth.add(sprite);
            travellers.push({ name: character.name, hops, sprite });
        } catch (error) {
            console.warn(`Skipping '${character.name}': ${error.message}`);
        }
    }
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
