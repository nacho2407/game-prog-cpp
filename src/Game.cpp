#include "game/Game.hpp"

namespace nacho {
    bool Game::initialize(void) {
        bool sdl_result = SDL_Init(SDL_INIT_VIDEO);
        if (sdl_result != true) {
            SDL_Log("[error] failed to initialize SDL: %s", SDL_GetError());

            return false;
        }
        
        _window = SDL_CreateWindow(
            "Game Programming in C++, Chapter 1",
            1280,
            720,
            0
        );
        if (_window) {
            SDL_Log("[error] failed to create SDL window: %s", SDL_GetError());

            return false;
        }

        return true;
    }

    void Game::run_loop(void) {
        while (_is_running) {
            process_input();

            update_game();

            generate_output();
        }
    }

    void Game::shut_down(void) {
        SDL_DestroyWindow(_window);

        SDL_Quit();
    }
}
