#include "ConnectFour.h"

ConnectFour::ConnectFour(int color1, int color2)
    : color1(color1), color2(color2) {
    std::array<int,7> col;
    std::fill(begin(col), end(col), 0);
    std::fill(begin(board), end(board), col);
    std::fill(begin(turns), end(turns), 0);
}

void ConnectFour::run() {
    for ( ; !winner() || !is_board_full(); player = (player + 1) % 2) {
        board_show();
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),15);
        int column;
        std::cout << "Player " << player + 1 << " please make your choice by selecting the column (0-6): ";
        std::cin >> column;
        std::cout << '\n';
        while (column < 0 || column > 6 || !is_valid_column(column)) {
            std::cout << "Invalid column: ";
            std::cin >> column;
            std::cout << '\n';
        }
        drop(column);
        if(winner() || is_board_full())
            break;
    }
    int w = winner();
    board_show();
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),224);
    if (w) {
        std::cout << "PLAYER " << w << " WINS!!!\n\n";
    } else {
        std::cout << "It's a tie!\n";
    }
}

bool ConnectFour::is_valid_column(const int col) {
    if(turns[col] < 6) return true;
    return false;
}
void ConnectFour::drop(const int col) {
    board[5 - turns[col]][col] = player + 1;
    turns[col]++;
}

int ConnectFour::winner() {
    for (int piece = 1; piece <= 2; piece++) {
        int c, r;

        //Check horizontal
        for(c = 0 ;c <= 3; c++){
            for(r = 0; r <= 5; r++){
                if(board[r][c] == piece && board[r][c+1] == piece && board[r][c+2] == piece && board[r][c+3] == piece)
                    return piece;
            }
        }

        //Check vertical
        for(c = 0 ;c <= 6; c++){
            for(r = 0; r <= 2; r++){
                if(board[r][c] == piece && board[r+1][c] == piece && board[r+2][c] == piece && board[r+3][c] == piece)
                    return piece;
            }
        }

        //Check positively sloped diaganols
        for(c = 0 ;c <= 3; c++){
            for(r = 0; r <= 2; r++){
                if(board[r][c] == piece && board[r+1][c+1] == piece && board[r+2][c+2] == piece && board[r+3][c+3] == piece)
                    return piece;
            }
        }

        //Check negatively sloped diagonals
        for(c = 0 ;c <= 3; c++){
            for(r = 3; r <= 5; r++){
                if(board[r][c] == piece && board[r-1][c+1] == piece && board[r-2][c+2] == piece && board[r-3][c+3] == piece)
                    return piece;
            }
        }
    }
    return 0;
}

bool ConnectFour::is_board_full() {
    return *std::min_element(begin(turns), end(turns)) == 7;
}

void ConnectFour::board_show() {
    system("cls");
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),15);
    for(int i = 0; i <= 6; i++) std::cout << " " << i << " ";
    std::cout << "\n";
    for (auto row : board) {
        for (const int tile : row) {
            if (tile == 0)
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 240);
            if (tile == 1)
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color1);
            if (tile == 2)
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color2);
            std::cout << "   ";
        }
        std::cout << '\n';
    }
    std::cout << '\n';
}
