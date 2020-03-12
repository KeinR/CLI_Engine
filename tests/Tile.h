#ifndef TILE_H_INCLUDED
#define TILE_H_INCLUDED

#include <functional>

class Tile {
    std::function<void()> *event;
    bool done = false;
    public:
    Tile();
    void open();
};

#endif
