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
#include "GameTime.h"
#include "SunLight.h"
class RooftopRampage : public Levels
{
private:
	Texture peaShooterIcon;
	Sprite s_peaShooterIcon;

	Texture sunflowerIcon;
	Sprite s_sunflowerIcon;

	Texture wallnutIcon;
	Sprite s_wallnutIcon;

	Texture cherryBombIcon;
	Sprite s_cherryBombIcon;

	Texture repeaterIcon;
	Sprite s_repeaterIcon;

	Texture snowPeaIcon;
	Sprite s_snowPeaIcon;

	Texture fumeshroomIcon;
	Sprite s_fumeshroomIcon;

	Texture background;
	Sprite s_background;


public:
	RooftopRampage(GameTime& gameTime, SunLight* sunlight);
	void drawIcons(sf::RenderWindow& window) override;
	void zombiesCreation() override;
	void drawBackground(sf::RenderWindow& window);
	int getPlantType(Mouse mouse, sf::RenderWindow& window) override;
};

