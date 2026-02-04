#include <procedurally-generated-music/player.h>

// std::random_device                           dev;
// std::mt19937                                 rng(dev());
// std::uniform_int_distribution<std::uint8_t>  noteGenerator {0, 72};
// std::uniform_int_distribution<std::uint8_t>  velocityGenerator {0, 255};
// std::uniform_int_distribution<std::uint16_t> durationGenerator {1, 4};

// std::uint8_t getRandomNote() { return noteGenerator(rng); }

// std::uint8_t getRandomVelocity() { return velocityGenerator(rng); }

// std::uint16_t getRandomDuration() { return durationGenerator(rng); }

int main()
{
    ProcGenMusic::Player player("output");

    player.AddNote(0, 10, 40, 40);

    return 0;
}
