#include "Game.h"
#include "State.h"

Game::Game() {
    isRunning = true;
}

Game::~Game() {
    //dtor
}

void Game::Init(const char* title, int width, int height, bool fullscreen){

// Will add this and remove Ren intialization in state.

}

void Game::Cleanup(){
    while(!states.empty()){
        states.back()->CleanUp();
        states.pop_back();
    }
}

bool Game::Running() {
    return isRunning;
}

void Game::Quit(){
    isRunning = false;
}

void Game::ChangeState(State* state){
    if(!states.empty()){
        states.back()->CleanUp();
        states.pop_back();
    }

    states.push_back(state);
    states.back()->Init();
}

void Game::PushState(State* state) {
    if(!states.empty()){
        states.back()->Pause();
    }

    states.push_back(state);
    states.back()->Init();
}

void Game::PopState() {
    if(!states.empty()){
        states.back()->CleanUp();
        states.pop_back();
    }

    if(!states.empty()) {
        states.back()->Resume();
    }
}

void Game::HandleEvents(){
    states.back()->HandleEvents(this);
}

void Game::Update(){
    states.back()->Update(this);
}

void Game::Draw(){
    states.back()->Draw(this);
}
