#include "keyboard.h"

const map<string,Action> defaultMappings {
	{"w", Action::UP}, 
	{"a", Action::LEFT}, 
	{"s", Action::DOWN}, 
	{"d", Action::RIGHT},
	{" ", Action::SPACE},
	{"i", Action::ALT_UP}, 
	{"j", Action::ALT_LEFT}, 
	{"k", Action::ALT_DOWN}, 
	{"l", Action::ALT_RIGHT},
	{"q", Action::L_TRIGGER},
	{"e", Action::R_TRIGGER}
};

Keyboard::Keyboard() :
keyMappings {defaultMappings}
{ }

Keyboard::Keyboard(map<string,Action> keyMappings) :
keyMappings {keyMappings}
{ }

Action Keyboard::action() {
	string c {getch()};
	flushinp();
	return keyMappings[c];
}
