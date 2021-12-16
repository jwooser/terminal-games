#include <memory>
#include <utility>
#include <string>
#include "game.h"
#include "customClock.h"
#include "halfSecondClock.h"
#include "floppybrad.h"

int main(int argc, char *argv[]) {
	for (int i = 0; i < argc; ++i) {
		std::string s = argv[i];
		if (s == "-fps") {
			Game game {std::make_unique<FloppyBrad>(), std::make_unique<CustomClock>(0.15)};
    		game.go();
			return 0;
		}
	}
    Game game {std::make_unique<FloppyBrad>(), std::make_unique<HalfSecondClock>()};
    game.go();
}

