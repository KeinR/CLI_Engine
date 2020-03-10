#include <algorithm>
#include "Frame.h"

Frame::Frame() {

}

Frame::~Frame() {
    dealcBuffer();
}

Frame &Frame::operator=(Frame &f) {
    dealcBuffer();
    std::copy();
}

Frame &Frame::operator=(Frame &&f) {
    
}

void Frame::allocBuffer(const int &width, const int &height) {
    bufferWidth = width;
    bufferHeight = height;
    buffer = new char*[width];
    for (int x = 0; x < bufferWidth; x++) {
        buffer[x] = new char[height];
        for (int y = 0; y < height; y++) {
            buffer[x][y] = '\0';
        }
    }
}

void Frame::dealcBuffer() {
   for (int x = 0; x < bufferWidth; x++) {
        delete[] buffer[x];
    }
    delete[] buffer;
}

void Frame::resize(const int &width, const int &height) {
    dealcBuffer();
    allocBuffer(width, height);
    updateWindowSize();
}

void Frame::place(const int &x, const int &y, const char &c) {
    #ifdef AUE_BOUNDS_CHECKS
    if (x >= bufferWidth || x < 0) {
        aueException e = {std::string("X index ").append(std::to_string(x)).append(" out of bounds")};
        throw e;
    }
    if (y >= bufferHeight || y < 0) {
        aueException e = {std::string("Y index ").append(std::to_string(y)).append(" out of bounds")};
        throw e;
    }
    #endif // end BOUNDS_CHECKS
    buffer[x][y] = c;
}

void clear() {
    for (int x = 0; x < bufferWidth; x++) {
        for (int y = 0; y < height; y++) {
            buffer[x][y] = '\0';
        }
    }
}
