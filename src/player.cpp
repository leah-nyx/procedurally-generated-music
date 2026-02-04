/**
 * @file player.cpp
 * @brief abstracts some of the library for my laziness
 */

#include <procedurally-generated-music/player.h>

#include <libremidi/writer.hpp>

#include <cstdint>
#include <fstream>
#include <string>

namespace ProcGenMusic
{

    Player::Player(std::string filename)
    {
        track = 3; // magic number copied from documentation

        output.open("midi/" + filename + ".mid");
    }

    void Player::AddNote(std::int32_t time, std::uint16_t duration,
                         std::uint8_t note, std::uint8_t velocity)
    {
        writer.tracks.push_back(libremidi::midi_track {
            libremidi::track_event {
                time, track,
                libremidi::channel_events::note_on(1, note, velocity)},
            libremidi::track_event {
                time + duration, track,
                libremidi::channel_events::note_off(1, note, velocity)},
        });
    }
} // namespace ProcGenMusic
