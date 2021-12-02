#pragma once
#ifndef STATE_H
#define STATE_H

#include "Entity.h"

class State {

private:


public:
	State (sf::RenderWindow* window, std::map<std::string, int>* supportedKeys, std::stack<State*>* statesP);
	~State ();

	const bool& getQuit() const;

	virtual void checkForQuit();
	virtual void endState() = 0;

	virtual void update(const float& dt) = 0;
	virtual void updateInput(const float& dt) = 0;
	virtual void updateMousePosition();
	virtual void render(sf::RenderTarget* target = nullptr) = 0;

protected:
	
	std::stack<State*>* statesP;

	sf::RenderWindow* window;
	std::map<std::string, int>* supportedKeys;
	std::map<std::string, int> keybinds;
	bool quit;

	//Recursos
	std::vector<sf::Texture> textures;
	sf::Vector2i mousePosScreen;
	sf::Vector2i mousePosWindow;
	sf::Vector2f mousePosView;

	//Funciones
	virtual void initKeybinds() = 0;


};

#endif // !STATE_H

