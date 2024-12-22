#pragma once
#include <SFML/Graphics.hpp>
#include <ctime>
#include <iostream>
#include "Coordinates.h"
using namespace sf;
using namespace std;

class Lawnmower
{
	//private because its not being inherited anywhere
private:
	bool existence;
	int lawnmowerCount;
	coordinates position;
	Sprite s_lawnmower;
	Texture lawnmower;
	bool isMoving;
	int row;
public:
	Lawnmower() { //count is from 0 to 4
		existence = true;
		lawnmowerCount = 0;
		position.x = 0;
		position.y = 0;
		lawnmower.loadFromFile("C:/Users/wajiz.pk/Desktop/urgh/SFML/Images/lawnmower.png");
		s_lawnmower.setTexture(lawnmower);
		isMoving = false;
		row = 0;
	}
	void setInitialPosition(int count, const int boxPixels) {
		position.x = 9 * boxPixels;
		row = count + 1;
		position.y = (5 + 3 * count) * boxPixels;
		lawnmowerCount = count;
		s_lawnmower.setPosition(position.x, position.y);
	}
	bool lawnmowerExists() {
		return existence;
	}
	void movelawnMower() {
		position.x += 1;
		s_lawnmower.setPosition(position.x, position.y);
		if (position.x >= 1900) {
			existence = false;
		}
	}
	Sprite& getLawnmowerSprite() {
		return s_lawnmower;
	}
	coordinates& getPosition() {
		return position;
	}
	void setExistence(bool state) {
		existence = state;
	}
	bool moving() {
		return isMoving;
	}
	int getRow() {
		return row;
	}
};

