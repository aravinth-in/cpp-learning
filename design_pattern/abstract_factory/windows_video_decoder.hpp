#pragma once

#include <iostream>
#include "media_decoder.hpp"

class WindowsVideoDecoder : public MediaDecoder {
public:
    WindowsVideoDecoder() {
        std::cout << "WindowsVideoDecoder created." << std::endl;
    }

    ~WindowsVideoDecoder() {
        std::cout << "WindowsVideoDecoder destroyed." << std::endl;
    }

    void decode() const override {
        std::cout << "Decoding video on Windows." << std::endl;
    }

    std::string getType() const override {
        return "Windows Video Decoder";
    }
};
