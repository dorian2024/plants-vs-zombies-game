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
class Repeater : public Plants
{
public:
	Repeater(coordinates& location) : Plants(location) {

	}
	void plantFunctionality(sf::RenderWindow& window) override {

	}
};