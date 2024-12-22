#include "SunflowerFields.h"
SunflowerFields::SunflowerFields(GameTime& gameTime, SunLight* sunlight) : Levels(3, gameTime, sunlight) {
	peaShooterIcon.loadFromFile("C:/Users/wajiz.pk/Desktop/urgh/SFML/Images/img1.png");
	s_peaShooterIcon.setTexture(peaShooterIcon);
	s_peaShooterIcon.setPosition(150, 100);

	wallnutIcon.loadFromFile("C:/Users/wajiz.pk/Desktop/urgh/SFML/Images/img6.png");
	s_wallnutIcon.setTexture(wallnutIcon);
	s_wallnutIcon.setPosition(150, 300);

	sunflowerIcon.loadFromFile("C:/Users/wajiz.pk/Desktop/urgh/SFML/Images/img2.png");
	s_sunflowerIcon.setTexture(sunflowerIcon);
	s_sunflowerIcon.setPosition(150, 200);

	cherryBombIcon.loadFromFile("C:/Users/wajiz.pk/Desktop/sfml projects/SFML/Images/cherrybombicon.png");
	s_cherryBombIcon.setTexture(cherryBombIcon);
	s_cherryBombIcon.setPosition(150, 400);

	repeaterIcon.loadFromFile("C:/Users/wajiz.pk/Desktop/sfml projects/SFML/Images/repeatericon.png");
	s_repeaterIcon.setTexture(repeaterIcon);
	s_repeaterIcon.setPosition(150, 500);

	snowPeaIcon.loadFromFile("C:/Users/wajiz.pk/Desktop/sfml projects/SFML/Images/snowpeaicon.png");
	s_snowPeaIcon.setTexture(snowPeaIcon);
	s_snowPeaIcon.setPosition(150, 600);

	zombieCreationAllowedTime = 23;
	simpleZombiesCount = 5;
	footballZombiesCount = 4;
	flyingZombieCount = 2;
	dancingZombieCount = 1;
	dolphinZombieCount = 2;
	zombieSpeed = 100;//px
	ZombieTypes = 5;
	zombieFactory = new ZombieFactory * [ZombieTypes];
	zombieFactory[0] = &simplezombiefactory;
	zombieFactory[1] = &footballzombiefactory;
	zombieFactory[2] = &flyingzombiefactory;
	zombieFactory[3] = &dancingzombiefactory;
	zombieFactory[4] = &dolphinzombiefactory;
	for (int i = 0; i < ZombieTypes; i++) {
		zombieFactory[i]->createZombies(simpleZombiesCount, zombieCreationAllowedTime);
	}

}
void SunflowerFields::drawIcons(sf::RenderWindow& window) {
	window.draw(s_peaShooterIcon);
	window.draw(s_sunflowerIcon);
	window.draw(s_wallnutIcon);
	window.draw(s_cherryBombIcon);
	window.draw(s_repeaterIcon);
	window.draw(s_snowPeaIcon);
}

int SunflowerFields::getPlantType(Mouse mouse, sf::RenderWindow& window) {
	int plantChosen = -1;
	if (mouse.getPosition().x >= 150 && mouse.getPosition().x <= 300 && mouse.getPosition().y >= 100) {
		int y;
		y = mouse.getPosition().y;
		if (y >= 100 && y <= 200) {
			plantChosen = 1; //sunflower
			return plantChosen;
		}

		else if (y >= 210 && y <= 300) {
			plantChosen = 2; //peashooter?
			return plantChosen;
		}

		else if (y >= 310 && y <= 400) {
			plantChosen = 3; //wallnut
			return plantChosen;
		}

		else if (y >= 410 && y <= 500) {
			plantChosen = 4; //cherrybomb
			return plantChosen;
		}

		else if (y >= 510 && y <= 600) {
			plantChosen = 5; //repeater
			return plantChosen;
		}
		else if (y >= 610 && y <= 750) {
			plantChosen = 6; //snowpea
			return plantChosen;
		}
		else return 0;
	}
}
void SunflowerFields::zombiesCreation() {
	for (int i = 0; i < ZombieTypes; i++) {
		zombieFactory[i]->zombieSpawning();
	}
}