#pragma once

#include "ofMain.h"

#include <vector>

class ofApp : public ofBaseApp{

	public:
		void setup();
		void update();
		void draw();

		void keyPressed(int key);
		void keyReleased(int key);
		void mouseMoved(int x, int y );
		void mouseDragged(int x, int y, int button);
		void mousePressed(int x, int y, int button);
		void mouseReleased(int x, int y, int button);
		void mouseEntered(int x, int y);
		void mouseExited(int x, int y);
		void windowResized(int w, int h);
		void dragEvent(ofDragInfo dragInfo);
		void gotMessage(ofMessage msg);
		
		void audioIn(float* input, int bufferSize, int nChannels);

	private:
		void updateFps(float dt);

		ofSoundStream soundStream;

		std::vector<float> left;
		std::vector<float> right;
		std::vector<float> volHistory;

		float smoothedVol;
		float scaledVol;

		float fps = 0;
		bool drawFpsLabel = false;
};
