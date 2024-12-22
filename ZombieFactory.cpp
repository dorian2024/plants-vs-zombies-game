#include "ZombieFactory.h"
ZombieFactory::ZombieFactory() {
	zombies = nullptr; //will turn to dynamically allocated array when we get zombie count from levels using function
	zombieCreationTime = zombieCreationClock.getElapsedTime();
	zombieCreationClock.restart();
	noZombies = true;
	zombieCreationAllowedTime = 0;
	totalZombieCount = 0;
	currentZombieCount = 0;
	bulletCollision.asSeconds();
	bulletCollisionClock.restart();
}
void ZombieFactory::createZombies(int count, float time) {
	zombieCreationAllowedTime = time;
	totalZombieCount = count;
	zombies = new Zombie * [count]; //array of zombie pointers		
}
void ZombieFactory::moveZombie(sf::RenderWindow& window) {
	for (int i = 0; i < currentZombieCount; i++) {
		if (zombies[i] != nullptr) {
			zombies[i]->moveZombie(window);
		}
	}
}

void ZombieFactory::allowZombieMovement(int index, bool allow) {
	if (zombies[index] != nullptr) {
		if (allow) {
			zombies[index]->resumeZombie();
		}
		else if (!allow) {
			zombies[index]->pauseZombie();
		}
	}
}
void ZombieFactory::drawZombie(sf::RenderWindow& window) {
	for (int i = 0; i < currentZombieCount; i++) {
		if (zombies[i] != nullptr) {
			zombies[i]->drawZombie(window);
		}
	}
}
bool ZombieFactory::checkLawnmowerCollision(Lawnmower& lawnmower, int endPixelx, int endPixely)
{

	for (int i = 0; i < currentZombieCount; i++) {
		if (zombies[i] != nullptr) {
			if (zombies[i]->getRow() == lawnmower.getRow()) {
				if (zombies[i]->getPosition().x <= 550 && lawnmower.lawnmowerExists()) {
					lawnmower.movelawnMower();
					delete zombies[i];
					zombies[i] = nullptr;
					return true;
				}
				else if (zombies[i]->getPosition().x >= lawnmower.getPosition().x + 50) {
					lawnmower.movelawnMower();
					delete zombies[i];
					zombies[i] = nullptr;
					return true;
				}
				else return false;
			}
			else return false;
		}
		else return false;
	}
}
ZombieFactory::~ZombieFactory() {
	delete[] zombies;
	zombies = nullptr;
}