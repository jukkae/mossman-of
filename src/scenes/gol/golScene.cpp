#include "golScene.hpp"
#include "goodRuleSets.hpp"

void GolScene::draw() {
	auto cols = world.colCount();
	auto rows = world.rowCount();
	float cellWidth = (float) ofGetWidth() / (float) cols;
	float cellHeight= (float) ofGetHeight() / (float) rows;
	for(int i = 0; i < cols; i++) {
		for(int j = 0; j < rows; j++) {
			float screenX = i * cellWidth;
			float screenY = j * cellHeight;
			if(world.isAlive(i, j)) ofDrawRectangle(screenX, screenY, cellWidth, cellHeight);
		}
	}
}

void GolScene::update(float dt) {
	if(active) world.step();
}

void GolScene::activate() {

}

void GolScene::deactivate() {

}

void GolScene::keyPress(int key) {
	if(key == 'r') world.randomizeState();
	if(key == 'n') randomizeRules();
	if(key == 'c') world.clear();
	if(key == 'b') world.insertShape(bomb, rand() % world.rowCount(), rand() % world.colCount());
	if(key == 'p') active = !active;
	if(key == OF_KEY_UP) {
		colCount++;
		rowCount++;
		world.resize(colCount, rowCount);
	}
	if(key == OF_KEY_DOWN) {
		colCount--;
		rowCount--;
		world.resize(colCount, rowCount);
	}
}

void GolScene::randomizeRules() {
	world.setRules(GoodRuleSets::getRandomRuleSet());
}
