#pragma once
#include "PlantFactory.h"
class WallnutFactory: public PlantFactory
{
protected:
	float lifetime;
public:
	WallnutFactory();
	Sprite& getPlantSprite() override;
	void createPlant(coordinates& plantLocation, int row, int column, sf::RenderWindow& window, int& balance) override;
};

