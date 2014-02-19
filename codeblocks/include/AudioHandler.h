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
        AudioHandler();
        ~AudioHandler();

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
        ///
        AudioHandler* setVolume(float volume);
        float getVolume();
        void clearBuffer();
    protected:
        //vector<SoundBuffer> b;
        std::vector<std::shared_ptr<sf::Sound>> s; // s for sound
        float v;// default 50, v for volume
        std::unordered_map<std::string, std::shared_ptr<sf::SoundBuffer>> m; // m for map, no f
        sf::Music a; // a for audio
};

#endif // AUDIOHANDLER_H_INCLUDED
