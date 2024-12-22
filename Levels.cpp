#include "Levels.h"
#include <ctime>
#include <cstdlib>
Levels::Levels(int level, GameTime& gameTime, SunLight* sunlight) {
	//ZOMBIES
	simpleZombiesCount = 0;
	footballZombiesCount = 0;
	flyingZombieCount = 0;
	dancingZombieCount = 0;
	dolphinZombieCount = 0;
	ZombieTypes = 0;
	zombieFactory = new ZombieFactory* [ZombieTypes];
	/*simpleZb = nullptr;
	footballZb = nullptr;
	flyingZb = nullptr;
	dancingZb = nullptr;
	dolphinZb = nullptr;*/

	zombieSpeed = 5;
	zombieCreationAllowedTime = 0;




	//PLANTS
	allowedPlants = nullptr;			//DO SMTH ABT THIS
	//SUN
	sunTime.asSeconds();
	sunTime = sunClock.getElapsedTime();
	sunCreationTime = 10;
	this->sunlight = sunlight;
	maxLevelSuns = 20;				//might be useless

	sunClickTime = sunClickClock.getElapsedTime();
	sunClickClock.restart();
	plantSunClickTime = plantSunClickClock.getElapsedTime();
	plantSunClickClock.restart();

	//SPRITES
	background.loadFromFile("C:/Users/wajiz.pk/Desktop/urgh/SFML/Images/background.png");
	s_background.setTexture(background);
	s_background.setPosition(0, 0);
	//EXTRAS
	time = &gameTime;
	balance = 1500;
	levelCompleted = false;
	levelNumber = level;
	plantFactory = nullptr;
	//lawnmowers
	lawnmowers = new Lawnmower[5];
	for (int i = 0; i < 5; i++) {
		lawnmowers[i].setInitialPosition(i, 50);
	}
}

Sprite& Levels::getPlantSprite(int plantType)
{

	switch (plantType) {
	case 2: plantFactory = &sunflowerfactory;
		sunflowerfactory.getPlantSprite().setPosition(50, 50);
		return plantFactory->getPlantSprite();
		break;
	case 1:
		plantFactory = &peashooterfactory;
		sunflowerfactory.getPlantSprite().setPosition(50, 50);
		return plantFactory->getPlantSprite();
		break;

	case 3:
		plantFactory = &wallnutfactory;
		wallnutfactory.getPlantSprite().setPosition(50, 50);
		return plantFactory->getPlantSprite();
		break;
	case 4:
		plantFactory = &cherrybombfactory;
		cherrybombfactory.getPlantSprite().setPosition(50, 50);
		return plantFactory->getPlantSprite();
		break;
	case 5:
		plantFactory = &repeaterfactory;
		repeaterfactory.getPlantSprite().setPosition(50, 50);
		return plantFactory->getPlantSprite();
		break;
	case 6:
		plantFactory = &snowpeafactory;
		snowpeafactory.getPlantSprite().setPosition(50, 50);
		return plantFactory->getPlantSprite();
		break;
	case 7:
		plantFactory = &fumeshroomfactory;
		fumeshroomfactory.getPlantSprite().setPosition(50, 50);
		return plantFactory->getPlantSprite();
		break;
	}
}

void Levels::plantsCreation(coordinates position, int plantType, int row, int col, sf::RenderWindow& window, int& balance) {
	if (plantType == 2) {
		plantFactory = &sunflowerfactory;
		plantFactory->createPlant(position, row, col, window, balance);

	}
	else if (plantType == 1) {
		plantFactory = &peashooterfactory;
		plantFactory->createPlant(position, row, col, window, balance);

	}
	else if (plantType == 3) {
		plantFactory = &wallnutfactory;
		plantFactory->createPlant(position, row, col, window, balance);
	}
	else if (plantType == 4) {
		plantFactory = &cherrybombfactory;
		plantFactory->createPlant(position, row, col, window, balance);
	}
	else if (plantType == 5) {
		plantFactory = &repeaterfactory;
		plantFactory->createPlant(position, row, col, window, balance);
	}
	else if (plantType == 6) {
		plantFactory = &snowpeafactory;
		plantFactory->createPlant(position, row, col, window, balance);
	}
	else if (plantType == 7) {
		plantFactory = &fumeshroomfactory;
		plantFactory->createPlant(position, row, col, window, balance);
	}
	else return;
}

