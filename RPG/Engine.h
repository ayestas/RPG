#pragma once
#ifndef ENGINE_H
#define ENGINE_H

#include "MainMenuState.h"

class Engine {
public:
	Engine();
	~Engine();

	//FUNCIONES
	void endApplication();

	void updateSFMLEvents();
	void updateDt();
	void update();
	void render();
	void run();

private:
	//VARIABLES
	sf::RenderWindow *window;
	sf::Event evento;
	std::vector<sf::VideoMode> videoModes;
	sf::ContextSettings windowSettings;

	bool fullscreen;

	sf::Clock dtClock;
	float dt;

	std::stack<State*> states;
	std::map<std::string, int> supportedKeys;

	//INICIALIZADORES
	void initVariables();
	void initWindow();
	void initStates();
	void initKeys();
};

#endif // !ENGINE_H

