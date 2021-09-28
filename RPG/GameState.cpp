#include "GameState.h"

GameState::GameState(sf::RenderWindow* window)
	: State(window) {

}

GameState::~GameState() {

}

void GameState::endState() {
	std::cout << "ENDING GAME STATE!" << "\n";
}

void GameState::update(const float& dt) {
	this->updateKeybinds(dt);
	this->player.update(dt);
}

void GameState::updateKeybinds(const float& dt) {
	this->checkForQuit();
}

void GameState::render(sf::RenderTarget* target) {
	this->player.render(this->window);
}

