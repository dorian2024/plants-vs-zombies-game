#pragma once
#include <SFML/Graphics.hpp>
#include <ctime>
#include <iostream>
#include "Lawnmower.h"
#include "Coordinates.h"
using namespace std;
using namespace sf;
class GameTime
{
private:
	sf::Clock plantClick;
	sf::Time plantClickTime;
public:
	GameTime();
	bool plantClickRegulator(sf::Clock& plantClick);
	
};

