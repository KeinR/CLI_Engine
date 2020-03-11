#include <iostream>
#include <string>

#include "Frame.h"
#include "core.h"

// stty size

int marginCount = 0;
char *marginN;

void printMargin() {
    std::cout.write(marginN, marginCount);
}

void setFrameMargin(const int &n) {
    if (marginCount != 0) {
        delete[] marginN;
    }
    marginCount = n;
    marginN = new char[n];
    std::fill_n(marginN, n, '\n');
}

void setWindowSize(const int &width, const int &height) {
    std::string s = "\x1b[8;";
    s += std::to_string(height);
    s += ";";
    s += std::to_string(width);
    s += "t";
    std::cout << s;
}

#if (!defined(WIN32) && !defined(_WIN32) && !defined(__WIN32)) || defined(__CYGWIN__) // platform check

    #include <unistd.h>
    #include <termios.h>
    #include <cstdio>

int getch() {
    char buf = 0;
    struct termios old = {0};
    fflush(stdout);
    if(tcgetattr(0, &old) < 0)
        perror("tcsetattr()");
    old.c_lflag &= ~ICANON;
    old.c_lflag &= ~ECHO;
    old.c_cc[VMIN] = 1;
    old.c_cc[VTIME] = 0;
    if(tcsetattr(0, TCSANOW, &old) < 0)
        perror("tcsetattr ICANON");
    if(read(0, &buf, 1) < 0)
        perror("read()");
    old.c_lflag |= ICANON;
    old.c_lflag |= ECHO;
    if(tcsetattr(0, TCSADRAIN, &old) < 0)
        perror("tcsetattr ~ICANON")
    return buf;
}

#endif // End platform check
