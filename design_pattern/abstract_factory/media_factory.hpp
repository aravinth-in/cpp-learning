#pragma once

#include <iostream>
#include "media_player.hpp"
#include "media_decoder.hpp"

class MediaFactory {
public:
    MediaFactory() {
        std::cout << "MediaFactory created." << std::endl;
    }

    virtual ~MediaFactory() {
        std::cout << "MediaFactory destroyed." << std::endl;
    }
    
    virtual MediaPlayer* createPlayer(const std::string& type) const = 0;
    virtual MediaDecoder* createDecoder(const std::string& type) const = 0;
};