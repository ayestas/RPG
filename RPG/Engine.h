#pragma once
#ifndef ENGINE_H
#define ENGINE_H

#include "GameState.h"

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

	sf::Clock dtClock;
	float dt;

	std::stack<State*> states;

	//INICIALIZADORES
	void initWindow();
	void initStates();
};

#endif // !ENGINE_H

