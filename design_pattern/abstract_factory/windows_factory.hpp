#pragma once

#include <iostream>

#include "media_factory.hpp"
#include "windows_audio_player.hpp"
#include "windows_video_player.hpp"
#include "windows_audio_decoder.hpp"
#include "windows_video_decoder.hpp"


class WindowsFactory : public MediaFactory {
public:
    WindowsFactory() {
        std::cout << "WindowsFactory created." << std::endl;
    }

    ~WindowsFactory() {
        std::cout << "WindowsFactory destroyed." << std::endl;
    }

    MediaPlayer* createPlayer(const std::string& type) const override {
        if (type == "audio") {
            return new WindowsAudioPlayer();
        } else if (type == "video") {
            return new WindowsVideoPlayer();
        }
        return nullptr;
    }

    MediaDecoder* createDecoder(const std::string& type) const override {
        if (type == "audio") {
            return new WindowsAudioDecoder();
        } else if (type == "video") {
            return new WindowsVideoDecoder();
        }
        return nullptr;
    }
};
