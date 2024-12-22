#pragma once
#include <SFML/Graphics.hpp>
#include <ctime>
#include <iostream>
#include "Coordinates.h"
#include "Lawnmower.h"
#include <cstdlib>
#include <ctime>
using namespace sf;
using namespace std;
class Zombie
	//to add time to zombie creation
{
protected:
	coordinates position;
	int speed;
	int life;
	int boxpixels; //delete later
	sf::Sprite s_zombie;
	sf::Texture zombie;
	bool existence;
	sf::Clock zombieClock;
	sf::Time zombieTime;
	bool pauseMovement;
	int row;
public:
	Zombie();
	virtual void initialiseZombie();
	virtual void drawZombie(sf::RenderWindow& window);
	virtual void moveZombie(sf::RenderWindow& window);
	virtual coordinates& getPosition();
	virtual void pauseZombie();
	virtual void resumeZombie();
	virtual bool exists();
	int getRow();
	virtual void damage(int damage) {
		life -= damage;
	}
	virtual int getLife() {
		return life;
	}

};

