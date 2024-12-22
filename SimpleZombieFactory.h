#pragma once
#include "Zombie.h"
#include <SFML/Graphics.hpp>
#include <ctime>
#include <iostream>
#include "Coordinates.h"
#include "Lawnmower.h"
#include "ZombieFactory.h"
#include "SimpleZombie.h"
#include <cstdlib>
#include <ctime>
using namespace sf;
using namespace std;
class SimpleZombieFactory : public ZombieFactory
{
protected:
public:
	SimpleZombieFactory() : ZombieFactory () {
		zombieCreationClock.restart();

		zombieCreationAllowedTime = 5 + rand() % 8; //seconds
	}
	
	void zombieSpawning() override {
		zombieCreationTime = zombieCreationClock.getElapsedTime();
		if (zombieCreationTime.asSeconds() >= (10 + rand() % 15)) {
			if (totalZombieCount > currentZombieCount) {
				zombies[currentZombieCount] = new SimpleZombie();
				zombies[currentZombieCount]->initialiseZombie();
				currentZombieCount++;
			}
			zombieCreationClock.restart();
		}
	}
	~SimpleZombieFactory() {
		delete[] zombies;
		zombies = nullptr;
	}
};

