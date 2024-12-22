#pragma once
//function to draw icons
//cutofftime
#pragma once
#include <SFML/Graphics.hpp>
#include <ctime>
#include <iostream>
#include "Coordinates.h"
#include "Lawnmower.h"
#include <cstdlib>
#include "Zombie.h"
#include "SimpleZombie.h"
#include "PlantFactory.h"
#include "GameTime.h"
#include "SunLight.h"

#include "SunflowerFactory.h"
#include "PeashooterFactory.h"
#include "WallnutFactory.h"
#include "RepeaterFactory.h"
#include "SnowPeaFactory.h"
#include "CherryBombFactory.h"
#include "FumeshroomFactory.h"

#include "ZombieFactory.h"
#include "SimpleZombieFactory.h"
#include "FlyingZombieFactory.h"
#include "DolphinZombieFactory.h"
#include "DancingZombieFactory.h"
#include "FootballZombieFactory.h"


using namespace sf;
using namespace std;
//abstract class
class Levels
{
protected:
	/// ////////////////////////////////////////////		ZOMBIE COUNT		////////////////////////////////////////////////////////////////
	int simpleZombiesCount;
	int footballZombiesCount;
	int flyingZombieCount;
	int dancingZombieCount;
	int dolphinZombieCount;


	//////////////////////////////////////////////////		ZOMBIE POINTERS	AND TIME	////////////////////////////////////////////////////////////////
	/*Zombie* simpleZb;
	Zombie* footballZb;
	Zombie* flyingZb;
	Zombie* dancingZb;
	Zombie* dolphinZb;*/
	ZombieFactory** zombieFactory; 
	SimpleZombieFactory simplezombiefactory;
	FlyingZombieFactory flyingzombiefactory;
	DolphinZombieFactory dolphinzombiefactory;
	DancingZombieFactory dancingzombiefactory;
	FootballZombieFactory footballzombiefactory;
	float zombieCreationAllowedTime;

	///////////////////////////////////////////////////		PLANTS		//////////////////////////////////////////////////////////////////////////
	int* allowedPlants;
	PlantFactory* plantFactory;
	SunflowerFactory sunflowerfactory;
	PeashooterFactory peashooterfactory;
	WallnutFactory wallnutfactory;
	RepeaterFactory repeaterfactory;
	SnowpeaFactory snowpeafactory;
	CherryBombFactory cherrybombfactory;
	FumeshroomFactory fumeshroomfactory;



	Sprite s_plant;
	///////////////////////////////////////////////////		SUNS		//////////////////////////////////////////////////////////////////////////
	int maxLevelSuns;
	SunLight* sunlight; //aggregation
	sf::Clock sunClock;
	sf::Time sunTime;
	float sunCreationTime;
	sf::Time sunClickTime;
	sf::Clock sunClickClock;

	sf::Time plantSunClickTime;
	sf::Clock plantSunClickClock;
	///////////////////////////////////////////////////////////////		EXTRAS		//////////////////////////////////////////////////////////////////////
	int balance;
	GameTime* time;
	Sprite s_background;
	Texture background;
	bool levelCompleted;
	int levelNumber;
	float zombieSpeed; //px
	int ZombieTypes;
	//float zombieCreationTime
	//plants* rewards
	//Plants* plants
	Lawnmower* lawnmowers;
	sf::Clock lawnmowerClock;

public:

	Levels(int level, GameTime& gameTime, SunLight* sunlight);
	virtual void zombiesCreation() = 0;
	virtual void drawIcons(sf::RenderWindow& window) = 0;
	virtual int getPlantType(Mouse mouse, sf::RenderWindow& window) = 0;
	virtual void plantsCreation(coordinates position, int plantType, int row, int col, sf::RenderWindow& window, int& balance);
	virtual void drawPlants(RenderWindow& window);
	virtual void drawLoop(RenderWindow& window, PlantFactory* plantFactory);
	virtual void generateSuns(sf::RenderWindow& window);
	virtual void moveSuns(sf::RenderWindow& window);
	virtual void drawBackground(sf::RenderWindow& window);
	//virtual void drawSuns(sf::RenderWindow& window);
//	virtual void moveZombie(int speed, sf::RenderWindow& window, sf::Clock& zombieClock, sf::Time& zombieSpeed);
	virtual void checkSunClick(sf::RenderWindow& window, Mouse& plantClick, int& currentSunBalance);
	Sprite& getPlantSprite(int plantType);
	virtual void moveZombies(sf::RenderWindow& window);
	virtual void drawZombie(sf::RenderWindow& window);
	virtual void checkLawnmowerZombieCollision(sf::RenderWindow& window) {
		for (int j = 0; j < ZombieTypes; j++) {
			for (int i = 0; i < 5; i++) {
				if (lawnmowers[i].lawnmowerExists()) {
					if (zombieFactory[j]->checkLawnmowerCollision(lawnmowers[i], 100, 88)) {
						lawnmowers[i].movelawnMower();
						drawLawnmowers(window);
					}
				}
				//cout << "collided at " << lawnmowers[i].getPosition().x << " " << lawnmowers[i].getPosition().y << endl;
			}
		}
	}
	virtual void drawLawnmowers(sf::RenderWindow& window) {
		for (int i = 0; i < 5; i++) {
			if (lawnmowers[i].lawnmowerExists()) {
				window.draw(lawnmowers[i].getLawnmowerSprite());
			}
		}
	}
	virtual void checkBulletZombieCollision() {
		for (int j = 0; j < ZombieTypes; j++) {
			zombieFactory[j]->checkBulletCollisions(peashooterfactory);
		}
	}
	virtual void plantFunctions(sf::RenderWindow& window) {
		sunflowerfactory.plantFunctions(window);
		peashooterfactory.plantFunctions(window);
		wallnutfactory.plantFunctions(window);
		repeaterfactory.plantFunctions(window);
		cherrybombfactory.plantFunctions(window);
		snowpeafactory.plantFunctions(window);
		fumeshroomfactory.plantFunctions(window);
	}
	int getLevel() {
		return levelNumber;
	}
	virtual ~Levels();
};

