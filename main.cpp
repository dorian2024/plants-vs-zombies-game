#include <SFML/Graphics.hpp>
#include <ctime>
#include <iostream>
#include "Game.h"
#include "Lawnmower.h"
#include "Coordinates.h"
#include "Zombie.h"
using namespace sf;
using namespace std;
//static members of game
const int Game::boxPixels = 50;
const int Game::xResolution = 1900;
const int Game::yResolution = 1000;
const int Game::grassPixelsX = 250;
const int Game::xRows = xResolution / boxPixels;
const int Game::yRows = yResolution / boxPixels;
int main() {
	Game game;
	return 0;
}