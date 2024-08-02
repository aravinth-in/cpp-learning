#include <iostream>

#include "windows_factory.hpp"
#include "macos_factory.hpp"


void testFactory(const MediaFactory& factory, const std::string& type) {
    MediaPlayer* player = factory.createPlayer(type);
    MediaDecoder* decoder = factory.createDecoder(type);

    if (player && decoder) {
        std::cout << "Testing " << player->getType() << " and " << decoder->getType() << ":" << std::endl;
        player->play();
        decoder->decode();
        player->stop();
    }

    delete player;
    delete decoder;
}

int main() {
    MediaFactory* factory = new WindowsFactory();
    testFactory(*factory, "audio");
    testFactory(*factory, "video");
    delete factory;

    factory = new MacOSFactory();
    testFactory(*factory, "audio");
    testFactory(*factory, "video");
    delete factory;

    return 0;
}


/*
OUTPUT
WindowsFactory created.
WindowsAudioPlayer created.
WindowsAudioDecoder created.
Testing Windows Audio Player and Windows Audio Decoder:
Playing audio on Windows.
Decoding audio on Windows.
Stopping audio on Windows.
WindowsAudioPlayer destroyed.
WindowsAudioDecoder destroyed.
WindowsVideoPlayer created.
WindowsVideoDecoder created.
Testing Windows Video Player and Windows Video Decoder:
Playing video on Windows.
Decoding video on Windows.
Stopping video on Windows.
WindowsVideoPlayer destroyed.
WindowsVideoDecoder destroyed.
WindowsFactory destroyed.
MacOSFactory created.
MacOSAudioPlayer created.
MacOSAudioDecoder created.
Testing MacOS Audio Player and MacOS Audio Decoder:
Playing audio on MacOS.
Decoding audio on MacOS.
Stopping audio on MacOS.
MacOSAudioPlayer destroyed.
MacOSAudioDecoder destroyed.
MacOSVideoPlayer created.
MacOSVideoDecoder created.
Testing MacOS Video Player and MacOS Video Decoder:
Playing video on MacOS.
Decoding video on MacOS.
Stopping video on MacOS.
MacOSVideoPlayer destroyed.
MacOSVideoDecoder destroyed.
MacOSFactory destroyed.
*/