#pragma once
#include "Plants.h"
#include "PlantFactory.h"
#include "Coordinates.h"
#include <SFML/Graphics.hpp>
#include <ctime>
#include "Plants.h"
#include <iostream>
#include <cstdlib>
using namespace sf;
using namespace std;
class Peashooter : public Plants
{
private:
	coordinates pealocation;
	Sprite s_pea;
	Texture pea;
	float speed;
	Time peaCreationTime;
	Clock peaCreationClock;
	Time peaMoveTime;
	Clock peaMoveClock;
	bool peaExists;
public:
	Peashooter(coordinates& location): Plants(location) {
		peaCreationClock.restart();
		peaCreationTime = peaCreationClock.getElapsedTime();
		peaMoveClock.restart();
		peaMoveTime = peaMoveClock.getElapsedTime();
		pealocation.x = location.x;
		pealocation.y = location.y;
		pea.loadFromFile("C:/Users/wajiz.pk/Desktop/urgh/SFML/Images/peabullet.png");
		s_pea.setTexture(pea);
		s_pea.setPosition(pealocation.x, pealocation.y);
		peaExists = false;
	}
	void shootPeas() {
		peaCreationTime = peaCreationClock.getElapsedTime();
		if (peaCreationTime.asSeconds() <= 2 || peaExists == true) {
			return;
		}
		else {
			peaExists = true;
			pealocation.x = location.x + 20;
			pealocation.y = location.y;
			peaCreationClock.restart();
		}
	}
	void movePeas() {
		if (pealocation.x >= 1900) {
			peaExists = false;
		}
		if (peaMoveTime.asSeconds() <= 0.8) {
			pealocation.x += 5;
			s_pea.setPosition(pealocation.x, pealocation.y);
			peaMoveClock.restart();
		}
		else { 
			return;
		}
	}
	void drawPeas(sf::RenderWindow& window) {
		if (peaExists) {
			window.draw(s_pea);
		}
	}
	void plantFunctionality(sf::RenderWindow& window)override{
		shootPeas();
		movePeas();
		drawPeas(window);
	}
	bool collision(coordinates& zombieCoordinates) override {
		int zombieEndPixely = 200;
		if (zombieCoordinates.x <= pealocation.x + 60 && zombieCoordinates.y <= pealocation.y && zombieCoordinates.y + 200 >= pealocation.y) {
			peaExists = false;
			cout << "collision";
			return true;
		}
		else return false;
	}
};

