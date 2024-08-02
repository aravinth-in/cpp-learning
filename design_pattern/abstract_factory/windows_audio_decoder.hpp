#pragma once

#include <iostream>
#include "media_decoder.hpp"

class WindowsAudioDecoder : public MediaDecoder {
public:
    WindowsAudioDecoder() {
        std::cout << "WindowsAudioDecoder created." << std::endl;
    }

    ~WindowsAudioDecoder() {
        std::cout << "WindowsAudioDecoder destroyed." << std::endl;
    }

    void decode() const override {
        std::cout << "Decoding audio on Windows." << std::endl;
    }

    std::string getType() const override {
        return "Windows Audio Decoder";
    }
};