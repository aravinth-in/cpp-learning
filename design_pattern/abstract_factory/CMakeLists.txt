cmake_minimum_required(VERSION 3.10)

set(HEADER_FILES
    macos_audio_decoder.hpp
    macos_audio_player.hpp
    macos_factory.hpp
    macos_video_decoder.hpp
    macos_video_player.hpp
    media_decoder.hpp
    media_factory.hpp
    media_player.hpp
    windows_audio_decoder.hpp
    windows_audio_player.hpp
    windows_factory.hpp
    windows_video_decoder.hpp
    windows_video_player.hpp
)

set(SOURCE_FILES
    main.cpp
)

add_executable(abstract_factory_executable ${HEADER_FILES} ${SOURCE_FILES})
