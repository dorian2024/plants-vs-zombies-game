#pragma once
#include <SFML/Graphics.hpp>
#include <ctime>
#include <iostream>
#include "Lawnmower.h"
#include "Coordinates.h"
#include "Zombie.h"
#include "Levels.h"
#include "SimpleZombie.h"
#include "FootballZombie.h"
#include "FlyingZombie.h"
#include "DancingZombie.h"
#include "DolphinRiderZombie.h"
#include "GameTime.h"
#include "SunLight.h"
//level 2
class ZombieOutskirts: public Levels
{
private:
	Texture peaShooterIcon;
	Sprite s_peaShooterIcon;

	Texture sunflowerIcon;
	Sprite s_sunflowerIcon;

	Texture wallnutIcon;
	Sprite s_wallnutIcon;
public:
	ZombieOutskirts(GameTime& gameTime, SunLight* sunlight);
	void drawIcons(RenderWindow& window) override;
	void zombiesCreation() override;
	int getPlantType(Mouse mouse, sf::RenderWindow& window) override;

};

