#include "floppybrad.h"
#include <memory>
#include <cstdlib>
#include <ctime>
#include "action.h"
#include "point.h"
#include "pipe.h"
#include "properties.h"
#include <string>
#include <vector>

void FloppyBrad::initialize(Game &game) {
    srand(time(NULL));
    toggleSolidBorder(false);
    brad = queueSpawn(std::make_unique<Brad>());
    brad->setPosition(15, 10);
	game.updateStatus(0, "Score: 0");
	game.updateStatus(1, "Highscore: 0");
}

void FloppyBrad::process(Game &game) {
	game.updateStatus(0, "Score: " + std::to_string(brad->getScore()));
	if (brad->getScore() > high) {
		high = brad->getScore();
		game.updateStatus(1, "Highscore: " + std::to_string(high));
	}
    if (game.getTick() % 30 == 0) {
        int t = 2 + rand() % 14;
        queueSpawn(std::make_unique<Pipe>())->setSize(t, true);
        queueSpawn(std::make_unique<Pipe>())->setSize(Properties::BORDER_HEIGHT - t - 6, false);
    }
	if (brad->isFlaggedDestroy()) {
		queueDestroyAll();
		brad = queueSpawn(std::make_unique<Brad>());
    	brad->setPosition(15, 10);
	}
	if (game.getInput() == Action::L_TRIGGER) game.stop();
}


