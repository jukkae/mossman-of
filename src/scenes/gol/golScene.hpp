#ifndef GOLSCENE_H
#define GOLSCENE_H

#include "ofMain.h"
#include "scene.hpp"
#include "ruleSet.hpp"
#include "golWorld.hpp"

class GolScene : public Scene {
public:
	int colCount = 1024; // default size of ofApp window
	int rowCount = 768;
	GolScene(): world(colCount, rowCount) {
	}
	void draw();
	void update(float dt);
	void activate();
	void deactivate();
	void keyPress(int key);
private:
	GolWorld world;
	bool active = true;
	std::vector<std::vector<bool>> bomb = { { false, true, false }, { true, true, true }, { true, false, false }};
	void insertShape(std::vector<std::vector<bool>> shape, int x, int y);
	void randomizeRules();
};

#endif /* GOLSCENE_H */
