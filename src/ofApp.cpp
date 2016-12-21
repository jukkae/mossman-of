#include "ofApp.h"
#include "scenes/boids/boidsScene.hpp"
#include "scenes/gol/golScene.hpp"

Scene* s1;
Scene* s2;
Scene* activeScene;
//--------------------------------------------------------------
void ofApp::setup(){
	ofBackground(255, 255, 255);
	s1 = new BoidsScene();
	s2 = new GolScene();
	activeScene = s1;

	int bufferSize = 256;
	left.assign(bufferSize, 0.0);
	right.assign(bufferSize, 0.0);
	smoothedVol = 0.0;
	scaledVol = 0.0;

	soundStream.setup(this, 0, 2, 44100, bufferSize, 4);
}

//--------------------------------------------------------------
void ofApp::update(){
	activeScene->update(ofGetLastFrameTime());

	//lets scale the vol up to a 0-1 range
	scaledVol = ofMap(smoothedVol, 0.0, 0.17, 0.0, 1.0, true);

	//lets record the volume into an array
	volHistory.push_back( scaledVol );

	//if we are bigger the the size we want to record - lets drop the oldest value
	if( volHistory.size() >= 400 ) {
		volHistory.erase(volHistory.begin(), volHistory.begin()+1);
	}
	if(scaledVol > 0.5) {
		activeScene->keyPress('r');
	}
}

//--------------------------------------------------------------
void ofApp::draw(){
	activeScene->draw();
}

void ofApp::audioIn(float* input, int bufferSize, int nChannels) {
	float curVol = 0.0;

	// samples are "interleaved"
	int numCounted = 0;

	//lets go through each sample and calculate the root mean square which is a rough way to calculate volume
	for (int i = 0; i < bufferSize; i++){
	left[i]         = input[i*2]*0.5;
		right[i]        = input[i*2+1]*0.5;

	curVol += left[i] * left[i];
	curVol += right[i] * right[i];
	numCounted+=2;
	}

	//this is how we get the mean of rms :)
	curVol /= (float)numCounted;

	// this is how we get the root of rms :)
	curVol = sqrt( curVol );

	smoothedVol *= 0.93;
	smoothedVol += 0.07 * curVol;
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
	if (key == '1') {
		activeScene = s1;
	}
	if (key == '2') {
		activeScene = s2;
	}
	else {
		activeScene->keyPress(key);
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
