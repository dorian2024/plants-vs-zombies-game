#pragma once
//function that creates a plant 
//abstract class
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
#include "Peashooter.h"
#include "Wallnut.h"
#include "Cherrybomb.h"
#include "Snowpea.h"
#include "Repeater.h"
#include "Fumeshroom.h"

using namespace sf;
using namespace std;
class PlantFactory
{
protected:
	int plantCount;
	int price; //add check to see if we can afford to buy the plant
	float coolDownTime;
	sf::Time plantCreation;
	sf::Clock plantCreationClock;
	sf::Texture plant;
	sf::Sprite s_plant;
	bool plantExists[5][9];

public:
	Plants* plantArray[6][9]; //2d array of pointers
	PlantFactory();
	virtual Sprite& getPlantSprite() = 0;
	virtual void createPlant(coordinates&  plantLocation, int row, int column, sf::RenderWindow& window, int& balance) = 0;
	virtual Texture& getTexture();
	virtual void plantFunctions(sf::RenderWindow& window);
	virtual bool collision(coordinates& zombie) {
		return false;
	}
	//~PlantFactory();
};


//	void createPlant(coordinates& plantCoordinates, int plantType) {
//
//		if (plantType == 1) {
//			Sunflower sun1;
//			plants = &sun1;
//		}
//	}
//	void draw(RenderWindow& window) {
//		window.draw(plants->getSprite());
//	}
//};
