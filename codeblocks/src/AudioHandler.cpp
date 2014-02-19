#include "AudioHandler.h"

using namespace std;
typedef std::shared_ptr<sf::SoundBuffer> sbPtr;
typedef std::shared_ptr<sf::Sound> sdPtr;

AudioHandler::AudioHandler() {
    v = 50;
    m.reserve(100); // initial set
}

AudioHandler::~AudioHandler() {
    // missing destructors, will add
}

AudioHandler* AudioHandler::setVolume(float v) {
    this->v = v;
    return this;
}

float AudioHandler::getVolume() {
    return this->v;
}

int AudioHandler::loadSound(string file) {
    unordered_map<string, shared_ptr<sf::SoundBuffer>>::iterator it = m.find(file);

    if (it != m.end()) {
        sdPtr newSnd(new sf::Sound(*it->second));
        s.push_back(newSnd);
    }
    else {
        sbPtr sb(new sf::SoundBuffer());

        if(!sb->loadFromFile(file)) {
            return -1;
        }

        if(!(m[file] = sb)) { /// check to rehash
            return -1; /// placeholder for file exception
        }

        sdPtr snd(new sf::Sound(*m[file]));
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
    if (!a.openFromFile(file)) {
        return; /// placeholder for file exception
    }
    playMusic();

    return;
}

void AudioHandler::playMusic() {
    a.setVolume(this->v);
    a.setLoop(true);
    a.play();

    return;
}

void AudioHandler::clearBuffer() {
    /*for (sf::Sound& si : s) { // dont know if i need this
        delete si;
    }
    for (pair<string, sf::SoundBuffer>& mi : m) {
        delete mi.second;
        // shouldnt have to create new strings for the hash, 90% sure
    }*/
    s.clear();
    m.clear();

}
