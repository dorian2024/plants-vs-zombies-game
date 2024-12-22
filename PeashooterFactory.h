#pragma once

#include "Plants.h"
#include <SFML/Graphics.hpp>
#include <ctime>
#include <iostream>
#include "Coordinates.h"
#include "Lawnmower.h"
#include <cstdlib>
#include "Zombie.h"
#include "SimpleZombie.h"
#include "Sunflower.h"
#include "PlantFactory.h"
#include "Peashooter.h"
using namespace sf;
using namespace std;

class PeashooterFactory: public PlantFactory
{
	//plants*
public:
	PeashooterFactory();
	Sprite& getPlantSprite() override;
	void createPlant(coordinates& plantLocation, int row, int column, sf::RenderWindow& window, int& balance) override;
	void plantFunctions(sf::RenderWindow& window) override;
	bool collision(coordinates& zombie) override {
		for (int i = 0; i <= 5; i++) {
			for (int j = 0; j < 9; j++) {
				if (plantArray[i][j] != nullptr) {
					if (plantArray[i][j]->collision(zombie))
					{
						return true;
					}
				}
			}
		}
		return false;
	}
};

