#include <memory>
#include "game.h"
#include "arlg.h"

int main(int argc, char *argv[]) {	
    Game game {std::make_unique<ARLG>()};
    game.go();
}
