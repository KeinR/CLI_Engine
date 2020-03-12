#include <iostream>
#include <functional>
#include <random>

#include "main.h"
#include "Tile.h"

std::default_random_engine generator;
std::uniform_int_distribution<int> distribution(0, 1);

std::function<void()> none = []() {
    std::cout << "There's nothing here..." << std::endl;
};

std::function<void()> gold = []() {
    std::cout << "You found gold!" << std::endl;
};

Tile::Tile() {
    if (distribution(generator)) {
        event = &gold;
    } else {
        event = &none;
    }
}

void Tile::open() {
    if (!done) {
        done = true;
        (*event)();
    } else {
        std::cout << "We've already been here :/" << std::endl;
    }
}
