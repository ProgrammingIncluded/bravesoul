#ifndef AUDIOHANDLER_H_INCLUDED
#define AUDIOHANDLER_H_INCLUDED

#include <SFML/Audio.hpp>
#include <unordered_map>
#include <stdio.h>
#include <vector>
#include <memory>

//enum audio_t {sound, music};
///

class AudioHandler {
    public:
        static AudioHandler& getInstance();

        int loadSound(std::string filename);
        std::vector<int> loadSound(std::vector<std::string> filenames); // return list of indexes
        /// will throw exceptions if index off, music not loaded
        void playSound(int index);
        void loopSound(int index, bool b);
        void stopSound(int index);
        void playSound(int indexes[]);/// not sure if want ....
        void loopSound(int indexes[]);/// might do args list
        void stopSound(int indexes[]);
        void playMusic(std::string file); // music loops by default
        void playMusic();
        void pauseMusic();
        void loadMusic(std::string file);
        ///
        AudioHandler* setVolume(float volume);
        float getVolume();
        AudioHandler* setVolIncrements(float newInc);
        float getVolIncrements();
        float incVolume();
        float incVolume(float newInc);
        float decVolume();
        float decVolume(float decInc);
        void clearBuffer();

    protected:
        std::vector<std::shared_ptr<sf::Sound>> s;
        std::unordered_map<std::string, std::shared_ptr<sf::SoundBuffer>> b;
        float v;
        float vInc;
        sf::Music m;

    private:
        AudioHandler();
        AudioHandler(AudioHandler const&);
        void operator=(AudioHandler const&);
        ~AudioHandler();
};

#endif // AUDIOHANDLER_H_INCLUDED
