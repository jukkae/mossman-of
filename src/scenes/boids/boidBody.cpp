#include "boidBody.hpp"

void BoidBody::update() {
	velocity += acceleration;
	if(velocity.length() > rules.maxSpeed) velocity.scale(rules.maxSpeed);
	location += velocity;
	acceleration *= rules.deceleration;
	checkBounds();
}

void BoidBody::checkBounds() {
	switch(rules.bounds) {
		case Rules::Boundaries::Wrap :
			if(location.x > ofGetWidth() + rules.radius)	location.x = -rules.radius;
			if(location.x < -rules.radius)			location.x = ofGetWidth() + rules.radius;
			if(location.y > ofGetHeight() + rules.radius)	location.y = -rules.radius;
			if(location.y < -rules.radius)			location.y = ofGetHeight() + rules.radius;
			break;
		case Rules::Boundaries::Bounce :
			if(location.x > ofGetWidth() - rules.radius) {
				velocity.x = -velocity.x;
				location.x -= 2 * (location.x - (ofGetWidth() - rules.radius)); // bounce back
			}
			if(location.x < rules.radius) {
				velocity.x = -velocity.x;
				location.x -= 2 * (location.x - rules.radius); // bounce back
			}
			if(location.y > ofGetHeight() - rules.radius) {
				velocity.y = -velocity.y;
				location.y -= 2 * (location.y - (ofGetHeight() - rules.radius)); // bounce back
			}
			if(location.y < rules.radius) {
				velocity.y = -velocity.y;
			location.y -= 2 * (location.y - rules.radius); // bounce back
			}
			break;
		case Rules::Boundaries::Inertial : // TODO basically works, needs tuning!
			if(location.x > ofGetWidth())	applyForce(ofVec2f(-10 * (location.x - ofGetWidth()), 0));
			if(location.x < 0)		applyForce(ofVec2f(10 * (-location.x), 0));
			if(location.y > ofGetHeight())	applyForce(ofVec2f(0, -10 * (location.y - ofGetHeight())));
			if(location.y < 0)		applyForce(ofVec2f(0, 10 * (-location.y)));
			break;
	}
}

void BoidBody::applyForce(ofVec2f force) {
	acceleration = acceleration + (force / rules.weight);
}
