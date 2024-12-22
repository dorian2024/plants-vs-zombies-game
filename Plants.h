#pragma once
//make it abstract
#include "Coordinates.h"
#include "SunLight.h"
#include <SFML/Graphics.hpp>
#include <ctime>
#include <iostream>
#include <cstdlib>
using namespace sf;
using namespace std;
//abstract class
class Plants {
protected:
	coordinates location;
	Sprite s_plant;
	Texture plant;
	int lifetime;
	//
	Time plantTime;
	Clock plantClock;

public:
	Plants(coordinates plantLocation); 
	virtual void plantFunctionality(sf::RenderWindow& window) = 0;
	virtual bool collision(coordinates& zombie) { return false; }
	virtual Sprite& getSprite();
	virtual void setLifetime(int life);
	virtual void setLocation(int x, int y);
	virtual coordinates& getPlantCoordinates();




	//sunflower specific function
	
	//void setLocation(); in case i make a shovel function
};