//void Levels::drawSuns(sf::RenderWindow& window) {
//	for (int i = 0; i <= 5; i++) {
//		for (int j = 0; j < 9; j++) {
//			if (sunflowerfactory.plantArray[i][j] != nullptr) {
//				sunflowerfactory.plantArray[i][j]->drawSuns(window, sunflowerfactory.plantArray[i][j]->getSunExistence());
//			}
//		}
//	}
//
//}

void Levels::drawPlants(RenderWindow& window) {
	plantFactory = &peashooterfactory;
	drawLoop(window, plantFactory);

	plantFactory = &sunflowerfactory;
	drawLoop(window, plantFactory);

	plantFactory = &wallnutfactory;
	drawLoop(window, plantFactory);

	plantFactory = &cherrybombfactory;
	drawLoop(window, plantFactory);

	plantFactory = &repeaterfactory;
	drawLoop(window, plantFactory);

	plantFactory = &snowpeafactory;
	drawLoop(window, plantFactory);

	plantFactory = &fumeshroomfactory;
	drawLoop(window, plantFactory);
}

void Levels::drawBackground(sf::RenderWindow& window) {
	window.draw(s_background);
}

void Levels::drawLoop(RenderWindow& window, PlantFactory* plantFactory) {
	//helper function
	for (int i = 0; i <= 5; i++) {
		for (int j = 0; j < 9; j++) {
			/////////// REMINDER ////////// DONT FORGET ///////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
			//add a bool in plant factory for indexes with plants
			if (plantFactory->plantArray[i][j] != nullptr) {
				int x;
				x = plantFactory->plantArray[i][j]->getPlantCoordinates().x;
				int y;
				y = plantFactory->plantArray[i][j]->getPlantCoordinates().y;
				plantFactory->getPlantSprite().setPosition(x, y);

				window.draw(plantFactory->getPlantSprite());
			}
		}

	}
}

void Levels::generateSuns(sf::RenderWindow& window)
{
	sunTime = sunClock.getElapsedTime();
	if (sunTime.asSeconds() >= sunCreationTime) {
		int index = rand() % 20;
		sunlight[index].createSun();
		sunClock.restart();
	}
}

void Levels::moveSuns(sf::RenderWindow& window) {
	for (int i = 0; i < 20; i++) {
		sunlight[i].moveSun(window);
		sunlight[i].drawSun(window);
	}
	//sunflowerfactory.createSuns(window);
}

void Levels::checkSunClick(sf::RenderWindow& window, Mouse& plantClick, int& currentSunBalance)
{
	int x = plantClick.getPosition(window).x;
	int y = plantClick.getPosition(window).y;
	
	for (int i = 0; i <= maxLevelSuns; i++) {
		//checks for randomly generated suns only
		sunClickTime = sunClickClock.getElapsedTime();
		if (sunClickTime.asSeconds() >= 1) {
			if (x >= sunlight[i].getPosition().x && x <= sunlight[i].getPosition().x + 80 && y >= sunlight[i].getPosition().y && y <= sunlight[i].getPosition().y + 80) {
				sunlight[i].sunExistence(false);
				currentSunBalance += 50;
				sunClickClock.restart();
			}
		}
		//checks sunflower suns
		/*plantSunClickTime = plantSunClickClock.getElapsedTime();
		if (plantSunClickTime.asSeconds() >= 1) {
			for (int i = 0; i <= 5; i++) {
				for (int j = 0; j < 9; j++) {
					if (sunflowerfactory.plantArray[i][j] != nullptr) {
						if (x >= sunflowerfactory.plantArray[i][j]->getPlantCoordinates().x + 60 && x <= sunflowerfactory.plantArray[i][j]->getPlantCoordinates().x + 148) {
							if (y >= sunflowerfactory.plantArray[i][j]->getPlantCoordinates().y + 40 && y <= sunflowerfactory.plantArray[i][j]->getPlantCoordinates().y + 120) {
								sunflowerfactory.plantArray[i][j]->setSunPosition(-100, -100);
								if (sunflowerfactory.plantArray[i][j]->getSunTime().asSeconds() < 3)
									sunflowerfactory.plantArray[i][j]->setSunExistence(false);
								currentSunBalance += 50;
								plantSunClickClock.restart();
							}
						}
					}
				}
			}
		}*/
		
	}

}

void Levels::moveZombies(sf::RenderWindow& window) {
	for (int i = 0; i < ZombieTypes; i++) {
		zombieFactory[i]->moveZombie(window);
	}
}

void Levels::drawZombie(sf::RenderWindow& window) {
	for (int i = 0; i < ZombieTypes; i++) {
		zombieFactory[i]->drawZombie(window);
	}
}

Levels::~Levels() {
	delete[] zombieFactory;
	zombieFactory = nullptr;
}