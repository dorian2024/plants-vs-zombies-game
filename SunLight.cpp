#pragma once
#include "SunLight.h"
#include <cstdlib>
#include <SFML/Graphics.hpp>
#include <ctime>
#include <iostream>
#include "Coordinates.h"
using namespace sf;
using namespace std;

SunLight::SunLight() {
	suns.loadFromFile("C:/Users/wajiz.pk/Desktop/urgh/SFML/Images/SkySun.png");
	s_suns.setTexture(suns);
	plantSun = false;

	if (!plantSun) {
		int x = rand() % 1000;
		cout << "x position: " << x << endl;
		x += 550;
		position.x = x;//sunCoordinates.x;
	}
	position.y = -100;//default value//sunCoordinates.y;
	exists = true;
	currencyWeight = 50;
	
	sunSpeed = 0.2;

	movementTime = movementClock.getElapsedTime();
}
void SunLight::createSun() {
		//cout << "sun created\n";
		if (position.y < 0) {
			position.y = 0;
		}
		cout << "suncreated" << endl;
}
void SunLight::createPlantSun(coordinates& plantPosition) {
	position.x = plantPosition.x + 40;
	position.y = plantPosition.y + 60;
	plantSun = true;
}
void SunLight::moveSun(sf::RenderWindow& window) {
	
	movementTime = movementClock.getElapsedTime();
	if (movementTime.asSeconds() >= 0.1) {
		if (position.y >= 0 && !plantSun) {
			movementClock.restart();
			position.y += 3;
		}
	}
}
void SunLight::drawSun(sf::RenderWindow& window) {
	if (exists) {
		s_suns.setPosition(position.x, position.y);
		window.draw(s_suns);
	}
}
coordinates& SunLight::getPosition()
{
	return position;
}

int SunLight::getCurrencyWeight()
{
	return currencyWeight;
}
