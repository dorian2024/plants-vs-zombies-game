#pragma once
#include <SFML/Graphics.hpp>
#include <ctime>
#include <iostream>
#include "Lawnmower.h"
#include "Coordinates.h"
#include "Zombie.h"
#include "BeginnersGarden.h"
#include "ZombieOutskirts.h"
#include "PlantFactory.h"
#include "Plants.h"
#include "SunflowerFields.h"
#include "FoggyForest.h"
#include "RooftopRampage.h"
#include "NighttimeSiege.h"
#include "GameTime.h"
#include "SunLight.h"
using namespace std;
using namespace sf;
class Game
{
protected:
	////////////////////////////////////   SPRITES   /////////////////////////////////////////////////////
	//backgrounds
	sf::Sprite s_background;
	sf::Sprite s_nightBackground;
	sf::Texture day;
	sf::Texture night;
	//screens
	sf::Sprite s_pauseScreen;
	sf::Texture pauseScreen;
	sf::Sprite s_startScreen;
	sf::Texture startScreen;
	//icons
	sf::Texture menu;
	sf::Sprite s_menu;
	sf::Texture instructions;
	sf::Sprite s_instructions;

	sf::Texture sunCount;
	sf::Sprite s_sunCount;
	sf::Text scoreText;
	sf::Font font;
	///delete 
	sf::Sprite s_plant;
	sf::Texture plant;
	bool isFirstClick;
	int plantChosen;
	bool dragPlant;
	///delete ???
	///////////////////////////// PLANTS and OTHERS //////////////////////////////////
	int** gameRows;
	int currentLevel;
	Levels* level;
	GameTime time;
	Clock plantClock;
	int plantType;
	///////////////////////////////////// SUNS ////////////////////////////////////////////

	int currentSunBalance;
	SunLight sunlight[20];


	
	////////////////////////////////////	ZOMBIES		//////////////////////////////////////////////////////////
	sf::Clock zombieClock;
	Zombie* zomb;
	Zombie* zomb2;
	Zombie* zomb3;
	///////////////////////////////		 STATIC VARIABLES	 //////////////////////////////////////////////////////////
public:
	static const int xResolution;
	static const int yResolution;
	static const int boxPixels;
	static const int grassPixelsX;
	static const int xRows;
	static const int yRows;
//	int xGridPixels[9] = {110, 130, 112, 110, 125, 120, 110, 130, 130};
	int xGridPixels[10] = { 0, 110, 240, 352, 462, 587, 707, 817, 947, 1077 };
	Game();
	static const int getBoxPixels();
	void gamePlay();
	void createSuns(sf::RenderWindow& window, sf::Clock& sunClock);
	bool PlantSecondClick(Mouse& m, int icon_number, RenderWindow& window, Sprite& Sprite);
	~Game();

};
