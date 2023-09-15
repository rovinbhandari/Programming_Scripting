import * as THREE from 'three';

const backendPort = 21248; // TODO: obtain from env variable or config

const earthRadius = 6;

const scene = new THREE.Scene();
const camera = new THREE.PerspectiveCamera(75, window.innerWidth / innerHeight, 0.1, 1000);
const renderer = new THREE.WebGLRenderer();

renderer.setSize(window.innerWidth, window.innerHeight);
document.body.appendChild(renderer.domElement);

const geometry = new THREE.SphereGeometry(earthRadius, 32, 32);
const material = new THREE.MeshBasicMaterial({ map: new THREE.TextureLoader().load('/static/earth/earth-satellite.jpg') });
const earth = new THREE.Mesh(geometry, material);

const lat = 60;
const lon = 10;
const pointLevitation = 0;


const sphericalCoords = {
    radius: earthRadius, // Radius of the sphere
    polar: Math.PI / 4,  // Latitude in radians (example: 45 degrees)
    azimuthal: Math.PI   // Longitude in radians (example: 180 degrees)
};

const cartesianCoords = sphericalToCartesian(
    sphericalCoords.radius,
    sphericalCoords.polar,
    sphericalCoords.azimuthal
);

const smallSphereGeometry = new THREE.SphereGeometry(earthRadius/50.0, 32, 32);
const smallSphereMaterial = new THREE.MeshBasicMaterial({ color: 0xff0000 });
const smallSphere = new THREE.Mesh(smallSphereGeometry, smallSphereMaterial);

// Position the small sphere on top of the big sphere
smallSphere.position.set(0, earthRadius, 0); // Adjust the position as needed

earth.add(smallSphere);

scene.add(earth);

camera.position.z = 15;

var cameraAngleDeltas = {x: 0.005, y: 0.005, z: 0.005};
const refreshButton = document.getElementById('refreshButton');
refreshButton.addEventListener('click', async function() { await RefreshAngles() });

animate();

function animate() {
    requestAnimationFrame(animate);

    // Add any animations or updates here
	earth.rotation.x += cameraAngleDeltas.x;
	earth.rotation.y += cameraAngleDeltas.y;
    earth.rotation.z += cameraAngleDeltas.z;

    renderer.render(scene, camera);
}

async function RefreshAngles() {
    // TODO:
    // To avoid CORS issues, instead of modifying the backend,
    // this could be tried as well:
    // https://javascript.info/fetch-crossorigin#using-scripts
    const response = await fetch(
        `http://localhost:${backendPort}/cameraangles`,
        {
            method: 'GET',
            headers:
            { 
                'Content-Type': 'application/json'
            }
        });
    const responseJson = await response.json(); //extract JSON from the http response
    cameraAngleDeltas.x = responseJson[0].x;
    cameraAngleDeltas.y = responseJson[0].y;
    cameraAngleDeltas.z = responseJson[0].z;
    console.log(cameraAngleDeltas);
}

function sphericalToCartesian(radius, polar, azimuthal) {
    const x = radius * Math.sin(polar) * Math.cos(azimuthal);
    const y = radius * Math.sin(polar) * Math.sin(azimuthal);
    const z = radius * Math.cos(polar);
    return new THREE.Vector3(x, y, z);
}

// TODO: next thing to figure out is how to get a point on the earth's surface using coordinates.