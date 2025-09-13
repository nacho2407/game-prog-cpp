#ifndef NACHO_GAME_HPP
#define NACHO_GAME_HPP

#include <SDL/SDL.h>

namespace nacho {
    class Game {
    public:
        Game(void): _window(nullptr), _is_running(false) { };

        /**
         * @brief 게임을 초기화합니다
         */
        bool initialize(void);

        /**
         * @brief 게임 루프를 실행합니다
         */
        void run_loop(void);

        /**
         * @brief 게임을 종료합니다
         */
        void shut_down(void);
    private:
        /**
         * @brief 게임과 관련된 입력을 처리합니다
         */
        void process_input(void);

        /**
         * @brief 게임을 갱신합니다
         */
        void update_game(void);

        /**
         * @brief 갱신된 게임을 출력합니다
         */
        void generate_output(void);

        /**
         * @brief 게임 윈도우
         */
        SDL_Window* _window;

        /**
         * @brief 게임이 계속 실행되어야 하는지 판단
         */
        bool _is_running;
    }
}
#endif 
