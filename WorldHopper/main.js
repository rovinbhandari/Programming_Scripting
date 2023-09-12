import * as THREE from 'three';
let camera, scene, renderer, mesh;

init();
animate();

function init() {

    camera = new THREE.PerspectiveCamera( 70, window.innerWidth / window.innerHeight, 0.01, 10 );
    camera.position.z = 1;

    scene = new THREE.Scene();

    const geometry = new THREE.BoxGeometry( 0.2, 0.2, 0.2 ).toNonIndexed();
		
		// vertexColors must be true so vertex colors can be used in the shader
		
    const material = new THREE.MeshBasicMaterial( { vertexColors: true } ); 
		
		// generate color data for each vertex
		
		const positionAttribute = geometry.getAttribute( 'position' );
		
		const colors = [];
		const color = new THREE.Color();
		
		for ( let i = 0; i < positionAttribute.count; i += 3 ) {
		
			color.set( Math.random() * 0xffffff );
			
			// define the same color for each vertex of a triangle
			
			colors.push( color.r, color.g, color.b );
			colors.push( color.r, color.g, color.b );
			colors.push( color.r, color.g, color.b );
		
		}
		
		// define the new attribute
		
		geometry.setAttribute( 'color', new THREE.Float32BufferAttribute( colors, 3 ) );

    mesh = new THREE.Mesh( geometry, material );
    scene.add( mesh );

    renderer = new THREE.WebGLRenderer( { antialias: true } );
    renderer.setSize( window.innerWidth, window.innerHeight );
    document.body.appendChild( renderer.domElement );

}

function animate() {

    requestAnimationFrame( animate );

    mesh.rotation.x += 0.01;
    mesh.rotation.y += 0.02;

    renderer.render( scene, camera );

}