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
using namespace sf;
using namespace std;
class RepeaterFactory : public PlantFactory
{

public:
	RepeaterFactory();
	Sprite& getPlantSprite()override;
	void createPlant(coordinates& plantLocation, int row, int column, sf::RenderWindow& window, int& balance) override;
};