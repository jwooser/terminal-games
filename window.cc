#include "window.h"

Window::Window(int height, int width, int starty, int startx) :
theWindow {newwin(height, width, starty, startx)}
{ }

WINDOW* Window::getWindow() { return theWindow; }

void Window::erase() { werase(theWindow); }

void Window::refresh() { wrefresh(theWindow); }

void Window::drawBox() { box(theWindow, 0, 0); }

void Window::printCharAt(int x, int y, char c) {
    mvwaddch(theWindow, y, x, c);
}

void Window::printToLine(int line, string text) {
    wmove(theWindow, line, 0);
    wclrtoeol(theWindow);
    wprintw(theWindow, text.c_str());
}

Window::~Window() { delwin(theWindow); }
