/*
ID: 318439981
Name: Matan Dombelski
ID: 315240564
Name: Arad Zulti
*/

#include "gtest/gtest.h"
#include "gmock/gmock.h"
#include "../src/client/BoardManager.h"
#include "../src/client/Matrix.h"

TEST(REGULAR_RULE, FIND_ALL_AVAILABLE) {
    BoardManager boardManager(6);
    Matrix<Checker> board(6, 6);
    Matrix<Checker> check(6, 6);
    for (int i = 0; i < 6; i++) {
        for (int j = 0; j < 6; j++) {
            board[i][j] = Nothing;
            check[i][j] = Nothing;
        }
    }

    board[2][2] = White;
    board[2][3] = Black;
    board[3][2] = Black;
    board[3][3] = White;
    board[4][1] = White;
    board[4][4] = Black;
    boardManager.Init(board);

    check[2][2] = White;
    check[2][3] = Black;
    check[3][2] = Black;
    check[3][3] = White;
    check[4][1] = White;
    check[4][4] = Black;

    check[1][1] = AvailableB;
    check[1][2] = AvailableB;
    check[2][1] = AvailableB;
    check[3][4] = AvailableB;
    check[4][3] = AvailableB;
    check[5][0] = AvailableB;

    check[1][3] = AvailableW;
    check[1][4] = AvailableW;
    check[2][4] = AvailableW;
    check[3][1] = AvailableW;
    check[4][2] = AvailableW;
    check[5][5] = AvailableW;

    boardManager.FindAllAvailable();
    EXPECT_EQ(check, boardManager.GetBoard());
}