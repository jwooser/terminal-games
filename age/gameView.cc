#include "gameView.h"
#include "properties.h"

GameView::GameView() : 
screen {Properties::BORDER_HEIGHT, Properties::BORDER_WIDTH, 0, 0},
status {Properties::STATUS_LINES, Properties::BORDER_WIDTH, Properties::BORDER_HEIGHT, 0}
{
	screen.drawBox();
}

void GameView::drawBitmap(Point p, const Bitmap *b) {
    for (const auto &pixel : b->get()) {
        Point offset = p + pixel.p;
        screen.printCharAt(offset.x, offset.y, pixel.c);
    }
}

void GameView::update(int line, string text) {
	status.printToLine(line, text);
}

void GameView::update(queue<pair<Point, const Bitmap*>> &render) {
    screen.erase();
    while (!render.empty()) {
        auto &a = render.front();
        drawBitmap(a.first, a.second);
        render.pop();
    }
    screen.drawBox();
}

void GameView::refreshView() {
    status.refresh();
    screen.refresh();
}
