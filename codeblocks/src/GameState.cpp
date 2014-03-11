#include "GameState.h"

GameState::GameState() {
    //ctor
}

GameState::~GameState() {
    //dtor
}

void GameState::display() {
    State *cur;
    State *next;
    cur->resume();
    while((cur = s.top()) != nullptr) {
        cur->run();
        if((next = cur->run()) != nullptr) {
            s.push(next);
            cur->pause();
        } else {
            s.pop();
        }
    }
}
