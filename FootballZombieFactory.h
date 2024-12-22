#pragma once
#include "Zombie.h"
#include <SFML/Graphics.hpp>
#include <ctime>
#include <iostream>
#include "Coordinates.h"
#include "Lawnmower.h"
#include "ZombieFactory.h"
#include "SimpleZombie.h"
#include "FootballZombie.h"
#include <cstdlib>
#include <ctime>
using namespace sf;
using namespace std;
class  FootballZombieFactory : public ZombieFactory
{
protected:
public:
	FootballZombieFactory() : ZombieFactory() {
		zombieCreationClock.restart();

		zombieCreationAllowedTime = 34; //seconds
	}

	void zombieSpawning() override {
		zombieCreationTime = zombieCreationClock.getElapsedTime();
		if (zombieCreationTime.asSeconds() >= (50 + rand() % 29)) {
			if (totalZombieCount > currentZombieCount) {
				zombies[currentZombieCount] = new FootballZombie();
				zombies[currentZombieCount]->initialiseZombie();
				currentZombieCount++;
				zombieCreationClock.restart();
			}
		}
	}
	~FootballZombieFactory() {
		delete[] zombies;
		zombies = nullptr;
	}
};
