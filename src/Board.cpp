//
// Created by Serena Gong on 4/17/22.
//
#include "Board.h"
#include <vector>
using namespace std;
using glm::vec2;

    Board::Board(string starting_board) {
    win_condition = vector<BoardStruct>(kWinCondition);
    }

    void Board::Draw() {
        // Draws and fills the classic connect 4 blue gameboard
        ci::gl::color(ci::Color8u(0, 0, 200));
        ci::gl::drawSolidRect(ci::Rectf(vec2(300, 100), vec2(900, 750)));

        // player 1 has classic connect 4 red checker
        if (player_one_turn) {
            ci::gl::color(ci::Color("red"));
        }

        // player 2 has classic connect 4 yellow checker
        if (player_one_turn) {
            ci::gl::color(ci::Color("yellow"));
        }
        else {
            ci::gl::color(ci::Color8u(0,0,0));
        }
    }

    vector<vector<int>> Board::getBoard() {
        return board;
    }

    int Board::getWinValue() {
        return kWinCondition;
    }

    int Board::checkMove(int player, int column) {
        if (board[0][column] != 0) {
            return -1;
        }

        for (int i = 0; i < kBoardRowLength; i++) {
            if (i > 0 && board[i][column] != 0) {
                i--;
                board[i][column] = player;
                return i;
            } else if (i == board.size() - 1) {
                board[i][column] = player;
                return i;
            }
        }
        return 0;
    }

    bool Board::isDiagWin(int player, int column, int row) {
        int count = 0;

        if (row < kBoardRowLength && column <  kBoardColumnLength) {
            row++;
            column++;
        }

        while (row >= 0 && column >= 0) {
            if (board[row][column] == player) {
                count++;
                win_condition.push_back(BoardStruct(row, column));
            }

            else {
                count = 0;
                win_condition.clear();
            }

            if (count >= kWinCondition) {
                return true;
            }

            row--;
            column--;
        }

        win_condition.clear();
        return false;
    }

    bool Board::isAntiDiagWin(int player, int row, int column) {
        int count = 0;
        if (row < kBoardRowLength  && column <  kBoardColumnLength) {
            row++;
            column--;
        }

        while (row >= 0 && board[row].size()) {
            if (board[row][column] == player) {
                count++;
                win_condition.push_back(BoardStruct(row, column));
            }

            else {
                count = 0;
                win_condition.clear();
            }

            if (count >= kWinCondition) {
                return true;
            }

            row--;
            column--;
        }

        win_condition.clear();
        return false;
    }

    bool Board::isRowWin(int player, int row) {
        int count = 0;

        for (int i = 0; i < kBoardColumnLength; i++) {
            if (board[row][i] == player) {
                count++;
                win_condition.push_back(BoardStruct(row, i));
            }

            else {
                count = 0;
                win_condition.clear();
            }

            if (count >= kWinCondition) {
                return true;
            }
        }
        win_condition.clear();
        return false;
    }

    bool Board::isColumnWin(int player, int column) {
        int count = 0;

        for (int i = 0; i < kBoardRowLength; i++) {
            if (board[i][column] == player) {
                count++;
                win_condition.push_back(BoardStruct(i, column));
            }
            else {
                count = 0;
                win_condition.clear();

            }

            if (count >= kWinCondition) {
                return true; }
        }

        win_condition.clear();
        return false;
    }

    bool Board::isPlayerWin(int player, int row, int column) {
        return (isDiagWin(player, row, column) || isAntiDiagWin(player, row, column)
                || isRowWin(player, row) || isColumnWin(player, column));
    }

    bool Board::isBoardFull() {
        for (int i = 0; i < board[0].size(); i++) {
            if (board[0][i] == 0) {
                return false;
            }
        }
        return true;
    }

    void Board::emptyBoard() {
        for (vector<int> row : board) {
            row.clear();
        }
    }





