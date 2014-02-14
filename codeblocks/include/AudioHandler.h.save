#ifndef AUDIOHANDLER_H_INCLUDED
#define AUDIOHANDLER_H_INCLUDED

#include <SFML/Audio.hpp>
#include <stdio.h>
#include <vector>

//enum audio_t {sound, music};
namespace std; ///

class AudioHandler {
    public:
        AudioHandler();
        ~AudioHandler();

        int loadSound(string& filename);
        vector<int> loadSound(vector<string> filenames); // return list of indexes
        /// will throw exceptions if index off, music not loaded
        void playSound(int index);
        void loopSound(int index);
        void stopSound(int index);
        void playSound(int[] indexes);/// not sure if want ....
        void loopSound(int[] indexes);/// might do args list
        void stopSound(int[] indexes);
        void playMusic(string& file); // music loops by default
        void playMusic();
        void pauseMusic();
        ///
        AudioHandler setVolume(float volume);
        float getVolume();
        void clearBuffer();
    protected:
        //vector<SoundBuffer> b;
        vector<sf::Sound> s; // s for sound
        float v;// default 50, v for volume
        unordered_map<string, sf::SoundBuffer> m; // m for map
        sf::Music a; // a for audio
};

#endif // AUDIOHANDLER_H_INCLUDED
