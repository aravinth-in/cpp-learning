#pragma once

#include <iostream>
#include "media_decoder.hpp"

class MacOSVideoDecoder : public MediaDecoder {
public:
    MacOSVideoDecoder() {
        std::cout << "MacOSVideoDecoder created." << std::endl;
    }

    ~MacOSVideoDecoder() {
        std::cout << "MacOSVideoDecoder destroyed." << std::endl;
    }

    void decode() const override {
        std::cout << "Decoding video on MacOS." << std::endl;
    }

    std::string getType() const override {
        return "MacOS Video Decoder";
    }
};