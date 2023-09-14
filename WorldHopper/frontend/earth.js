import * as THREE from 'three';

const backendPort = 21248; // TODO: obtain from env variable or config
const scene = new THREE.Scene();
const camera = new THREE.PerspectiveCamera(75, window.innerWidth / innerHeight, 0.1, 1000);
const renderer = new THREE.WebGLRenderer();

renderer.setSize(window.innerWidth, window.innerHeight);
document.body.appendChild(renderer.domElement);

const geometry = new THREE.SphereGeometry(5, 32, 32);
const material = new THREE.MeshBasicMaterial({ map: new THREE.TextureLoader().load('/static/earth/earth-satellite.jpg') });
const earth = new THREE.Mesh(geometry, material);

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

// TODO: next thing to figure out is how to get a point on the earth's surface using coordinates.