#pragma once

#include <iostream>

class MediaDecoder {
public:
    MediaDecoder() {
        std::cout << "MediaDecoder created." << std::endl;
    }

    virtual ~MediaDecoder() {
        std::cout << "MediaDecoder destroyed." << std::endl;
    }
    
    virtual void decode() const = 0;
    virtual std::string getType() const = 0;
};