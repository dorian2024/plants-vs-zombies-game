#include "RooftopRampage.h"
RooftopRampage::RooftopRampage(GameTime& gameTime, SunLight* sunlight) : Levels(6, gameTime, sunlight) {
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

	fumeshroomIcon.loadFromFile("C:/Users/wajiz.pk/Desktop/sfml projects/SFML/Images/fumeshroomicon.png");
	s_fumeshroomIcon.setTexture(fumeshroomIcon);
	s_fumeshroomIcon.setPosition(150, 700);

	background.loadFromFile("C:/Users/wajiz.pk/Desktop/sfml projects/SFML/Images/rooftopday.png");
	s_background.setTexture(background);
	s_background.setPosition(0, 0);
}

void RooftopRampage::drawIcons(sf::RenderWindow& window) {
	window.draw(s_peaShooterIcon);
	window.draw(s_sunflowerIcon);
	window.draw(s_wallnutIcon);
	window.draw(s_cherryBombIcon);
	window.draw(s_repeaterIcon);
	window.draw(s_snowPeaIcon);
	window.draw(s_fumeshroomIcon);
}
void RooftopRampage::zombiesCreation() {

}
void RooftopRampage::drawBackground(sf::RenderWindow& window) {
	window.draw(s_background);
}
int RooftopRampage::getPlantType(Mouse mouse, sf::RenderWindow & window) {
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
				else if (y >= 610 && y <= 700) {
					plantChosen = 6; //snowpea
					return plantChosen;
				}
				else if (y >= 710 && y <= 800) {
					plantChosen = 7; //fumeshroom
					return plantChosen;
				}
				else return 0;

	}
}