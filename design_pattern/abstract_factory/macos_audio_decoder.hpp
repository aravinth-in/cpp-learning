#pragma once

#include <iostream>
#include "media_decoder.hpp"

class MacOSAudioDecoder : public MediaDecoder {
public:
    MacOSAudioDecoder() {
        std::cout << "MacOSAudioDecoder created." << std::endl;
    }

    ~MacOSAudioDecoder() {
        std::cout << "MacOSAudioDecoder destroyed." << std::endl;
    }

    void decode() const override {
        std::cout << "Decoding audio on MacOS." << std::endl;
    }

    std::string getType() const override {
        return "MacOS Audio Decoder";
    }
};