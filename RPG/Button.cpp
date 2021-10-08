#include "Button.h"


Button::Button(float x, float y, float width, float height, sf::Font* font, std::string text, sf::Color iddleColor, sf::Color hoverColor, sf::Color activeColor, sf::Color textColor) {
	this->botonState = BTN_IDDLE;
	
	this->botonShape.setSize(sf::Vector2f(width, height));
	this->botonShape.setPosition(sf::Vector2f(x, y));
	
	this->botonFont = font;
	this->botonText.setFont(*this->botonFont);
	this->botonText.setString(text);
	this->botonText.setFillColor(textColor);
	this->botonText.setCharacterSize(16);
	this->botonText.setPosition(
		this->botonShape.getPosition().x + (this->botonShape.getGlobalBounds().width / 2.f) - this->botonText.getGlobalBounds().width / 2.f,
		this->botonShape.getPosition().y + (this->botonShape.getGlobalBounds().height / 2.f) - this->botonText.getGlobalBounds().height / 2.f);
	
	this->iddleColor = iddleColor;
	this->hoverColor = hoverColor;
	this->activeColor = activeColor;

	this->botonShape.setFillColor(this->iddleColor);
}

Button::~Button() {

}

const bool Button::isPressed() const {
	if (this->botonState == BTN_PRSSED)
		return true;

	return false;
}

void Button::update(sf::Vector2f mousePos) {
	//Update the booleans for Hover and Pressed :)
	//Iddle
	this->botonState = BTN_IDDLE;

	//Hover

	if (this->botonShape.getGlobalBounds().contains(mousePos)) {
		this->botonState = BTN_HOVER;

		if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
			//Pressed
			this->botonState = BTN_PRSSED;
		}
	}

	switch (this->botonState) {
	case BTN_IDDLE:
		this->botonShape.setFillColor(this->iddleColor);
		break;

	case BTN_HOVER:
		this->botonShape.setFillColor(this->hoverColor);
		break;

	case BTN_PRSSED:
		this->botonShape.setFillColor(this->activeColor);
		break;
	default:
		this->botonShape.setFillColor(sf::Color::Red);
		break;
	}
}


void Button::render(sf::RenderTarget* target) {
	target->draw(this->botonShape);
	target->draw(this->botonText);
}
