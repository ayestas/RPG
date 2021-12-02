#include "MainMenuState.h"

MainMenuState::MainMenuState(sf::RenderWindow* window, std::map<std::string, int>* supportedKeys, std::stack<State*>* statesP)
	:State(window, supportedKeys, statesP) {

	this->initVariables();
	this->initBackground();
	
	this->initFonts();
	this->initKeybinds();
	this->initBoton();

}

MainMenuState::~MainMenuState() {
	auto it = this->botones.begin();
	for (it = this->botones.begin(); it != this->botones.end(); ++it) {
		delete it->second;
	}
}

void MainMenuState::endState() {
	std::cout << "ENDING MAIN MENU STATE!" << "\n";
}

void MainMenuState::update(const float& dt) {
	this->updateMousePosition();
	this->updateInput(dt);
	this->updateBotones();
}

void MainMenuState::updateInput(const float& dt) {
	this->checkForQuit();

}

void MainMenuState::updateBotones() {
	for (auto& it : this->botones) {
		it.second->update(this->mousePosView);
	}

	if (this->botones["GAME_STATE_BOTON"]->isPressed()) {
		this->statesP->push(new GameState(this->window, this->supportedKeys, this->statesP));

	}

	if (this->botones["EXIT_STATE_BOTON"]->isPressed()) {
		this->quit = true;
	}
}

void MainMenuState::renderBotones(sf::RenderTarget* target) {
	for (auto& it : this->botones) {
		it.second->render(target);
	}
}

void MainMenuState::render(sf::RenderTarget* target) {
	if (!target)
		target = this->window;

	target->draw(this->background);
	this->renderBotones(target);
}

void MainMenuState::initVariables() {

}

void MainMenuState::initBackground() {
	this->background.setSize(sf::Vector2f(static_cast<float>(this->window->getSize().x),
				static_cast<float>(this->window->getSize().y)));

	if (!this->bgTexture.loadFromFile("Resources/Images/BG_MainMenu.png")) {
		throw"ERROR!!! al cargar imagen 'BG_MainMenu.png'!!";
	}

	this->background.setTexture(&this->bgTexture);
}

void MainMenuState::initKeybinds() {
	std::ifstream ifs("Config/mainMenuStateKeybinds.ini");

	if (ifs.is_open()) {
		std::string key = "";
		std::string key2 = "";

		while (ifs >> key >> key2) {
			this->keybinds[key] = this->supportedKeys->at(key2);
		}
	}

	ifs.close();

}

void MainMenuState::initFonts() {
	if (!this->fontText.loadFromFile("Fonts/normal_Text.ttf")) {
		throw("ERROR CON FONT DE TEXTO!!!");
	}

}

void MainMenuState::initBoton() {
	this->botones["GAME_STATE_BOTON"] = new Button(380, 300, 150, 50, &this->fontText, "START GAME",
		sf::Color::Color(250, 179, 169), sf::Color::Color(237, 107, 134), sf::Color::Color(70, 50, 57),
		sf::Color::Color(70, 50, 57));
	
	this->botones["EXIT_STATE_BOTON"] = new Button(380, 375, 150, 50, &this->fontText, "EXIT GAME",
		sf::Color::Color(250, 179, 169), sf::Color::Color(237, 107, 134), sf::Color::Color(70, 50, 57),
		sf::Color::Color(70, 50, 57));
}
