#pragma once

#include "GameState.h"
#include <vector>
#include <SDL.h>

class GameStateMachine
{
public:
    GameStateMachine() = default;
    ~GameStateMachine() = default;

    void pushState(GameState *state);
    void changeState(GameState *state);
    void popState();

    void update();
    void render();

    std::string GetStateID() const;

private:
    std::vector<GameState *> m_gameStates;
};
