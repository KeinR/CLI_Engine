
// Not thread safe

class Frame {
    char **buffer;
    void dealcBuffer();
    void allocBuffer();
    public:
    Frame();
    ~Frame();
    void place(const int &x, const int &y, const char &c);
    void resize(const int &width, const int &height);
    void clear();
    Frame &operator=(Frame &f);
}

