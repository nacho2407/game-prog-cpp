#include "nacho/Game.hpp"

int main(void) {
    nacho::Game game;

    bool init_res = game.initialize();
    if (init_res) {
        game.run_loop();
    }

    game.shut_down();

    return 0;
}
