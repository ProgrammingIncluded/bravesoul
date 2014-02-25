#include "AudioHandler.h"

using namespace std;
typedef std::shared_ptr<sf::SoundBuffer> sbPtr;
typedef std::shared_ptr<sf::Sound> sdPtr;

AudioHandler::AudioHandler() {
    v = 30;
    vInc = 5;
    b.reserve(100); // initial set
}

AudioHandler::~AudioHandler() {
    s.clear();
    b.clear();
}

AudioHandler* AudioHandler::setVolume(float v) {
    if(v < 0)
        v = 0;
    else if(v > 100)
        v = 100;

    this->v = v;
    m.setVolume(this->v);

    return this;
}

float AudioHandler::getVolume() {
    return this->v;
}

float AudioHandler::incVolume() {
    v += vInc;
    if(v > 100)
        v = 100;

    return this->v;
}

float AudioHandler::incVolume(float newInc) {
    vInc = newInc;
    incVolume();

    return this->v;
}

float AudioHandler::decVolume() {
    v -= vInc;
    if(v < 0)
        v = 0;

    return this->v;
}

float AudioHandler::decVolume(float newInc) {
    vInc = newInc;
    decVolume()

    return this->v;
}

AudioHandler* AudioHandler::setVolIncrements(float newInc) {
    vInc = newInc;

    return this;
}

float AudioHandler::getVolIncrements() {
    return this->vInc;
}

int AudioHandler::loadSound(string file) {
    unordered_map<string, shared_ptr<sf::SoundBuffer>>::iterator it = b.find(file);

    if (it != b.end()) {
        sdPtr newSnd(new sf::Sound(*it->second));
        s.push_back(newSnd);
    } else {
        sbPtr sb(new sf::SoundBuffer());

        if(!sb->loadFromFile(file)) {
            return -1;
        }

        if(!(b[file] = sb)) { /// check to rehash
            return -1; /// placeholder for file exception
        }

        sdPtr snd(new sf::Sound(*b[file]));
        s.push_back(snd);
    }

    return s.size() - 1; // returns index, not actually the size
}

vector<int> AudioHandler::loadSound(vector<string> files) {
    vector<int> n;
    for (string file : files) {
        n.push_back(loadSound(file));
    }

    return n;
}

void AudioHandler::playSound(int i) {
    s[i]->setVolume(this->v);
    s[i]->play();

    return;
}

void AudioHandler::loopSound(int i, bool b) {
    s[i]->setLoop(b);
    playSound(i);

    return;
}

void AudioHandler::stopSound(int i) {
    s[i]->stop();
    s[i]->setLoop(false);

    return;
}

void AudioHandler::playMusic(string file) {
    if(m.getStatus() == sf::SoundSource::Playing) {
        m.pause();
    }
    loadMusic(file);
    playMusic();

    return;
}

void AudioHandler::playMusic() {
    if(m.getStatus() == sf::SoundSource::Playing) {
        return; // dont run another play() while playing
    }
    m.setVolume(this->v);
    m.setLoop(true);
    m.play();

    return;
}

void AudioHandler::pauseMusic() {
    m.pause();

    return;
}

void AudioHandler::loadMusic(string file) {
    if (!m.openFromFile(file)) {
        return; /// placeholder for file exception
    }

    return;
}

void AudioHandler::clearBuffer() {
    s.clear();
    b.clear();
}
