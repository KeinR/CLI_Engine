#include <iostream>
#include <random>

#include "Tile.h"
#include "main.h"
#include "../src/ce.h"

#define WIDTH 30
#define HEIGHT 20

std::default_random_engine generator;
std::uniform_int_distribution<int> distribution(0, 9);

int rand() {
    return distribution(generator);
}

int main() {
    
    Frame frame(WIDTH, HEIGHT);
    setWindowSize(WIDTH, HEIGHT+5);
    frame.setBackground(219);
    int playerX = rand() * 3;
    int playerY = rand() * 2;

    // Agch
    Tile ***map = new Tile**[WIDTH];
    for (int x = 0; x < WIDTH; x++) {
        map[x] = new Tile*[HEIGHT];
        for (int y = 0; y < HEIGHT; y++) {
            if (rand() > 5) {
                map[x][y] = new EmptyTile();
            } else {
                map[x][y] = new GoldTile();
            }
        }
    }

    while (true) {
        frame.clear();
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
        frame.place(playerX, playerY, '$');
        frame.place(playerX-1, playerY, '#');
        frame.place(playerX+1, playerY, '#');
        frame.place(playerX, playerY-1, '#');
        frame.place(playerX, playerY+1, '#');
        frame.draw();
    }
}

int getKey() {
    if (getch() == 27) {
        if (getch() == 91) {
            switch (getch()) {
                case 65: // Up
                    return ;
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
}
