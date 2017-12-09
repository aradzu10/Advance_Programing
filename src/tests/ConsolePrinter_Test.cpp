/*
ID: 318439981
Name: Matan Dombelski
ID: 315240564
Name: Arad Zulti
*/

#include "gtest/gtest.h"
#include "gmock/gmock.h"
#include "../client/ConsolePrinter.h"

TEST(CONSOLE_PRINTER, PRINT_TURN_OF) {
    ConsolePrinter *printer = new ConsolePrinter();
    testing::internal::CaptureStdout();
    printer->PrintTurnOf(Black);
    printer->PrintTurnOf(White);
    printer->PrintTurnOf(Nothing);
    std::string output = testing::internal::GetCapturedStdout();
    EXPECT_EQ(output, "It's the turn of player X: \nIt's the turn of player O: \nIt's the turn of player  : \n");
}

TEST(CONSOLE_PRINTER, PRINT_BOARD) {
    Matrix<Checker> board(4, 4);
    ConsolePrinter *printer = new ConsolePrinter();
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            board[i][j] = Nothing;
        }
    }
    board[0][0] = White;
    board[0][1] = White;
    board[1][0] = Black;
    board[2][0] = AvailableW;
    testing::internal::CaptureStdout();
    printer->PrintBoard(board, 4);
    std::string output = testing::internal::GetCapturedStdout();
    EXPECT_EQ(output, "current board: \n | 1 | 2 | 3 | 4 |\n------------------\n1| O | O |   |   |"
            "\n------------------\n2| X |   |   |   |\n------------------\n3|   |   |   |   |\n------------------\n"
            "4|   |   |   |   |\n------------------\n");
}

TEST(CONSOLE_PRINTER, PRINT_AVILABLE) {
    ConsolePrinter *printer = new ConsolePrinter();
    Matrix<Checker> check(6, 6);
    for (int i = 0; i < 6; i++) {
        for (int j = 0; j < 6; j++) {
            check[i][j] = Nothing;
        }
    }

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
    testing::internal::CaptureStdout();
    printer->PrintAvilable(check, 6, Black);
    std::string output = testing::internal::GetCapturedStdout();
    EXPECT_EQ(output, "Your avilable options are: \n(3,4) (4,3) (5,5) \n");

    testing::internal::CaptureStdout();
    printer->PrintAvilable(check, 6, White);
    output = testing::internal::GetCapturedStdout();
    EXPECT_EQ(output, "Your avilable options are: \n(3,3) (4,4) (5,2) \n");

    testing::internal::CaptureStdout();
    printer->PrintAvilable(check, 6, Nothing);
    output = testing::internal::GetCapturedStdout();
    EXPECT_EQ(output, "Your avilable options are: \n(1,1) (1,2) (1,3) (1,4) (1,5) (1,6) (2,1) (2,6)"
            " (3,1) (3,6) (4,1) (4,6) (5,1) (5,6) (6,2) (6,3) (6,4) (6,5) \n");

    testing::internal::CaptureStdout();
    printer->PrintAvilable(check, 6, AvailableB);
    output = testing::internal::GetCapturedStdout();
    EXPECT_EQ(output, "Your avilable options are: \n(2,2) (2,3) (3,2) (4,5) (5,4) (6,1) \n");

    testing::internal::CaptureStdout();
    printer->PrintAvilable(check, 6, AvailableW);
    output = testing::internal::GetCapturedStdout();
    EXPECT_EQ(output, "Your avilable options are: \n(2,4) (2,5) (3,5) (4,2) (5,3) (6,6) \n");

    testing::internal::CaptureStdout();
    printer->PrintAvilable(check, 6, AvailableBoth);
    output = testing::internal::GetCapturedStdout();
    EXPECT_EQ(output, "Your avilable options are: \n\n");
}

TEST(CONSOLE_PRINTER, PRINT_MESSAGE) {
    ConsolePrinter *printer = new ConsolePrinter();
    testing::internal::CaptureStdout();
    printer->PrintMessage("My message test1");
    printer->PrintMessage("My message test2");
    std::string output = testing::internal::GetCapturedStdout();
    EXPECT_EQ(output, "My message test1\nMy message test2\n");
}

TEST(CONSOLE_PRINTER, PRINT_WINNER_MESSAGE) {
    ConsolePrinter *printer = new ConsolePrinter();
    testing::internal::CaptureStdout();
    printer->PrintWinnerMessage(Black);
    printer->PrintWinnerMessage(White);
    printer->PrintWinnerMessage(Nothing);
    std::string output = testing::internal::GetCapturedStdout();
    EXPECT_EQ(output, "The game ended!\nThe Winner is: X !"
            "\nThe game ended!\nThe Winner is: O !"
            "\nThe game ended!\nThe Winner is:   !\n");
}