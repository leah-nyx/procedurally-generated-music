/**
 * @file player.cpp
 * @brief abstracts some of the library for my laziness
 * @see player.cpp
 */

#pragma once

#include <libremidi/writer.hpp>

#include <cstdint>
#include <fstream>
#include <string>

namespace ProcGenMusic
{
    class Player
    {
    private:
        libremidi::writer writer;

        std::ofstream output;

        std::uint8_t track;

        std::string file;

    public:
        Player(std::string filename);
        void AddNote(std::int32_t time, std::uint16_t duration,
                     std::uint8_t note, std::uint8_t velocity);
    };
} // namespace ProcGenMusic
