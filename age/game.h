#ifndef GAME_H
#define GAME_H

#include <queue>
#include <memory>
#include <utility>
#include "model.h"
#include "action.h"
#include "clock.h"
#include "keyboard.h"
#include "bitmap.h"
#include "point.h"

using std::queue;
using std::unique_ptr;
using std::pair;

class World;

class Game : public Model {
	unique_ptr<World> world;
	unique_ptr<Clock> clock;
	Action input;
	unsigned long int tick = 0;
	bool play = false;

	void gameLoop();
  public:
	Game(unique_ptr<World> world);
	Game(unique_ptr<World> world, unique_ptr<Clock> clock);
	Game(unique_ptr<World> world, unique_ptr<Keyboard> keyboard);
	Game(unique_ptr<World> world, unique_ptr<Clock> clock, unique_ptr<Keyboard> keyboard);
	Action getInput();
	unsigned long int getTick() const;
    void go();
	void stop();
	~Game();
};

#endif
	
