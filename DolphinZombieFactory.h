#pragma once
#include "Zombie.h"
#include <SFML/Graphics.hpp>
#include <ctime>
#include <iostream>
#include "Coordinates.h"
#include "Lawnmower.h"
#include "ZombieFactory.h"
#include "SimpleZombie.h"
#include "DolphinRiderZombie.h"
#include <cstdlib>
#include <ctime>
using namespace sf;
using namespace std;
class  DolphinZombieFactory : public ZombieFactory
{
protected:
public:
	DolphinZombieFactory() : ZombieFactory() {
		zombieCreationClock.restart();

		zombieCreationAllowedTime = 36; //seconds
	}

	void zombieSpawning() override {
		zombieCreationTime = zombieCreationClock.getElapsedTime();
		if (zombieCreationTime.asSeconds() >= (39 + rand() % 54)) {
			if (totalZombieCount > currentZombieCount) {
				zombies[currentZombieCount] = new DolphinRiderZombie();
				zombies[currentZombieCount]->initialiseZombie();
				currentZombieCount++;
				zombieCreationClock.restart();
			}
		}
	}
	~DolphinZombieFactory() {
		delete[] zombies;
		zombies = nullptr;
	}
};