#include <memory>
#include <utility>
#include <string>
#include "game.h"
#include "customClock.h"
#include "arlg.h"

int main(int argc, char *argv[]) {
	std::unique_ptr<ARLG> arlg = std::make_unique<ARLG>();
	if (argc > 1) {
		int l = std::stoi(argv[1]);
		if (l > 0 && l < 7) {
			arlg->setLevel(l);
		}
	}
	if (argc > 2) {
		int l = std::stoi(argv[2]);
		if (l > 0) {
			arlg->setLife(l);
		}
	}
    Game game {std::move(arlg), std::make_unique<CustomClock>(0.2)};
    game.go();
}
