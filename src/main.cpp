#include <libremidi/libremidi.hpp>
#include <libremidi/writer.hpp>

#include <fstream>
#include <random>

std::random_device dev;
std::mt19937 rng(dev());
std::uniform_int_distribution<std::int8_t> generator{0,72};

std::int8_t getRandomNotes()
{
    return generator(rng);
}

int main(int argc, char** argv)
{
    libremidi::writer writer;

    writer.tracks.push_back(
    libremidi::midi_track{
        libremidi::track_event{0, 0, libremidi::channel_events::note_on(1, 45, 35)},
        libremidi::track_event{140, 0, libremidi::channel_events::note_off(1, 45, 0)},
    }
    );

    {
        int tick = 500;
        int track = 3;
        libremidi::message msg = libremidi::channel_events::note_on(1, 45, 35);

        writer.add_event(tick, track, msg);
    }

    std::ofstream output{"midi/output.mid", std::ios::binary};
    writer.write(output);
}