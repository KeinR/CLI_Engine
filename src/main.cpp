#include <iostream>
#include <string>

#define AUE_BOUNDS_CHECKS

#include "main.h"

#define MARGIN 10

// stty size

namespace aue {
    const char *marginN = "\n\n\n\n\n\n\n\n\n\n";
    char **buffer;
    int bufferWidth;
    int bufferHeight;

    void init(const int &width, const int &height) {
        allocBuffer(width, height);
        updateWindowSize();
    }

    void update() {
        std::cout << marginN;
        for (int y = 0; y < bufferWidth; y++) {
            for (int x = 0; x < bufferHeight; x++) {
                std::cout << buffer[x][y];
            }
            std::cout << std::endl;
        }
    }

    void setWindowSize(const int &width, const int &height) {
        std::string s = "\x1b[8;";
        s += std::to_string(bufferHeight+MARGIN);
        s += ";";
        s += std::to_string(bufferWidth+MARGIN);
        s += "t";
        std::cout << s << std::endl;
        std::cout << s;
    }
}
