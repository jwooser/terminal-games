#ifndef KEYBOARD_H
#define KEYBOARD_H

#include <map>
#include <ncurses.h>
#include "controller.h"
#include "action.h"

using std::map;
using std::string;

class Keyboard : public Controller {
	map<string,Action> keyMappings;

	Action action() override;
  public:
  	Keyboard();
	Keyboard(map<string,Action> keyMappings);
};

#endif
