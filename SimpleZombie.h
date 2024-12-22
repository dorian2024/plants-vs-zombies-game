#pragma once
#include <SFML/Graphics.hpp>
#include <ctime>
#include <iostream>
#include "Coordinates.h"
#include "Lawnmower.h"
#include <cstdlib>
#include <ctime>
#include "Zombie.h"
using namespace sf;
using namespace std;
class SimpleZombie: public Zombie
{
public:
	SimpleZombie() {
		zombie.loadFromFile("C:/Users/wajiz.pk/Desktop/urgh/SFML/Images/zombie.png");
		s_zombie.setTexture(zombie);
	}

};

