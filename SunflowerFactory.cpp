#include "SunflowerFactory.h"
SunflowerFactory::SunflowerFactory(): PlantFactory() {
	plantCount = 0;
	price = 50;
	plant.loadFromFile("C:/Users/wajiz.pk/Desktop/sfml projects/SFML/Images/sunflower.png");
	s_plant.setTexture(plant);
	coolDownTime = 0.5;

}
Sprite& SunflowerFactory::getPlantSprite() {
	return s_plant;
}

void SunflowerFactory::createPlant(coordinates& plantLocation, int row, int column, sf::RenderWindow& window, int& balance)
{
	if (!plantExists[row][column]) {

		plantCreation = plantCreationClock.getElapsedTime();
		if (plantCreation.asSeconds() >= coolDownTime) {
			if (balance >= price) {
				balance -= price;
				plantArray[row][column] = new Sunflower (plantLocation); //im calculating rows and columns from 1 onwards not 0 hence the -2
				plantArray[row][column]->setLifetime(10);
				s_plant.setPosition(plantLocation.x, plantLocation.y);
				window.draw(s_plant);
				plantCreationClock.restart();

			}
			else {
				// add a font displaying error
			}
		}
		plantExists[row][column] = false;
	}
	

}
