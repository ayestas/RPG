#include "Engine.h"

void Engine::initVariables() {
	this->window = nullptr;
	this->fullscreen = false;
	this->dt = 0.f;
}

void Engine::initWindow() {
	
	std::ifstream ifs("Config/window.ini");
	this->videoModes = sf::VideoMode::getFullscreenModes();

	std::string title = "None";
	sf::VideoMode window_bounds = sf::VideoMode::getDesktopMode();
	bool fullscreen = false;
	unsigned framerate_limit = 120;
	bool vertical_sync_enabled = false;
	unsigned antialiasing_lvl = 0;

	if (ifs.is_open()) {
		std::getline(ifs, title);
		ifs >> window_bounds.width >> window_bounds.height;
		ifs >> fullscreen;
		ifs >> framerate_limit;
		ifs >> vertical_sync_enabled;
		ifs >> antialiasing_lvl;
	}

	ifs.close();

	this->fullscreen = fullscreen;
	this->windowSettings.antialiasingLevel = antialiasing_lvl;

	if(this->fullscreen)
		this->window = new sf::RenderWindow(window_bounds, title, sf::Style::Fullscreen, windowSettings);
	else
		this->window = new sf::RenderWindow(window_bounds, title, 
			 sf::Style::Titlebar | sf::Style::Close, windowSettings);

	this->window->setFramerateLimit(framerate_limit);
	this->window->setVerticalSyncEnabled(vertical_sync_enabled);

}

void Engine::initKeys() {
	std::ifstream ifs("Config/supportedKeys.ini");

	if (ifs.is_open()) {
		std::string key = "";
		int key_value = 0;

		while (ifs >> key >> key_value) {
			this->supportedKeys[key] = key_value;
		}
	}

	ifs.close();

	//PROBABLY REMOVED DEBUG
	for  (auto i : this->supportedKeys) {
		std::cout << i.first << " " << i.second << "\n";
	}
}

void Engine::initStates() {
	this->states.push(new MainMenuState(this->window, &this->supportedKeys, &this->states));
}

//CONSTRUCTORES
Engine::Engine() {
	this->initWindow();
	this->initKeys();
	this->initStates();
}

Engine::~Engine() {
	delete this->window;

	while (!this->states.empty()) {
		delete this->states.top();
		this->states.pop();
	}
}

void Engine::endApplication() {
	std::cout << "ENDING APP!!" << "\n";
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

	if (!this->states.empty()) {
		this->states.top()->update(this->dt);

		if (this->states.top()->getQuit()) {

			this->states.top()->endState();
			delete this->states.top();
			this->states.pop();
		}
	}
	else {
		this->endApplication();
		this->window->close();
	}
	
}

void Engine::render() {
	this->window->clear();

	if (!this->states.empty())
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

