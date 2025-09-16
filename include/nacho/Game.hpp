#ifndef NACHO_GAME_HPP
#define NACHO_GAME_HPP

#include <SDL3/SDL.h>

namespace nacho {
    /**
     * @brief 게임을 나타내는 클래스
     */
    class Game {
    public:
        Game(void): _window(nullptr), _is_running(true) { };

        /**
         * @brief 게임을 초기화합니다
         * 
         * @details SDL과 같이 게임을 구성하는 자원들을 초기화합니다
         * 
         * @return 게임 초기화 성공 여부
         */
        bool initialize(void);

        /**
         * @brief 게임 루프를 실행합니다
         * 
         * @details 게임 루프는 기본적으로 입력 > 처리 > 출력으로 이루어집니다
         */
        void run_loop(void);

        /**
         * @brief 게임을 종료합니다
         * 
         * @details SDL과 같이 게임을 구성하는 자원들을 정리합니다
         */
        void shut_down(void);
    private:
        /**
         * @brief 게임과 관련된 입력을 처리합니다
         * 
         * @details SDL은 게임과 관련한 사용자의 입력을 운영체제로부터 이벤트의 형태로 받아서 처리합니다.
         *          
         *          이 때는 SDL 내부 큐를 이용하여 관리하며, 개발자가 해당 이벤트를 처리하지 않으면 자동으로 SDL에서 처리합니다.
         * 
         *          개발자는 처리가 필요한 이벤트를 이벤트 큐에서 폴링하여 이벤트의 종류를 파악한 후 처리합니다
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
    };
}
#endif 
