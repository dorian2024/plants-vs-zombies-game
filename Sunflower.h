#pragma once
#include "Plants.h"
#include "PlantFactory.h"
#include "Coordinates.h"
#include <SFML/Graphics.hpp>
#include <ctime>
#include <iostream>
#include <cstdlib>
using namespace sf;
using namespace std;
class Sunflower : public Plants {
protected:
	float sunProductionTime;
	sf::Time sunTime;
	sf::Clock sunClock;
	sf::Sprite s_suns;
	sf::Texture suns;
	sf::Color plantColor;
	SunLight* sunLight;
	bool sunExistence;
public:
	Sunflower(coordinates& location) : Plants(location){
		sunProductionTime = 0;
		plant.loadFromFile("C:/Users/wajiz.pk/Desktop/urgh/SFML/Images/sunflower.png");
		s_plant.setTexture(plant);
		s_plant.setPosition(location.x, location.y);
		sunProductionTime = 10;//sec
		sunExistence = false;
		plantColor = s_plant.getColor();
		sunTime = sunClock.getElapsedTime();
		suns.loadFromFile("C:/Users/wajiz.pk/Desktop/urgh/SFML/Images/SkySun.png");
		s_suns.setTexture(suns);
	}
	void createSuns(sf::RenderWindow& window) { //will only be called through sunflower factory
		sunTime = sunClock.getElapsedTime();
		if (sunTime.asSeconds() >= 3) {
			sunExistence = true;
			s_suns.setPosition(location.x + 60, location.y + 40);
			s_plant.setColor(plantColor);
		}
		if (sunTime.asSeconds() >= 7) {
			sunExistence = false;
			s_suns.setPosition(-12, -12);
			sunClock.restart();
		}
	}
	void setSunPosition(int x, int y) {
		s_suns.setPosition(x, y);
	}
	void drawSuns(sf::RenderWindow& window) {
		if (sunExistence) {
			window.draw(s_suns);
		}
	}
	bool getSunExistence() {
		return sunExistence;
	}
	Time& getSunTime() {
		return sunTime;
	}
	void setSunExistence(bool existence) {
		sunExistence = existence;
	}
	void plantFunctionality(sf::RenderWindow& window) override {
		createSuns(window);
		drawSuns(window);
	}
};

