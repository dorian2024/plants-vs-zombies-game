#include "CherryBombFactory.h"
CherryBombFactory::CherryBombFactory() :PlantFactory() {
	plant.loadFromFile("C:/Users/wajiz.pk/Desktop/urgh/SFML/Images/cherrybomb.png");
	s_plant.setTexture(plant);
}
Sprite& CherryBombFactory::getPlantSprite() {
	return s_plant;
}


void CherryBombFactory::createPlant(coordinates& plantLocation, int row, int column, sf::RenderWindow& window, int& balance)
{
	if (!plantExists[row][column]) {
		plantCreation = plantCreationClock.getElapsedTime();
		if (plantCreation.asSeconds() >= coolDownTime) {
			if (balance >= price) {
				balance -= price;
				plantArray[row][column] = new Cherrybomb (plantLocation); //im calculating rows and columns from 1 onwards not 0 hence the -2
				plantArray[row][column]->setLifetime(10);
				s_plant.setPosition(plantLocation.x, plantLocation.y);
				plantCreationClock.restart();
			}
			else {
				// add a font displaying error
			}
		}
		plantExists[row][column] = false;
	}
}