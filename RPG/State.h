#pragma once
#ifndef STATE_H
#define STATE_H

#include <iostream>
#include <ctime>
#include <cstdlib>
#include <fstream>
#include <sstream>
#include <stack>
#include <map>
#include <vector>

#include "SFML/System.hpp"
#include "SFML/Window.hpp"
#include "SFML/Audio.hpp"
#include "SFML/Graphics.hpp"
#include "SFML/Network.hpp"

class State {
public:
	State (sf::RenderWindow* window);
	~State ();

	virtual void endState() = 0;

	virtual void update(const float& dt) = 0;
	virtual void render(sf::RenderTarget* target = nullptr) = 0;

private:
	
	sf::RenderWindow* window;
	std::vector<sf::Texture> textures;


};

#endif // !STATE_H

