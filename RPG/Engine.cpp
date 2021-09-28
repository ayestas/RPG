#include "Engine.h"

void Engine::initWindow() {
	
	std::ifstream ifs("Config/window.ini");

	std::string title = "None";
	sf::VideoMode window_bounds(800, 600);
	unsigned framerate_limit = 120;
	bool vertical_sync_enabled = false;

	if (ifs.is_open()) {
		std::getline(ifs, title);
		ifs >> window_bounds.width >> window_bounds.height;
		ifs >> framerate_limit;
		ifs >> vertical_sync_enabled;
	}

	ifs.close();

	this->window = new sf::RenderWindow(window_bounds, title);
	this->window->setFramerateLimit(framerate_limit);
	this->window->setVerticalSyncEnabled(vertical_sync_enabled);

}

void Engine::initStates() {
	this->states.push(new GameState(this->window));
}

//CONSTRUCTORES
Engine::Engine() {
	this->initWindow();
	this->initStates();
}

Engine::~Engine() {
	delete this->window;

	while (this->states.empty()) {
		delete this->states.top();
		this->states.pop();
	}
}

//FUNCIONES
void Engine::updateSFMLEvents() {
	while (this->window->pollEvent(this->evento)) {
		if (this->evento.type == sf::Event::Closed)
			this->window->close();
	}
}

void Engine::updateDt() {
	this->dt = this->dtClock.restart().asSeconds();
}

void Engine::update() {
	this->updateSFMLEvents();

	if (!this->states.empty())
		this->states.top()->update(this->dt);
}

void Engine::render() {
	this->window->clear();

	if (this->states.empty())
		this->states.top()->render();

	this->window->display();
}

void Engine::run() {
	while (this->window->isOpen()) {
		this->updateDt();
		this->update();
		this->render();
	}
}

