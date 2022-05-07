//
// Created by Serena Gong on 4/25/22.
//

#pragma once

#include "cinder/app/App.h"
#include "cinder/app/RendererGl.h"
#include "cinder/gl/gl.h"
#include <vector>
#include "Board.h"

namespace connect4 {
        class ConnectFourApp : public ci::app::App {
        public:
            ConnectFourApp();
            void draw() override;
            void mouseDown(ci::app::MouseEvent event) override;
            void mouseDrag(ci::app::MouseEvent event) override;
            void keyDown(ci::app::KeyEvent event) override;

        private:
            const std::string starting_board_ = "bbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbb";
            Board current_board_;
            bool game_has_started_ = false;
            bool player_one_won_ = false;
            bool player_two_won_ = false;
            bool player_one_turn_ = false;
            bool player_two_turn_ = false;
        };

}  // namespace connectfour

