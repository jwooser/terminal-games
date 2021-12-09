#include <memory>
#include "game.h"
#include "customClock.h"
#include "arlg.h"

int main(int argc, char *argv[]) {	
    Game game {std::make_unique<ARLG>(), std::make_unique<CustomClock>(0.25)};
    game.go();
}
