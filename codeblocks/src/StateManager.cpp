#include "StateManager.h"
#include "State.h"

StateManager::StateManager() {
    isRunning = true;
}

StateManager::~StateManager() {
    //dtor
}

void StateManager::Init(const char* title, int width, int height, bool fullscreen){

// Will add this and remove Ren intialization in state.

}

void StateManager::Cleanup(){
    while(!states.empty()){
        states.back()->CleanUp();
        states.pop_back();
    }
}

bool StateManager::Running() {
    return isRunning;
}

void StateManager::Quit(){
    isRunning = false;
}

void StateManager::ChangeState(State* state){
    if(!states.empty()){
        states.back()->CleanUp();
        states.pop_back();
    }

    states.push_back(state);
    states.back()->Init(this);
}

void StateManager::PushState(State* state) {
    if(!states.empty()){
        states.back()->Pause();
    }

    states.push_back(state);
    states.back()->Init(this);
}

void StateManager::PopState() {
    if(!states.empty()){
        states.back()->CleanUp();
        states.pop_back();
    }

    if(!states.empty()) {
        states.back()->Resume();
    }
}

void StateManager::HandleEvents(){
    states.back()->HandleEvents(this);
}

void StateManager::Update(){
    states.back()->Update(this);
}

void StateManager::Draw(){
    states.back()->Draw(this);
}
