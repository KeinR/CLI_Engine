#ifndef MAIN_H_INCLUDED
#define MAIN_H_INCLUDED

void setFrameMargin(const int &n);
void printMargin();
void setWindowSize(const int &width, const int &height);

#if defined(WIN32) || defined(_WIN32) || defined(__WIN32) && !defined(__CYGWIN__) // platform check

    #include <conio.h>

#else

int getch();

#endif // End platform check

#endif // end MAIN_H_INCLUDED
