#include "RepeaterFactory.h"
RepeaterFactory::RepeaterFactory() : PlantFactory() {
	//lifetime = 10;
	plantCount = 0;
	price = 200;
	plant.loadFromFile("C:/Users/wajiz.pk/Desktop/urgh/SFML/Images/repeater.png");
	s_plant.setTexture(plant);
	coolDownTime = 0.5;

}
Sprite& RepeaterFactory::getPlantSprite() {
	return s_plant;
}

void RepeaterFactory::createPlant(coordinates& plantLocation, int row, int column, sf::RenderWindow& window, int& balance)
{
	if (!plantExists[row][column]) {

		plantCreation = plantCreationClock.getElapsedTime();
		if (plantCreation.asSeconds() >= coolDownTime) {
			if (balance >= price) {
				balance -= price;
				plantArray[row][column] = new Repeater(plantLocation); //im calculating rows and columns from 1 onwards not 0 hence the -2
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