#ifndef MODEL_H
#define MODEL_H

#include <memory>
#include <vector>
#include <queue>
#include <utility>
#include "controller.h"
#include "view.h"
#include "point.h"
#include "bitmap.h"

using std::queue;
using std::pair;
using std::unique_ptr;
using std::string;

enum Action;

class Model {
	unique_ptr<View> view;
	unique_ptr<Controller> control;
  protected:
    void updateGraphics(queue<pair<Point, const Bitmap*>> &render);
	void refreshView();
	void addView(unique_ptr<View> v);
	void addController(unique_ptr<Controller> c);
	Action getAction();
  public:
  	void updateStatus(int line, string text);
	virtual ~Model() = default;
};

#endif
