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
class FootballZombie : public Zombie
{
public:
	FootballZombie() {
		zombie.loadFromFile("C:/Users/wajiz.pk/Desktop/urgh/SFML/Images/footballzombie.png");
		s_zombie.setTexture(zombie);
	}
};

