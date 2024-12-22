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
class DancingZombie: public Zombie
{
public:
	DancingZombie() {
		zombie.loadFromFile("C:/Users/wajiz.pk/Desktop/urgh/SFML/Images/dancingzombie.png");
		s_zombie.setTexture(zombie);
	}
};

