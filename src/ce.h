#ifndef AUE_H_INCLUDED
#define AUE_H_INCLUDED

void setWindowSize(const int &width, const int &height);
int getch();

struct aueException {
    std::string message;
};
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

#endif // end AUE_H_INCLUDED
