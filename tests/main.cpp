#include <iostream>
#include <random>

#include "Tile.h"
#include "main.h"
#include "../src/ce.h"

#define WIDTH 80
#define HEIGHT 20

// std::default_random_engine generator;
// std::uniform_int_distribution<int> distribution(0, 9);

int playerX = 1;// rand() * 3;
int playerY = 1;// rand() * 2;
Tile map[WIDTH][HEIGHT];
Frame frame(WIDTH, HEIGHT);

int main() {

    setWindowSize(WIDTH, HEIGHT+5);
    frame.setBackground(219);

    update();
    while (true) {
        if (getch() == 27) {
            if (getch() == 91) {
                switch (getch()) {
                    case 65: // Up
                        if (playerY-1 >= 0) {
                            playerY--;
                            map[playerX][playerY].open();
                        }
                        break;
                    case 66: // Down
                        if (playerY+1 < HEIGHT) {
                            playerY++;
                            map[playerX][playerY].open();
                        }
                        break;
                    case 67: // Right
                        if (playerX+1 < WIDTH) {
                            playerX++;
                            map[playerX][playerY].open();
                        }
                        break;
                    case 68: // Left
                        if (playerX-1 >= 0) {
                            playerX--;
                            map[playerX][playerY].open();
                        }
                        break;
                }
            }
        }
        update();
    }
}

int rand() {
    // return distribution(generator);
    return 0;
}

void update() {
    frame.clear();
    frame.place(playerX, playerY, '$');
    frame.place(playerX-1, playerY, '#');
    frame.place(playerX+1, playerY, '#');
    frame.place(playerX, playerY-1, '#');
    frame.place(playerX, playerY+1, '#');
    frame.draw();
}

/*
if (getch() == 27) {
    if (getch() == 91) {
        switch (getch()) {
            case 65: // Up
                if (playerY-1 >= 0) {
                    playerY--;
                    map[playerX][playerY]->open();
                }
                break;
            case 66: // Down
                if (playerY+1 < HEIGHT) {
                    playerY++;
                    map[playerX][playerY]->open();
                }
                break;
            case 67: // Right
                if (playerX+1 < WIDTH) {
                    playerX++;
                    map[playerX][playerY]->open();
                }
                break;
            case 68: // Left
                if (playerY-1 >= 0) {
                    playerX--;
                    map[playerX][playerY]->open();
                }
                break;
        }
    }
}
*/
