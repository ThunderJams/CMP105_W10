#include "Mario.h"
bool movingM = false;
bool ducking = false;
bool swimming = false;

Mario::Mario() {
	walk.addFrame(sf::IntRect(0, 0, 15, 21));
	walk.addFrame(sf::IntRect(15, 0, 15, 21));
	walk.addFrame(sf::IntRect(30, 0, 15, 21));
	walk.addFrame(sf::IntRect(45, 0, 15, 21));
	walk.setFrameSpeed(1.f / 10.f);

	swim.addFrame(sf::IntRect(0, 21, 16, 20));
	swim.addFrame(sf::IntRect(16, 21, 16, 20));
	swim.addFrame(sf::IntRect(32, 21, 16, 20));
	swim.setFrameSpeed(1.f / 10.f);

	duck.addFrame(sf::IntRect(0, 41, 16, 20));
	duck.addFrame(sf::IntRect(16, 41, 16, 20));
	duck.setFrameSpeed(1.f / 10.f);

	
}

Mario::~Mario() {

}

void Mario::handleInput(float dt) {
	velocity.x = 0;
	movingM = false;
	ducking = false;
	swimming = false;

	if (input->isKeyDown(sf::Keyboard::Left)) {
		velocity.x = -500;
		walk.setFlipped(true);
		movingM = true;
	}

	if (input->isKeyDown(sf::Keyboard::Right)) {
		velocity.x = 500;
		walk.setFlipped(false);
		movingM = true;
	}

	if (input->isKeyDown(sf::Keyboard::Down)) {
		ducking = true;
	}

	if (input->isKeyDown(sf::Keyboard::Up)) {
		swimming = true;
	}
}

void Mario::update(float dt) {

	velocity.y = 98;

	if (ducking) {
		duck.animate(dt);
		setTextureRect(duck.getCurrentFrame());
	}
	else if (movingM) {
		walk.animate(dt);
		setTextureRect(walk.getCurrentFrame());
		move(velocity.x * dt, 0);
	}
	else if (swimming) {
		swim.animate(dt);
		setTextureRect(swim.getCurrentFrame());
	}

	move(0, velocity.y * dt);
}

void Mario::collisionRespone(GameObject* collider)
{
	velocity.y= 0;
	setPosition(getPosition().x,collider->getPosition().y-getSize().y);
}


