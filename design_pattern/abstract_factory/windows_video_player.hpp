#pragma once

#include <iostream>
#include "media_player.hpp"

class WindowsVideoPlayer : public MediaPlayer {
public:
    WindowsVideoPlayer() {
        std::cout << "WindowsVideoPlayer created." << std::endl;
    }

    ~WindowsVideoPlayer() {
        std::cout << "WindowsVideoPlayer destroyed." << std::endl;
    }

    void play() const override {
        std::cout << "Playing video on Windows." << std::endl;
    }

    void stop() const override {
        std::cout << "Stopping video on Windows." << std::endl;
    }

    std::string getType() const override {
        return "Windows Video Player";
    }
};