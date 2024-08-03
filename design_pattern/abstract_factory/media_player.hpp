#pragma once

#include <iostream>

class MediaPlayer {
public:
    MediaPlayer() {
        std::cout << "MediaPlayer created." << std::endl;
    }

    virtual ~MediaPlayer() {
        std::cout << "MediaPlayer destroyed." << std::endl;
    }
    
    virtual void play() const = 0;
    virtual void stop() const = 0;
    virtual std::string getType() const = 0;
};