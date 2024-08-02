#pragma once

#include <iostream>

class MediaPlayer {
public:
    virtual ~MediaPlayer() = default;
    virtual void play() const = 0;
    virtual void stop() const = 0;
    virtual std::string getType() const = 0;
};