/*
ID: 318439981
Name: Matan Dombelski
ID: 315240564
Name: Arad Zulti
*/

#include "gtest/gtest.h"
#include "gmock/gmock.h"
#include "../src/BoardManager.h"
#include "../src/Matrix.h"

TEST(BOARD_MANAGER_TEST, DO_TURN) {
    BoardManager boardManager(4);
    Matrix<Checker> board(4, 4);
    Matrix<Checker> check(4, 4);
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            board[i][j] = Nothing;
            check[i][j] = Nothing;
        }
    }
    board[0][0] = White;
    board[1][0] = Black;
    board[2][0] = Black;
    board[3][0] = AvailableW;
    boardManager.Init(board);
    check[0][0] = White;
    check[1][0] = White;
    check[2][0] = White;
    check[3][0] = White;
    boardManager.DoTurn(3, 0, White);
    EXPECT_EQ(check, boardManager.GetBoard());

    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            board[i][j] = Nothing;
            check[i][j] = Nothing;
        }
    }
    board[0][0] = White;
    board[1][1] = Black;
    board[2][2] = Black;
    board[3][3] = AvailableW;
    boardManager.Init(board);
    check[0][0] = White;
    check[1][1] = White;
    check[2][2] = White;
    check[3][3] = White;
    boardManager.DoTurn(3, 3, White);
    EXPECT_EQ(check, boardManager.GetBoard());
}

TEST(BOARD_MANAGER_TEST, PLAYER_HAS_AVAILABLE) {
    BoardManager boardManager(4);
    Matrix<Checker> board(4, 4);
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            board[i][j] = Nothing;
        }
    }
    board[0][0] = White;
    board[1][0] = Black;
    board[2][0] = Black;
    boardManager.Init(board);
    EXPECT_FALSE(boardManager.CheckPlayerAvailable(Black) || boardManager.CheckPlayerAvailable(White));
    board[3][0] = AvailableW;
    boardManager.Init(board);
    EXPECT_TRUE(boardManager.CheckPlayerAvailable(White));
}

TEST(BOARD_MANAGER_TEST, CHECK_GAME_ENDED) {
    BoardManager boardManager(4);
    Matrix<Checker> board(4, 4);
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            board[i][j] = Nothing;
        }
    }
    board[0][0] = White;
    board[1][0] = Black;
    board[2][0] = Black;
    boardManager.Init(board);
    EXPECT_TRUE(boardManager.CheckIfGameEnded());
    board[3][0] = AvailableW;
    boardManager.Init(board);
    EXPECT_FALSE(boardManager.CheckIfGameEnded());
}

TEST(BOARD_MANAGER_TEST, CHECK_WINNER) {
    BoardManager boardManager(4);
    Matrix<Checker> board(4, 4);
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            board[i][j] = Nothing;
        }
    }
    board[0][0] = White;
    board[1][0] = Black;
    board[2][0] = Black;
    boardManager.Init(board);
    EXPECT_EQ(boardManager.ReturnWinner(), Black);
    board[3][0] = White;
    boardManager.Init(board);
    EXPECT_EQ(boardManager.ReturnWinner(), Nothing);
    board[3][1] = White;
    boardManager.Init(board);
    EXPECT_EQ(boardManager.ReturnWinner(), White);
}