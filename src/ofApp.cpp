#include "ofApp.h"
#include "scenes/boids/boidsScene.hpp"
#include "scenes/gol/golScene.hpp"

float t;
Scene* s1;
Scene* s2;
Scene* activeScene;
//--------------------------------------------------------------
void ofApp::setup(){
	t = 0.0f;
	ofBackground(255, 255, 255);
	s1 = new BoidsScene();
	s2 = new GolScene();
	activeScene = s1;
}

//--------------------------------------------------------------
void ofApp::update(){
	t += 0.03f;
	activeScene->update();
}

//--------------------------------------------------------------
void ofApp::draw(){
	activeScene->draw();
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
	if (key == 's') {
		activeScene = s1;
	}
	if (key == 't') {
		activeScene = s2;
	}
}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseEntered(int x, int y){

}

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y){

}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){ 

}
