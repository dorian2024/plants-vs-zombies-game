#include "Game.h"
Game::Game() {
	gameRows = new int* [xRows];
	for (int i = 0; i < xRows; i++)
	{
		gameRows[i] = new int[yRows];
	}
	plantType = 0;
	currentLevel = 1;
	BeginnersGarden level1(time, sunlight);
	ZombieOutskirts level2(time, sunlight);
	SunflowerFields level3(time, sunlight);
	FoggyForest level4(time, sunlight);
	NighttimeSiege level5(time, sunlight);
	RooftopRampage level6(time, sunlight);
	currentSunBalance = 0;
	//level = &level1;
	level = &level3;
	
	////////////////////////////////////   SPRITES   /////////////////////////////////////////////////////
	//background
	day.loadFromFile("C:/Users/wajiz.pk/Desktop/urgh/SFML/Images/background.png");
	s_background.setTexture(day);
	s_background.setPosition(0, 0);

	night.loadFromFile("C:/Users/wajiz.pk/Desktop/urgh/SFML/Images/nightbackground.png");
	s_nightBackground.setTexture(night);
	s_nightBackground.setPosition(0, 0);

	startScreen.loadFromFile("C:/Users/wajiz.pk/Desktop/urgh/SFML/Images/start.png");
	s_startScreen.setTexture(startScreen);
	s_startScreen.setPosition(0, 0);

	pauseScreen.loadFromFile("C:/Users/wajiz.pk/Desktop/urgh/SFML/Images/pausescreen.png");
	s_pauseScreen.setTexture(pauseScreen);
	s_pauseScreen.setPosition(0, 0);

	instructions.loadFromFile("C:/Users/wajiz.pk/Desktop/urgh/SFML/Images/instructions.png");
	s_instructions.setTexture(instructions);
	s_instructions.setPosition(0, 0);

	//icons
	menu.loadFromFile("C:/Users/wajiz.pk/Desktop/urgh/SFML/Images/menuicon.png");
	s_menu.setTexture(menu);
	s_menu.setPosition(32 * boxPixels, boxPixels);

	sunCount.loadFromFile("C:/Users/wajiz.pk/Desktop/urgh/SFML/Images/suncount.png");
	s_sunCount.setTexture(sunCount);
	s_sunCount.setPosition(7 * boxPixels, 1* boxPixels);
	////////////////////////////////////////////////////////////////////////////////////////////////////////
	font.loadFromFile("C:/Users/wajiz.pk/Desktop/urgh/SFML/Images/Crima.ttf");
	scoreText.setFont(font);
	scoreText.setCharacterSize(60);
	scoreText.setFillColor(sf::Color::Black);
	scoreText.setStyle(sf::Text::Bold);
	scoreText.setPosition(420, 43);

	//delete
	plant.loadFromFile("C:/Users/wajiz.pk/Desktop/urgh/SFML/Images/snowpea.png");
	s_plant.setTexture(plant);
	isFirstClick = true;
	dragPlant = false;
	plantChosen = -1;
	//delete]]]
	
	//dont add anything after this
	gamePlay();
}
const int Game::getBoxPixels() {
	return boxPixels;
}
void Game::gamePlay() {
	//window declaration
	sf::RenderWindow window(sf::VideoMode(xResolution, yResolution), "PlantsVsZombies", sf::Style::Close | sf::Style::Titlebar);
	window.setSize(sf::Vector2u(xResolution, yResolution));
	window.setPosition(sf::Vector2i(0, 0));

	//game started?
	bool gameStarted = false;
	bool gamePause = false;
	bool instructions = false;
	//time control
	bool restart = false;
	while (window.isOpen())
	{
		
		Event event;
		while (window.pollEvent(event))
		{
			if (event.type == Event::Closed)
				window.close();
		}
		if (gameStarted == false && gamePause == false && !instructions) {
			window.draw(s_startScreen);
		}
		else if (gamePause == true && !instructions) { //if game paused
				window.draw(s_pauseScreen);
				sf::Event event;
				sf::Keyboard key;
				window.pollEvent(event);
				if (key.isKeyPressed(sf::Keyboard::L)){
					gamePause = false;
				}
				if (key.isKeyPressed(sf::Keyboard::I)) {
					instructions = true;
				}
				if (key.isKeyPressed(sf::Keyboard::R)) {
					restart = true;
					gamePause = false;
				}
		}
		else if (instructions) {
			window.draw(s_instructions);
			sf::Event event;
			sf::Keyboard key;
			window.pollEvent(event);
			if (key.isKeyPressed(sf::Keyboard::Enter) || key.isKeyPressed(sf::Keyboard::Space)) {
				instructions = false;
			}
		}
		else {
			if (restart == true) {
				restart = false;
				int levelNum = level->getLevel();
				switch (levelNum) {
				case 1:
					level = new BeginnersGarden(time, sunlight);
					break;
				case 2:
					level = new ZombieOutskirts(time, sunlight);
					break;
				case 3:
					level = new SunflowerFields(time, sunlight);
					break;
				case 4:
					level = new FoggyForest(time, sunlight);
					break;
				case 5:
					level = new NighttimeSiege(time, sunlight);
					break;
				case 6:
					level = new RooftopRampage(time, sunlight);
					break;
				}
			}

			scoreText.setString(std::to_string(currentSunBalance));

			level->drawBackground(window);
			window.draw(s_menu);
			window.draw(s_sunCount);
			window.draw(scoreText);
			level->drawIcons(window);
			
			
			//////////////TEST AREA ////////////////// PROCEED WITH CAUTION /////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

		
			coordinates placePlant;
			Mouse plantClick;
			Event plantEvent;
			window.pollEvent(plantEvent);
			//if left button pressed start
			if (plantClick.isButtonPressed(sf::Mouse::Left)){
				if (plantClick.getPosition(window).x >= 150 && plantClick.getPosition(window).x <= 300 && plantClick.getPosition(window).y >= 100 && isFirstClick) {
					plantClock.restart();
					cout << "smth\n";
					plantType = level->getPlantType(plantClick, window);
					if(plantType!= 0)
					s_plant = level->getPlantSprite(plantType);
					if (isFirstClick) {
						isFirstClick = false;
					}
					dragPlant = true;
				}

				level->checkSunClick(window, plantClick, currentSunBalance);
			}
			//level->drawSuns(window);
			//if button is released
			if (time.plantClickRegulator(plantClock)) {
				isFirstClick = true;
			}
			//to drag
					// \works perfectly fine
			if (dragPlant) {
				//check to see if grid coordinates
				if (plantClick.getPosition(window).x >= 540 && plantClick.getPosition(window).x <= 1600 && plantClick.getPosition(window).y >= 240 && plantClick.getPosition(window).y <= 940)
				{
					//s_plant = level->getPlantSprite(plantType);
				//	s_plant.setPosition(500, 500);
					s_plant.setPosition(plantClick.getPosition(window).x - boxPixels, plantClick.getPosition(window).y - boxPixels);
					window.draw(s_plant);

					Mouse secondPlantClick;
					// \works perfectly fine

					////////////////////////////// need to figure these out
					if (secondPlantClick.isButtonPressed(sf::Mouse::Left)) {
						PlantSecondClick(plantClick, plantType, window, s_plant);
						//int x = secondPlantClick.getPosition().x;
						//int y = secondPlantClick.getPosition().y;

					//	Sprite sunflower2 = s_sunflower;
					//	sunflower2.setPosition(x - 50, y - 50);
					//	window.draw(sunflower2);
					}
				}
			}

			Mouse plantClickOnGrid;
			Event plantEvent2;
			window.pollEvent(plantEvent2);
			if (plantClickOnGrid.isButtonPressed(sf::Mouse::Left) && plantClickOnGrid.getPosition(window).x >= 540 && plantClickOnGrid.getPosition(window).x <= 1600 && plantClickOnGrid.getPosition(window).y >= 240 && plantClickOnGrid.getPosition(window).y <= 940 && dragPlant) {
				/*placePlant.x = plantClick.getPosition(window).x;
				placePlant.y = plantClick.getPosition(window).y;
				s_plant.setPosition(placePlant.x, placePlant.y);*/
				if(plantType != 0)
				//PlantSecondClick(plantClick, plantType, window, s_plant);
				dragPlant = false;
			}
			level->drawPlants(window);
			level->generateSuns(window);
			level->moveSuns(window);
			level->plantFunctions(window);
			Mouse mouse;
			if (mouse.isButtonPressed(mouse.Button::Left)) {
				int mousePositionX = mouse.getPosition(window).x;
				int mousePositionY = mouse.getPosition(window).y;
				if (mousePositionX >= 32 * boxPixels && mousePositionX <= 36 * boxPixels && mousePositionY >= boxPixels && mousePositionY <= 2 * boxPixels) {
					gamePause = true;
				}
			}
			/// <zombie stuff>
			sf::Time zombieSpeed = zombieClock.getElapsedTime();
			level->drawLawnmowers(window);
			level->zombiesCreation();
			level->moveZombies(window);
			level->drawZombie(window);
			level->checkLawnmowerZombieCollision(window);
			level->checkBulletZombieCollision();
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


		}
		window.display();
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) {
			gameStarted = true;
		}

	}
}
bool Game::PlantSecondClick(Mouse& m, int plantType, RenderWindow& window, Sprite& Sprite)
{
	cout << "plant second plant type: " << plantType << endl;
	int numRows = 5;
	int numCols = 9;
	int PlantRow = 0;
	int PlantColumn = 0;
	if (m.isButtonPressed(sf::Mouse::Left))
	{
		if (m.getPosition().x - 50 >= 11 * boxPixels &&
			m.getPosition().x - 50 <= 32 * boxPixels &&
			m.getPosition().y - 50 >= 5 * boxPixels &&
			m.getPosition().y - 50 <= 19 * boxPixels)//grid range

		{

			//to check plant grid
			/*for (int i = 0; i < numRows; i++) {
				for (int j = 0; j < numCols; j++) {
					s_sunflower.setPosition(xGridPixels[j] + 550, i*140 + 240);
					window.draw(s_sunflower);
				}
			}*/
			coordinates plantPosition;


			for (int i = 0; i <= numRows; i++) {
				for (int j = 0; j <= numCols; j++) {
					if (m.getPosition(window).y - 240 >= (i - 1) * 140 && m.getPosition(window).y - 240 <= i * 140) {
						plantPosition.y = 100 + (i * 140);
						if (m.getPosition(window).x >= xGridPixels[j] - 550 && m.getPosition(window).x - 550 <= xGridPixels[j + 1]) {
							plantPosition.x = xGridPixels[j] + 550;
						//	s_plant.setPosition(plantPosition.x, plantPosition.y);
							PlantRow = i;
							PlantColumn = j;
							level->plantsCreation(plantPosition, plantType, PlantRow, PlantColumn, window, currentSunBalance);
						//	window.draw(s_plant);
							return true;
						}
					}
				}
			}		
		}
		else
		{
			return false;
		}
	}
}
void Game::createSuns(sf::RenderWindow& window, sf::Clock& sunClock) {

}
Game::~Game() {
	for (int i = 0; i < xRows; i++) {
		delete[] gameRows[i];
	}
	delete[] gameRows;
}