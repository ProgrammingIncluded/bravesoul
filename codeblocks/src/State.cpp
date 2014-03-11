#include "State.h"

State::State() {
    this->toArchive = false;
}

State::State(sf::Event **e) {
    event = e;
    this->toArchive = false;
}

State::~State() {
    //dtor
}

State* State::setEvent(sf::Event **e) {
    event = e;
    return this;
}

void State::pause() {

}

void State::resume() {

}
