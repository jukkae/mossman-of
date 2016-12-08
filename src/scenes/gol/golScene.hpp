#include "ofMain.h"
#include "scene.hpp"

class GolScene : public Scene {
public:
	GolScene();
	void draw();
	void update();
	void activate();
	void deactivate();
	void keyPress(int key);
};
