#include <cmath>
#include <iostream>
#include <random>


std::random_device dev;
std::mt19937 rng(dev());
std::uniform_real_distribution<std::double_t> generator{0,1};

std::double_t getRandom()
{
    return generator(rng);
}

int main(int argc, char** argv)
{
    getRandom();
}