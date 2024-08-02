#pragma once

#include <iostream>
#include "media_player.hpp"

class MacOSVideoPlayer : public MediaPlayer {
public:
    MacOSVideoPlayer() {
        std::cout << "MacOSVideoPlayer created." << std::endl;
    }

    ~MacOSVideoPlayer() {
        std::cout << "MacOSVideoPlayer destroyed." << std::endl;
    }

    void play() const override {
        std::cout << "Playing video on MacOS." << std::endl;
    }

    void stop() const override {
        std::cout << "Stopping video on MacOS." << std::endl;
    }

    std::string getType() const override {
        return "MacOS Video Player";
    }
};