#include "game/Game.hpp"

namespace nacho {
    bool Game::initialize(void) {
        bool sdl_result = SDL_Init(SDL_INIT_VIDEO);
        if (sdl_result != true) {
            SDL_Log("[error] unable to initialize SDL: %s", SDL_GetError());

            return false;
        }
        
        /* 작성중 */
    }
}
