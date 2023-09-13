import * as THREE from 'three';

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

animate();

function animate() {
    requestAnimationFrame(animate);

    // Add any animations or updates here
	earth.rotation.x += 0.005;
	earth.rotation.y += 0.005;
    earth.rotation.z += 0.005;

    renderer.render(scene, camera);
}
