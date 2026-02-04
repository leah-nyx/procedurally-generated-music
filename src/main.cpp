#include <libremidi/libremidi.hpp>
#include <libremidi/writer.hpp>

#include <fstream>
#include <random>

std::random_device                           dev;
std::mt19937                                 rng(dev());
std::uniform_int_distribution<std::uint8_t>  noteGenerator {0, 72};
std::uniform_int_distribution<std::uint8_t>  velocityGenerator {0, 255};
std::uniform_int_distribution<std::uint16_t> durationGenerator {1, 4};

std::uint8_t getRandomNote() { return noteGenerator(rng); }

std::uint8_t getRandomVelocity() { return velocityGenerator(rng); }

std::uint16_t getRandomDuration() { return durationGenerator(rng); }

int main(int argc, char** argv)
{
    libremidi::writer writer;

    writer.tracks.push_back(libremidi::midi_track {
        libremidi::track_event {0, 0,
                                libremidi::channel_events::note_on(1, 45, 35)},
        libremidi::track_event {140, 0,
                                libremidi::channel_events::note_off(1, 45, 0)},
    });

    {
        std::uint16_t      tick  = getRandomDuration() * 280;
        std::uint8_t       track = 3; // magic number for now
        libremidi::message msg   = libremidi::channel_events::note_on(
            1, getRandomNote(), getRandomVelocity());

        writer.add_event(tick, track, msg);
    }

    std::ofstream output {"midi/output.mid", std::ios::binary};
    writer.write(output);
}
