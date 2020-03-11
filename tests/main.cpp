#include <iostream>

#include "../src/aue.h"

int main() {
    // setWindowSize(30, 20);
    setFrameMargin(30);
    Frame frame(30, 20);
    frame.setBackground(178);
    frame.clear();
    frame.place(1, 1, 'e');
    frame.place(2, 2, 'e');
    frame.place(3, 3, 'e');
    frame.place(4, 4, 'e');
    frame.place(5, 5, 'e');
    frame.draw();
    int a = getch();
    int b = getch();
    std::cout << a << b << std::endl;
    // getch();
}
