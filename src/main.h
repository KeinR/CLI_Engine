#include <string>

namespace aue {
    #ifdef AUE_BOUNDS_CHECKS
    struct aueException {
        std::string message;
    };
    #endif // end AUE_BOUNDS_CHECKS

    void init(const int &width, const int &height);
    void update();
    void resize(const int &width, const int &height);
    void allocBuffer(const int &width, const int &height);
    void dealcBuffer();
    void updateWindowSize();
    void place(const int &x, const int &y, const char &c);
}
