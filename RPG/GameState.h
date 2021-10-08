#pragma once
#ifndef GAME_STATE_H
#define GAME_STATE_H

#include "State.h"

class GameState :
    public State
{
public:
    GameState(sf::RenderWindow* window, std::map<std::string, int>* supportedKeys, std::stack<State*>* statesP);
    ~GameState();

    //FUNCIONES
    void endState();

    void update(const float& dt);
    void updateInput(const float& dt);
    void render(sf::RenderTarget* target = nullptr);

private:
    Entity player;

    //Funciones
    void initKeybinds();
};

#endif // !GAME_STATE_H

