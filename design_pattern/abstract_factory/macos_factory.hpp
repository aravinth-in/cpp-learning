#pragma once

#include <iostream>

#include "media_factory.hpp"
#include "macos_audio_player.hpp"
#include "macos_video_player.hpp"
#include "macos_audio_decoder.hpp"
#include "macos_video_decoder.hpp"


class MacOSFactory : public MediaFactory {
public:
    MacOSFactory() {
        std::cout << "MacOSFactory created." << std::endl;
    }

    ~MacOSFactory() {
        std::cout << "MacOSFactory destroyed." << std::endl;
    }

    MediaPlayer* createPlayer(const std::string& type) const override {
        if (type == "audio") {
            return new MacOSAudioPlayer();
        } else if (type == "video") {
            return new MacOSVideoPlayer();
        }
        return nullptr;
    }

    MediaDecoder* createDecoder(const std::string& type) const override {
        if (type == "audio") {
            return new MacOSAudioDecoder();
        } else if (type == "video") {
            return new MacOSVideoDecoder();
        }
        return nullptr;
    }
};