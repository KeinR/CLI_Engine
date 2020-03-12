#include <iostream>
#include <string>

#include "Frame.h"
#include "core.h"

Frame::Frame() {
    bufferWidth = 0;
    bufferHeight = 0;
}

Frame::Frame(Frame &f) {
    allocBuffer(f.bufferWidth, f.bufferHeight);
    for (int y = 0; y < bufferHeight; y++) {
        for (int x = 0; x < bufferWidth; x++) {
            buffer[y][x] = f.buffer[y][x];
        }
    }
}

Frame::Frame(Frame &&f) {
    buffer = f.buffer;
    f.buffer = nullptr;
    bufferWidth = f.bufferWidth;
    bufferHeight = f.bufferHeight;
}

Frame::Frame(const int &width, const int &height) {
    allocBuffer(width, height);
}

Frame::~Frame() {
    dealcBuffer();
}

Frame &Frame::operator=(Frame &f) {
    if (f.bufferWidth != bufferWidth || f.bufferHeight != bufferHeight) {
        resize(f.bufferWidth, f.bufferHeight);
    }
    for (int y = 0; y < bufferHeight; y++) {
        for (int x = 0; x < bufferWidth; x++) {
            buffer[y][x] = f.buffer[y][x];
        }
    }
    return *this;
}

Frame &Frame::operator=(Frame &&f) {
    dealcBuffer();
    buffer = f.buffer;
    f.buffer = nullptr;
    bufferWidth = f.bufferWidth;
    bufferHeight = f.bufferHeight;
    return *this;
}

void Frame::swap(Frame &f) {
    char **temp_b = buffer;
    buffer = f.buffer;
    f.buffer = temp_b;

    int temp_i;
    temp_i = bufferWidth;
    bufferWidth = f.bufferWidth;
    f.bufferWidth = temp_i;
    temp_i = bufferHeight;
    bufferHeight = f.bufferHeight;
    f.bufferHeight = temp_i;
}

void Frame::allocBuffer(const int &width, const int &height) {
    bufferWidth = width;
    bufferHeight = height;
    buffer = new char*[height];
    for (int y = 0; y < bufferHeight; y++) {
        buffer[y] = new char[width];
        for (int x = 0; x < bufferWidth; x++) {
            buffer[y][x] = bg;
        }
    }
}

void Frame::dealcBuffer() {
    if (bufferHeight > 0) { // Safeguard
        delete[] buffer[0];
        for (int y = 1; y < bufferHeight; y++) {
            delete[] buffer[y];
        }
        delete[] buffer;
    }
}

void Frame::resize(const int &width, const int &height) {
    dealcBuffer();
    allocBuffer(width, height);
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
    #endif // end AUE_BOUNDS_CHECKS
    buffer[y][x] = c;
}

void Frame::clear() {
    for (int y = 0; y < bufferHeight; y++) {
        for (int x = 0; x < bufferWidth; x++) {
            buffer[y][x] = bg;
        }
    }
}

void Frame::draw() {
    system("clear"); // Fuck off it works alright?
    for (int y = 0; y < bufferHeight; y++) {
        std::cout.write(buffer[y], bufferWidth);
        std::cout << std::endl;
    }
}

void Frame::setBackground(const unsigned char &c) {
    bg = c;
}
