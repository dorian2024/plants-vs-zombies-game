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
class FlyingZombie: public Zombie
{
public:
	FlyingZombie() {
		zombie.loadFromFile("C:/Users/wajiz.pk/Desktop/urgh/SFML/Images/flyingzombie.png");
		s_zombie.setTexture(zombie);

	}
};

