#ifndef GAMEVIEW_H
#define GAMEVIEW_H

#include "view.h"
#include <memory>
#include <vector>
#include <queue>
#include <ncurses.h>
#include "window.h"
#include "game.h"
#include "point.h"
#include "bitmap.h"

using std::vector;
using std::queue;
using std::pair;
using std::unique_ptr;
using std::string;

class GameView : public View {
	Window screen;
	Window status;

	void drawBitmap(Point p, const Bitmap *b);
  public:
	GameView();
	void update(int line, string text) override;
	void update(queue<pair<Point, const Bitmap*>> &render) override;
	void refreshView() override;
};

#endif
