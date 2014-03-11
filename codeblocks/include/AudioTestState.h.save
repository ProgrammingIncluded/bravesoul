#ifndef AUDIOTESTSTATE_H
#define AUDIOTESTSTATE_H

class AudioTestState : public State {
    public:
        AudioTestState();
        AudioTestState(Event **event);
        virtual ~AudioTestState();
        void pause();
        void resume();
        State* run();
    private:
        AudioHandler* audioH;
};

#endif // AUDIOTESTSTATE_H
