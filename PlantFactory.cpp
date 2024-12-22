#include "PlantFactory.h"
PlantFactory::PlantFactory() {
	plantCount = 0;
	for (int i = 0; i < 6; i++) {
		for (int j = 0; j < 9; j++) {
			plantArray[i][j] = nullptr;
			plantExists[i][j] = false;
		}
	}
	coolDownTime = 0.9;
	plantCreation.asSeconds();
	plantCreationClock.restart();
	//sunflowerCount = 0;
	//peashooterCount = 0;
	//wallnutCount = 0;
	//cherrybombCount = 0;
	//repeaterCount = 0;
	//snowpeaCount = 0;
	//fumeshroomCount = 0;
}

Texture& PlantFactory::getTexture()
{
	return plant;
}
void PlantFactory::plantFunctions(sf::RenderWindow& window) {
	for (int i = 0; i < 6; i++) {
		for (int j = 0; j < 9; j++) {
			if(plantArray[i][j] != nullptr){
				plantArray[i][j]->plantFunctionality(window);
			}
		}
	}
}
//void PlantFactory::createPlant(coordinates& plantLocation, int row, int column, sf::RenderWindow& window, int& balance, int plantType)
//{
//	if (plantArray[row][column] != nullptr) {
//		plantCreation = plantCreationClock.getElapsedTime();
//		if (plantCreation.asSeconds() >= coolDownTime) {
//			if (balance >= price) {
//				balance -= price;
//				switch (plantType) {
//				case 2: plantArray[row][column] =  new Sunflower(plantLocation);
//					break;
//				case 1:
//					plantArray[row][column] = new Peashooter(plantLocation);
//					break;
//				case 3:
//					plantArray[row][column] = new Wallnut(plantLocation);
//					break;
//				case 4:
//					plantArray[row][column] = new Cherrybomb (plantLocation);
//					break;
//				case 5:
//					plantArray[row][column] = new Repeater (plantLocation);
//					break;
//				case 6:
//					plantArray[row][column] = new Snowpea (plantLocation);
//					break;
//				case 7:
//					plantArray[row][column] = new Fumeshroom(plantLocation);
//					break;
//				default:
//					return;
//				}
//				plantArray[row][column]->setLifetime(10);
//				s_plant.setPosition(plantLocation.x, plantLocation.y);
//				plantCreationClock.restart();
//			}
//			else {
//				// add a font displaying error
//			}
//		}
//		plantExists[row][column] = false;
//	}
//}