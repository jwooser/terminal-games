#ifndef WINDOW_H
#define WINDOW_H
#include "ncurses.h"
#include <string>

using std::string;

class Window {
    WINDOW *theWindow;
  public:
    Window(int height, int width, int starty, int startx);
	WINDOW* getWindow();
    void erase();
    void refresh();
    void drawBox();
    void printCharAt(int x, int y, char c);
    void printToLine(int line, string text);
    ~Window();
};

#endif
