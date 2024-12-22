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
#include "PlantFactory.h"
#include "SunLight.h"
using namespace sf;
using namespace std;
class SunflowerFactory: public PlantFactory
{
	
public:
	SunflowerFactory();
	Sprite& getPlantSprite()override;
	void createPlant(coordinates& plantLocation, int row, int column, sf::RenderWindow& window, int& balance) override;
	/*void createSuns(sf::RenderWindow& window) {
		for (int i = 0; i <= 5; i++) {
			for (int j = 0; j < 9;j++) {
				if (plantArray[i][j] != nullptr) {
					if (!plantArray[i][j]->getSunExistence())
						plantArray[i][j]->createSuns(window);
				}
			}
		}
	}*/
};

