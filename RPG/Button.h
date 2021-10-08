#pragma once
#ifndef BUTTON_H
#define BUTTON_H

#include <iostream>
#include <ctime>
#include <cstdlib>
#include <sstream>

#include "SFML/System.hpp"
#include "SFML/Window.hpp"
#include "SFML/Audio.hpp"
#include "SFML/Graphics.hpp"

enum boton_States {BTN_IDDLE = 0, BTN_PRSSED, BTN_HOVER};

class Button {

public:
	Button(float x, float y, float width, float height, sf::Font* font, 
		std::string text, sf::Color iddleColor, sf::Color hoverColor, sf::Color activeColor,
		sf::Color textColor);
	~Button();

	//Accesories
	const bool isPressed() const;

	//Funciones
	void render(sf::RenderTarget* target);
	void update(sf::Vector2f mousePos);

private:
	sf::RectangleShape botonShape;
	sf::Font* botonFont;
	sf::Text botonText;

	sf::Color iddleColor;
	sf::Color hoverColor;
	sf::Color activeColor;

	short unsigned botonState;
};

#endif // !BUTTON_H
