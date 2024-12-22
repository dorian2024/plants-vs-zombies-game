#pragma once
#include <SFML/Graphics.hpp>
#include <ctime>
#include <iostream>
#include "Lawnmower.h"
#include "Coordinates.h"
#include "Zombie.h"
#include "Levels.h"
#include "SimpleZombie.h"
#include "GameTime.h"
#include "SunLight.h"
using namespace sf;
using namespace std;
//level 1
class BeginnersGarden :
    public Levels
{
private:
    sf::Clock zombieClock;
    sf::Time zombieSpeed = zombieClock.getElapsedTime();

    Texture peaShooterIcon;
    Sprite s_peaShooterIcon;

    Texture sunflowerIcon;
    Sprite s_sunflowerIcon;

public:
    BeginnersGarden(GameTime& gameTime, SunLight* sunlight);
    void drawIcons(sf::RenderWindow& window) override;
    void zombiesCreation() override;
    int getPlantType(Mouse mouse, sf::RenderWindow& window) override;
};
//this shouldnt be here
    /*void zombieMovement(sf::RenderWindow& window) {
        /// <zombie stuff>
        for (int i = 0; i < simpleZombiesCount; i++) {
            simpleZb[i].moveZombie(5, window, zombieClock, zombieSpeed);
            if (simpleZb[i].exists()) {
                window.draw(simpleZb[i].getZombieSprite());
            }
        }
    }*/