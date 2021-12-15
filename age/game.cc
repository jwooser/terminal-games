#include "game.h"
#include <ncurses.h>
#include "gameView.h"
#include "keyboard.h"
#include "halfSecondClock.h"
#include "world.h"

using std::make_unique;

namespace {
    void initncurses() {
		initscr();
        cbreak();
        noecho();
        nodelay(stdscr, TRUE);
        curs_set(0);
		refresh();
    }
    
    void endncurses() { endwin(); }
}

// ********************************************************************************
// CTORS/DTOR
// ********************************************************************************

Game::Game(unique_ptr<World> world):
world {std::move(world)},
clock {make_unique<HalfSecondClock>()}
{
	initncurses();
    addView(make_unique<GameView>());
    addController(make_unique<Keyboard>());
}

Game::Game(unique_ptr<World> world, unique_ptr<Clock> clock):
world {std::move(world)},
clock {std::move(clock)}
{
	initncurses();
    addView(make_unique<GameView>());
    addController(make_unique<Keyboard>());
}

Game::Game(unique_ptr<World> world, unique_ptr<Keyboard> keyboard):
world {std::move(world)},
clock {make_unique<HalfSecondClock>()}
{
	initncurses();
    addView(make_unique<GameView>());
    addController(std::move(keyboard));
}

Game::Game(unique_ptr<World> world, unique_ptr<Clock> clock, unique_ptr<Keyboard> keyboard):
world {std::move(world)},
clock {std::move(clock)}
{
	initncurses();
    addView(make_unique<GameView>());
    addController(std::move(keyboard));
}

Game::~Game() { endncurses(); }

// ********************************************************************************
// GAMELOOP/GAME METHODS
// ********************************************************************************

void Game::gameLoop() {
    while (play) {
        if (clock->tick()) {
            input = getAction();
            world->doProcess(*this, {});
            updateGraphics(world->getRender({}));
			refreshView();
            ++tick;
        }
    }
}

Action Game::getInput() { return input; }

unsigned long int Game::getTick() const { 
    return tick;
}

void Game::go() {
    if (!play) {
        play = true;
        world->doInitialize(*this, {});
        updateGraphics(world->getRender({}));
        refreshView();
        gameLoop();
    }
}

void Game::stop() {
	play = false;
}
