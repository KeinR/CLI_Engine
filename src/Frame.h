#ifndef FRAME_H_INCLUDED
#define FRAME_H_INCLUDED

// Not thread safe

#define AUE_BOUNDS_CHECKS

#ifdef AUE_BOUNDS_CHECKS
struct aueException {
    std::string message;
};
#endif // end AUE_BOUNDS_CHECKS
class Frame {
    char **buffer;
    int bufferWidth;
    int bufferHeight;
    unsigned char bg = ' ';
    void dealcBuffer();
    void allocBuffer(const int &width, const int &height);
    public:
    Frame();
    Frame(Frame &f);
    Frame(Frame &&f);
    Frame(const int &width, const int &height);
    ~Frame();
    Frame &operator=(Frame &f);
    Frame &operator=(Frame &&f);
    void swap(Frame &f);
    void place(const int &x, const int &y, const char &c);
    void resize(const int &width, const int &height);
    void clear();
    void draw();
    void setBackground(const unsigned char &c);
};

#endif // end FRAME_H_INCLUDED
