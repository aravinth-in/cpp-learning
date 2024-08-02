#pragma once

#include <iostream>

class MediaDecoder {
public:
    virtual ~MediaDecoder() = default;
    virtual void decode() const = 0;
    virtual std::string getType() const = 0;
};