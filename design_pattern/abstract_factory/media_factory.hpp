#pragma once

#include <iostream>
#include "media_player.hpp"
#include "media_decoder.hpp"

class MediaFactory {
public:
    virtual ~MediaFactory() = default;
    virtual MediaPlayer* createPlayer(const std::string& type) const = 0;
    virtual MediaDecoder* createDecoder(const std::string& type) const = 0;
};