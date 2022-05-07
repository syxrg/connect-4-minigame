//
// Created by Serena Gong on 4/17/22.
//

#pragma once
#include<vector>
#include "cinder/gl/gl.h"

using namespace std;

class Board {
    struct BoardStruct {
        int row;
        int column;
        BoardStruct() : row(0), column(0) {};
        BoardStruct(int r, int c): row(r), column(c) {

        };
    };

    private:
        vector<vector<int>> board;
        vector<BoardStruct> win_condition;
        int moves_ = 0;
        const int kBoardColumnLength = 6;
        const int kBoardRowLength = 7;
        const int kWinCondition = 4;
        bool playerOneTurn = false;
        bool playerTwoTurn = false;

    public:
        Board(string starting_board);
        void Draw();
        vector<vector<int>> getBoard();
        int getWinValue();
        bool player_one_turn = false;
        bool player_two_turn = false;


    void setBoardPosition(int player, int column, int row);
        // Returns row number that checker was dropped in, or -1 (error) if column is full
        int checkMove(int player, int column);
        bool isDiagWin(int player, int column, int row);
        bool isAntiDiagWin(int player, int row, int column);
        bool isRowWin(int player, int row);
        bool isColumnWin(int player, int column);
        bool isPlayerWin(int player, int row, int column);
        bool isBoardFull();
        void emptyBoard();
};


