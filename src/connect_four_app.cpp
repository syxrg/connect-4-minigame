//
// Created by Serena Gong on 4/25/22.
//

#include "connect_four_app.h"
#include "Board.h"
using glm::vec2;
namespace connect4 {
    ConnectFourApp::ConnectFourApp() : current_board_(starting_board_) {
        ci::app::setWindowSize(1200, 800);
    }
    void ConnectFourApp::draw() {
        if(game_has_started_) {
                ci::Color8u background_color(0, 0, 0);
                ci::gl::clear(background_color);

                ci::gl::drawStringCentered("Connect Four", vec2(600, 400),
                                           ci::Color8u(30, 144, 255),
                                           ci::Font("Arial", 100));
                ci::gl::color(ci::Color8u(70, 130, 100));


                ci::gl::drawLine(vec2(530, 550), vec2(670, 550));
                ci::gl::drawLine(vec2(530, 600), vec2(670, 600));
                ci::gl::drawLine(vec2(530, 550), vec2(530, 600));
                ci::gl::drawLine(vec2(670, 550), vec2(670, 600));
                ci::gl::drawStringCentered("Start", vec2(600, 570),
                                           ci::Color8u(70, 130, 180),
                                           ci::Font("Arial", 20));
            }
            else if(player_one_won_ || player_two_won_) {
                ci::Color8u background_color(0, 0, 0);
                ci::gl::clear(background_color);
                ci::gl::color(ci::Color8u(30, 144, 255));
                if(player_one_won_) {
                    ci::gl::drawStringCentered("Player 1 won the game!", vec2(600, 400),
                                               ci::Color8u(30, 144, 255),
                                               ci::Font("Arial", 100));
                }
                else {
                    ci::gl::drawStringCentered("Player 2 won the game!", vec2(600, 400),
                                               ci::Color8u(30, 144, 255),
                                               ci::Font("Arial", 100));
                }

                ci::gl::color(ci::Color8u(70, 130, 100));
                ci::gl::drawLine(vec2(530, 550), vec2(670, 550));
                ci::gl::drawLine(vec2(530, 600), vec2(670, 600));
                ci::gl::drawLine(vec2(530, 550), vec2(530, 600));
                ci::gl::drawLine(vec2(670, 550), vec2(670, 600));
                ci::gl::drawStringCentered("PLAY AGAIN", vec2(600, 570),
                                           ci::Color8u(70, 130, 180),
                                           ci::Font("Arial", 20));

            }
            // if board is full and there is no winner, it is a draw.
            else if(current_board_.isBoardFull()) {
                ci::Color8u background_color(0, 0, 0);
                ci::gl::clear(background_color);
                ci::gl::color(ci::Color8u(30, 144, 255));
                ci::gl::drawStringCentered("Game is a draw!", vec2(600, 400),
                                           ci::Color8u(30, 144, 255),
                                           ci::Font("Arial", 100));
            }
            else {
                ci::Color8u background_color(0, 0, 0);
                ci::gl::clear(background_color);

                ci::gl::drawStringCentered("Connect Four", vec2(600, 40),
                                           ci::Color8u(30, 144, 255),
                                           ci::Font("Arial", 50));

                ci::Rectf pixel_bounding_box(vec2(600, 100), vec2(900, 750));
                ci::gl::drawSolidRect(pixel_bounding_box);
                current_board_.Draw();
            }

        else {
            ci::Color8u background_color(0, 0, 0);
            ci::gl::clear(background_color);

            ci::gl::drawStringCentered("Connect Four", vec2(600, 400),
                                       ci::Color8u(30, 144, 255),
                                       ci::Font("Arial", 100));
            ci::gl::color(ci::Color8u(70, 130, 100));


            ci::gl::drawLine(vec2(530, 550), vec2(670, 550));
            ci::gl::drawLine(vec2(530, 600), vec2(670, 600));
            ci::gl::drawLine(vec2(530, 550), vec2(530, 600));
            ci::gl::drawLine(vec2(670, 550), vec2(670, 600));
            ci::gl::drawStringCentered("Start", vec2(600, 570),
                                       ci::Color8u(70, 130, 180),
                                       ci::Font("Arial", 20));
        }
    }

    void ConnectFourApp::mouseDown(ci::app::MouseEvent event) {
        if(!game_has_started_) {
            vec2 click_screen_coords = event.getPos();
            // if click on "start", game begins
            if(click_screen_coords[0] >= 550 && click_screen_coords[0] <= 650 &&
               click_screen_coords[1] >= 550 && click_screen_coords[1] <= 600) {
                game_has_started_ = true;
                player_one_turn_ = true;
            }
        }
        else if(player_one_won_ || player_two_won_) {
            vec2 click_screen_coords = event.getPos();
            // if click on "play again", current board is emptied and starts again
            if(click_screen_coords[0] >= 530 && click_screen_coords[0] <= 670 &&
               click_screen_coords[1] >= 550 && click_screen_coords[1] <= 600) {
                current_board_.emptyBoard();
            }
        }
        // otherwise, continue to handle the game
        else {
            current_board_.checkMove();

        }
    }
}  //namespace connectfourapp
