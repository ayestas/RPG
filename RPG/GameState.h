#pragma once
#ifndef GAME_STATE_H
#define GAME_STATE_H

#include "State.h"

class GameState :
    public State
{
public:
    GameState(sf::RenderWindow* window);
    ~GameState();

    //FUNCIONES
    void endState();

    void update(const float& dt);
    void render(sf::RenderTarget* target = nullptr);

private:

};

#endif // !GAME_STATE_H

