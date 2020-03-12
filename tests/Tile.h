#ifndef TILE_H_INCLUDED
#define TILE_H_INCLUDED

class Tile {
    public:
    Tile() = default;
    virtual void open() = 0;
};

class EmptyTile: public Tile {
    public:
    EmptyTile();
    void open() override;
};

class GoldTile: public Tile {
    public:
    GoldTile();
    void open() override;
};


#endif
