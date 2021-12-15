#include <memory>
#include <utility>
#include <string>
#include "game.h"
#include "customClock.h"
#include "floppybrad.h"

int main(int argc, char *argv[]) {
    Game game {std::make_unique<FloppyBrad>, std::make_unique<CustomClock>(0.2)};
    game.go();
}

