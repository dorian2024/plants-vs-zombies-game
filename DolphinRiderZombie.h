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
class DolphinRiderZombie: public Zombie
{
public:
	DolphinRiderZombie() {
		zombie.loadFromFile("C:/Users/wajiz.pk/Desktop/urgh/SFML/Images/dolphinrider.png");
		s_zombie.setTexture(zombie);

	}
};

