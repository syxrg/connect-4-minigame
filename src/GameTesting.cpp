//
// Created by Serena Gong on 5/02/22.
//

#include "catch.hh"
#include "Board.h"


TEST_CASE("ClearBoard") {
    Board gameboard = Board("123456789012345678901234");
    gameboard.emptyBoard();
    REQUIRE(gameboard.isBoardFull() == false)
}