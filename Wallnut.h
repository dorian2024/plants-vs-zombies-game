#pragma once
#include "Plants.h"
#include "PlantFactory.h"
#include "Coordinates.h"
#include <SFML/Graphics.hpp>
#include <ctime>
#include "Plants.h"
#include <iostream>
#include <cstdlib>
using namespace sf;
using namespace std;
class Wallnut : public Plants
{
public:
	Wallnut(coordinates& location) : Plants(location) {

	}
	void plantFunctionality(sf::RenderWindow& window) override {
		plantTime = plantClock.getElapsedTime();
		if (plantTime.asSeconds() >= 0.01) {
			float rotation = s_plant.getRotation();
			rotation += 0.1f; // Adjust rotation speed as needed
			s_plant.setRotation(rotation);

			location.x += 1;
			s_plant.setPosition(location.x, location.y);
			if (location.x >= 1900) {
				lifetime = 0;
			}
			plantClock.restart();
		}
		else return;
	}
};

