#pragma once

#include <iostream>
#include "media_player.hpp"

class MacOSAudioPlayer : public MediaPlayer {
public:
    MacOSAudioPlayer() {
        std::cout << "MacOSAudioPlayer created." << std::endl;
    }

    ~MacOSAudioPlayer() {
        std::cout << "MacOSAudioPlayer destroyed." << std::endl;
    }

    void play() const override {
        std::cout << "Playing audio on MacOS." << std::endl;
    }

    void stop() const override {
        std::cout << "Stopping audio on MacOS." << std::endl;
    }

    std::string getType() const override {
        return "MacOS Audio Player";
    }
};