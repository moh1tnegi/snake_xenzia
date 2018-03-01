#ifndef GETCH
#define GETCH
#if defined (__unix__)
#include <termios.h>
#include <unistd.h>
#include <cstdio>
int getch() {
    struct termios oldt, newt;
    int ch;

    tcgetattr(STDIN_FILENO, &oldt);
    newt = oldt;
    newt.c_lflag &= ~(ICANON | ECHO);
    tcsetattr(STDIN_FILENO, TCSANOW, &newt);
    ch = getchar();
    tcsetattr(STDIN_FILENO, TCSANOW, &oldt);

    return ch;
}
#else
#   error getch is not available on the target system
#endif
#endif
