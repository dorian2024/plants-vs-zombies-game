#include "GameTime.h"
GameTime::GameTime() {
	plantClick.restart();
	plantClickTime.asSeconds();
	plantClickTime = plantClick.getElapsedTime();
}
bool GameTime::plantClickRegulator(sf::Clock& plantClick) {
	//ensures that plant click is regulated
	plantClickTime = plantClick.getElapsedTime();
	if (plantClickTime.asSeconds() <= 0.2) {
		return false;
	}
	else
		return true;
}
