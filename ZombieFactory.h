#pragma once
#include "Zombie.h"
#include <SFML/Graphics.hpp>
#include <ctime>
#include <iostream>
#include "Coordinates.h"
#include "PeashooterFactory.h"

#include "Lawnmower.h"
#include <cstdlib>
#include <ctime>
using namespace sf;
using namespace std;
//supposed to be abstract
class ZombieFactory
{
protected:
	Time zombieCreationTime;
	Clock zombieCreationClock;
	float zombieCreationAllowedTime;
	int totalZombieCount;
	int currentZombieCount;
	Time bulletCollision;
	Clock bulletCollisionClock;
	bool noZombies; //if no zombies exist of a certain type dont run the loop
public:
	Zombie** zombies;
	ZombieFactory();
	virtual void createZombies(int count, float time);
	virtual void zombieSpawning() = 0; // will add the zombie pointers to the array // add time element here
	virtual void moveZombie(sf::RenderWindow& window);
	//will call move zombie from zombie pointer one frame at a time //will only move the zombies that exist
	//check if plants in the way
	virtual void allowZombieMovement(int index, bool allow);
	virtual void drawZombie(sf::RenderWindow& window);
	virtual bool checkLawnmowerCollision(Lawnmower& lawnmower, int endPixelx, int endPixely);
	virtual void checkBulletCollisions(PeashooterFactory& peashooterfactory) {
		for (int i = 0; i < currentZombieCount; i++) {
			bulletCollision = bulletCollisionClock.getElapsedTime();
			if (bulletCollision.asSeconds() >= 0.1) {
				if (zombies[i] != nullptr) {
					if (peashooterfactory.collision(zombies[i]->getPosition())) {
						zombies[i]->damage(2);
						if (zombies[i]->getLife() <= 0) {
							delete zombies[i];
							zombies[i] = nullptr;
						}
					}
				}
				else return;
			}
			else return;
			
		}
	}
	//virtual bool checkZombieTermination(); //main implementation//checks if all zombies have been terminated so that it can go to the next level
	//moveZombie() = 0;
	//consider konsi level hai
	//create zombies accordingly
	//using time
		virtual ~ZombieFactory();//deletes new zombies array
};
//being inherited by all the other factories so theyll make use of the same functionalities 
//move zombie should be in zombie as its not a functionality of zombie
//createZombie is universal
//zombie creation time
//random position generator
//zombie draw
//zombie move
//delete zombie 