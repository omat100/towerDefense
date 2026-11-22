#include "Core/Game.hpp"
#include "base/Screen.hpp"

int main(int argc, char** argv) {
    if (argc > 1 && std::string(argv[1]) == "--editor") {
        sceneBuilder::runScreen();
        return 0;
    }
    Game game;
    game.run();

    return 0;
}