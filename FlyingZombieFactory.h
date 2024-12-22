#pragma once
#include "Zombie.h"
#include <SFML/Graphics.hpp>
#include <ctime>
#include <iostream>
#include "Coordinates.h"
#include "Lawnmower.h"
#include "ZombieFactory.h"
#include "SimpleZombie.h"
#include "FlyingZombie.h"
#include <cstdlib>
#include <ctime>
using namespace sf;
using namespace std;
class  FlyingZombieFactory : public ZombieFactory
{
protected:
public:
	FlyingZombieFactory() : ZombieFactory() {
		zombieCreationClock.restart();
		zombieCreationAllowedTime = 20 + rand() % 8; //seconds
	}

	void zombieSpawning() override {
		zombieCreationTime = zombieCreationClock.getElapsedTime();
		if (zombieCreationTime.asSeconds() >= (40 + rand() % 20)) {
			if (totalZombieCount > currentZombieCount) {
				zombies[currentZombieCount] = new FlyingZombie();
				zombies[currentZombieCount]->initialiseZombie();
				currentZombieCount++;
				zombieCreationClock.restart();
			}
		}
	}
	~FlyingZombieFactory() {
		delete[] zombies;
		zombies = nullptr;
	}
};

