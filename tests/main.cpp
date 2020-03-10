
#include "../src/main.h"

int main() {
    aue::init(10, 10);
    aue::place(1, 1, 'e');
    aue::place(2, 2, 'e');
    aue::place(3, 3, 'e');
    aue::place(4, 4, 'e');
    aue::place(5, 5, 'e');
    aue::update();
}
