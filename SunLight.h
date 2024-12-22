#pragma once
#include "Coordinates.h"
#include <SFML/Graphics.hpp>
#include <ctime>
#include <iostream>
using namespace sf;
using namespace std;

class SunLight
{
protected:
  /*coordinates startPosition[];
    coordinates endPosition[];
    coordinates currentPosition[];*/
    coordinates position;
    bool plantSun;
    bool exists;
    int currencyWeight;
    Sprite s_suns;
    Texture suns;

   
    float sunSpeed;
    sf::Clock movementClock;
    sf::Time movementTime;

public:
    SunLight();
    void createSun();
    void moveSun(sf::RenderWindow& window);
    void drawSun(sf::RenderWindow& window);
    coordinates& getPosition();
    void sunExistence(bool newState) {
        exists = newState;
    }
    void createPlantSun(coordinates& plantPosition);
    int getCurrencyWeight();
};