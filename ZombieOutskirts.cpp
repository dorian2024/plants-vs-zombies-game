
#include "ZombieOutskirts.h"
ZombieOutskirts::ZombieOutskirts(GameTime& gameTime, SunLight* sunlight) :Levels(2, gameTime, sunlight) {
	peaShooterIcon.loadFromFile("C:/Users/wajiz.pk/Desktop/urgh/SFML/Images/img1.png");
	s_peaShooterIcon.setTexture(peaShooterIcon);
	s_peaShooterIcon.setPosition(150, 100);
	wallnutIcon.loadFromFile("C:/Users/wajiz.pk/Desktop/urgh/SFML/Images/img6.png");
	s_wallnutIcon.setTexture(wallnutIcon);
	s_wallnutIcon.setPosition(150, 300);
	sunflowerIcon.loadFromFile("C:/Users/wajiz.pk/Desktop/urgh/SFML/Images/img2.png");
	s_sunflowerIcon.setTexture(sunflowerIcon);
	s_sunflowerIcon.setPosition(150, 200);

	simpleZombiesCount = 4;
	footballZombiesCount = 3;
	flyingZombieCount = 1;
	dancingZombieCount = 1;
	dolphinZombieCount = 2;
	zombieSpeed = 7;
	ZombieTypes = 5;
	zombieCreationAllowedTime = 50;
	zombieFactory = new ZombieFactory * [ZombieTypes];
	zombieFactory[0] = &simplezombiefactory;
	zombieFactory[1] = &footballzombiefactory;
	zombieFactory[2] = &flyingzombiefactory;
	zombieFactory[3] = &dancingzombiefactory;
	zombieFactory[4] = &dancingzombiefactory;
	for (int i = 0; i < ZombieTypes; i++) {
		zombieFactory[i]->createZombies(simpleZombiesCount, zombieCreationAllowedTime);
	}



	background.loadFromFile("C:/Users/wajiz.pk/Desktop/urgh/SFML/Images/background.png");
	s_background.setTexture(background);
	s_background.setPosition(0, 0);

	//simpleZb = new SimpleZombie[simpleZombiesCount];
	//for (int i = 0; i < simpleZombiesCount; i++) {
	//	simpleZb[i].initialiseZombie();
	//}
	//footballZb = new FootballZombie[footballZombiesCount];
	//for (int i = 0; i < footballZombiesCount; i++) {
	//	footballZb[i].initialiseZombie();
	//}
	//flyingZb = new FlyingZombie[flyingZombieCount];
	//for (int i = 0; i < flyingZombieCount; i++) {
	//	flyingZb[i].initialiseZombie();
	//}
	//dancingZb = new DancingZombie[dancingZombieCount];
	//for (int i = 0; i < dancingZombieCount; i++) {
	//	dancingZb[i].initialiseZombie();
	//}
	//dolphinZb = new DolphinRiderZombie[dolphinZombieCount];
	//for (int i = 0; i < dolphinZombieCount; i++) {
	//	dolphinZb[i].initialiseZombie();
	//}
}
int ZombieOutskirts::getPlantType(Mouse mouse, sf::RenderWindow& window) {
	int plantChosen = -1;
	if (mouse.getPosition(window).x >= 150 && mouse.getPosition(window).x <= 300 && mouse.getPosition(window).y >= 100) {
		if (mouse.getPosition(window).y >= 100 && mouse.getPosition(window).y <= 200) {
			plantChosen = 1; //sunflower
			return plantChosen;
		}
		else if (mouse.getPosition(window).y >= 210 && mouse.getPosition(window).y <= 300) {
			plantChosen = 2; //peashooter?
			return plantChosen;
		}
		else if (mouse.getPosition(window).y >= 310 && mouse.getPosition(window).y <= 400) {
			plantChosen = 3;
			return plantChosen;
		}
		else return 0;
	}
}
void ZombieOutskirts::drawIcons(RenderWindow& window) {
	window.draw(s_peaShooterIcon);
	window.draw(s_sunflowerIcon);
	window.draw(s_wallnutIcon);
}
void ZombieOutskirts::zombiesCreation() {
	for (int i = 0; i < ZombieTypes; i++) {
		zombieFactory[i]->zombieSpawning();
	}
}