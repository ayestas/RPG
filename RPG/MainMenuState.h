#pragma once
#ifndef MAIN_MENU_STATE_H
#define MAIN_MENU_STATE_H

#include "GameState.h"
#include "Button.h"

class MainMenuState :
    public State {

public:
    MainMenuState(sf::RenderWindow* window, std::map<std::string, int>* supportedKeys, std::stack<State*>* statesP);
    ~MainMenuState();

    //FUNCIONES
    void endState();

    void update(const float& dt);
    void updateInput(const float& dt);
    void updateBotones();
    void renderBotones(sf::RenderTarget* target = nullptr);
    void render(sf::RenderTarget* target = nullptr);

private:
    //Funciones
    void initKeybinds();
    void initFonts();
    void initBoton();

    //Variables
    sf::RectangleShape background;
    sf::Font fontText;

    std::map<std::string, Button*> botones;
};



#endif // !MAIN_MENU_STATE_H
