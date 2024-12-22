#include "BeginnersGarden.h"
BeginnersGarden::BeginnersGarden(GameTime& gameTime, SunLight* sunlight) : Levels(1, gameTime, sunlight) {
    //icons
    peaShooterIcon.loadFromFile("C:/Users/wajiz.pk/Desktop/urgh/SFML/Images/img1.png");
    s_peaShooterIcon.setTexture(peaShooterIcon);
    s_peaShooterIcon.setPosition(150, 100);
    sunflowerIcon.loadFromFile("C:/Users/wajiz.pk/Desktop/urgh/SFML/Images/img2.png");
    s_sunflowerIcon.setTexture(sunflowerIcon);
    s_sunflowerIcon.setPosition(150, 200);
    //
	zombieCreationAllowedTime = 60;
    simpleZombiesCount = 8;
	ZombieTypes = 1;
	zombieFactory = new ZombieFactory*[ZombieTypes];
	zombieFactory[0] = &simplezombiefactory;
	zombieFactory[0]->createZombies(simpleZombiesCount, zombieCreationAllowedTime);

  /*  simpleZb = new SimpleZombie[simpleZombiesCount];
    for (int i = 0; i < simpleZombiesCount; i++) {
        simpleZb[i].initialiseZombie();
    }*/
}
void BeginnersGarden::drawIcons (sf::RenderWindow& window) {
    window.draw(s_peaShooterIcon);
    window.draw(s_sunflowerIcon);
}
int BeginnersGarden::getPlantType(Mouse mouse, sf::RenderWindow& window) {
	int plantChosen = -1;
	if (mouse.getPosition(window).x >= 150 && mouse.getPosition(window).x <= 300 && mouse.getPosition(window).y >= 100) {
		int y;
		y = mouse.getPosition(window).y;
		if (mouse.getPosition(window).y >= 100 && mouse.getPosition(window).y <= 200) {
			plantChosen = 1; //sunflower
			return 1;
			//function that draws icons//levels
			//function that returns a sprite by reference of the icon you clicked //levels
			//attach to mouse; //gameplay
			//check for second click //gameplay
			//when second clidk pass cooordinates into plant creation function //level 

			//it checks if its outside range so itll remove sprite
			//sprite bool draw;
			//if inside range 
			//draw and create plant
			//create a function that checks grid
		}
		else if (mouse.getPosition(window).y >= 210 && mouse.getPosition(window).y <= 300) {
			plantChosen = 2; //peashooter?
			return 2;
		}
		else return 0;
	}
}
void BeginnersGarden::zombiesCreation() {
	for (int i = 0; i < ZombieTypes; i++) {
		zombieFactory[i]->zombieSpawning();
	}
}
