#pragma once

#include <iostream>
#include "media_player.hpp"

class WindowsAudioPlayer : public MediaPlayer {
public:
    WindowsAudioPlayer() {
        std::cout << "WindowsAudioPlayer created." << std::endl;
    }

    ~WindowsAudioPlayer() {
        std::cout << "WindowsAudioPlayer destroyed." << std::endl;
    }

    void play() const override {
        std::cout << "Playing audio on Windows." << std::endl;
    }

    void stop() const override {
        std::cout << "Stopping audio on Windows." << std::endl;
    }

    std::string getType() const override {
        return "Windows Audio Player";
    }
};