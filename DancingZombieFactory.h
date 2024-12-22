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
#include "DancingZombie.h"
using namespace sf;
using namespace std;
class  DancingZombieFactory : public ZombieFactory
{
protected:
public:
	DancingZombieFactory() : ZombieFactory() {
		zombieCreationClock.restart();

		zombieCreationAllowedTime = 23; //seconds
	}

	void zombieSpawning() override {
		zombieCreationTime = zombieCreationClock.getElapsedTime();
		if (zombieCreationTime.asSeconds() >= (60 + rand() % 28)) {
			if (totalZombieCount > currentZombieCount) {
				zombies[currentZombieCount] = new DancingZombie();
				zombies[currentZombieCount]->initialiseZombie();
				currentZombieCount++;
				zombieCreationClock.restart();
			}
		}
	}
	~DancingZombieFactory() {
		delete[] zombies;
		zombies = nullptr;
	}
};