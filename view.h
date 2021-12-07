#ifndef VIEW_H
#define VIEW_H

#include <string>
#include <vector>
#include <queue>
#include <utility>
#include "point.h"
#include "bitmap.h"

using std::string;
using std::vector;
using std::queue;
using std::pair;

class View {
  public:
	virtual ~View() = default;
	virtual void update(queue<pair<Point, const Bitmap*>> &render) = 0;
	virtual void update(int line, const string text) = 0;
	virtual void refreshView() = 0;
};

#endif
