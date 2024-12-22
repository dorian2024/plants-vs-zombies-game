#include "Zombie.h"
Zombie::Zombie()
{
	boxpixels = 50;
	//initialised to a random value that will be set later;
	position.x = 1900;
	position.y = 500;
	speed = 10;//pixels; add + level*2 when composed in levels
	life = 10; //takes five hits to kill it. -2 each time
	zombie.loadFromFile("C:/Users/wajiz.pk/Desktop/urgh/SFML/Images/zombie.png");
	s_zombie.setTexture(zombie);
	//position will be set in another function
	zombieClock.restart();
	zombieTime.asSeconds();
	pauseMovement = false;
	initialiseZombie();
	row = 0;
}
void Zombie::initialiseZombie() {
	//int row = (rand() % 2); //we need to multiply rows from 0 to 4 by 3 for the grid
	position.x = 1910;
	row = rand() % 5 + 1;
	position.y = 3 * row * boxpixels;
	s_zombie.setPosition(position.x, position.y);
}
void Zombie::drawZombie(sf::RenderWindow& window) {
	if (existence)
		window.draw(s_zombie);
}
void Zombie::moveZombie(sf::RenderWindow& window) {
	zombieTime = zombieClock.getElapsedTime();
	if (zombieTime.asMilliseconds() <= 500) {
		return;
	}
	else {
		if (existence && !pauseMovement) {
			//cout << "x = " << position.x << "y = " << position.y << endl;
			position.x -= speed;
			s_zombie.setPosition(position.x, position.y);
		}
		if (position.x <= 400) {
			existence = false;
		}
		zombieClock.restart();
	}
}
void Zombie::pauseZombie() {
	pauseMovement = true;
}
void Zombie::resumeZombie() {
	pauseMovement = false;
}
bool Zombie::exists() {
	if (position.x <= 400) {
		existence = false;
	}
	return existence;
}
coordinates& Zombie::getPosition() {
	return position;
}
int Zombie::getRow() {
	return row;
}