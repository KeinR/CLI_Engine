#include <iostream>

#include "main.h"
#include "Tile.h"

EmptyTile::EmptyTile() {
}

void EmptyTile::open() {
    std::cout << "There's nothing here..." << std::endl;
}

GoldTile::GoldTile() {
}

void GoldTile::open() {
    std::cout << "You found gold!" << std::endl;
}
