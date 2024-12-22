#include "Plants.h"
Plants::Plants(coordinates plantLocation)
{
	location.x = plantLocation.x;
	location.y = plantLocation.y;
	plant.create(19, 10);
	s_plant.setTexture(plant);
	s_plant.setPosition(location.x, location.y);
	lifetime = 10;
	//
	plantTime.asSeconds();
	plantClock.getElapsedTime();
}

Sprite& Plants::getSprite()
{
	return s_plant;
}

void Plants::setLifetime(int life)
{
	lifetime = life;
}

void Plants::setLocation(int x, int y)
{
	location.x = x;
	location.y = y;
}

coordinates& Plants::getPlantCoordinates()
{
	return location;
}




