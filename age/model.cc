#include "model.h"

void Model::updateGraphics(queue<pair<Point, const Bitmap*>> &render) {
	view->update(render);
}

void Model::updateStatus(int line, string text) {
	view->update(line, text);
}

void Model::refreshView() {
	view->refreshView();
}

void Model::addView(std::unique_ptr<View> v) {
	view = std::move(v);
}

void Model::addController(unique_ptr<Controller> c) {
	control = std::move(c);
}

Action Model::getAction() {
	return control->getAction();
}

