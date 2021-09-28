#pragma once
#ifndef STATE_H
#define STATE_H

#include "Entity.h"

class State {
public:
	State (sf::RenderWindow* window);
	~State ();

	const bool& getQuit() const;

	virtual void checkForQuit();
	virtual void endState() = 0;

	virtual void update(const float& dt) = 0;
	virtual void updateKeybinds(const float& dt) = 0;
	virtual void render(sf::RenderTarget* target = nullptr) = 0;

protected:
	
	sf::RenderWindow* window;
	std::vector<sf::Texture> textures;
	bool quit;

};

#endif // !STATE_H

