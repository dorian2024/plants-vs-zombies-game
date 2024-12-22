#include "PeashooterFactory.h"
PeashooterFactory::PeashooterFactory():PlantFactory() {
	plant.loadFromFile("C:/Users/wajiz.pk/Desktop/sfml projects/SFML/Images/peashooter.png");
	s_plant.setTexture(plant);
	price = 100;
}
Sprite& PeashooterFactory::getPlantSprite() {
	return s_plant;
}

void PeashooterFactory::createPlant(coordinates& plantLocation, int row, int column, sf::RenderWindow& window, int& balance)
{
	if (!plantExists[row][column]) {
		plantCreation = plantCreationClock.getElapsedTime();
		if (plantCreation.asSeconds() >= coolDownTime) {
			if (balance >= price) {
				balance -= price;
				plantArray[row][column] = new Peashooter (plantLocation); //im calculating rows and columns from 1 onwards not 0 hence the -2
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
void PeashooterFactory::plantFunctions(sf::RenderWindow& window) {
	for (int i = 0; i < 6; i++) {
		for (int j = 0; j < 9; j++) {
			if (plantArray[i][j] != nullptr) {
				plantArray[i][j]->plantFunctionality(window);
			}
		}
	}
}