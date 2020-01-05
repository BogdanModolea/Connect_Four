#include <bits/stdc++.h>
#include <windows.h>
void board_show(int board[][7], int color1, int color2){
    system("cls");
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),15);
    for(int i = 0; i <= 6; i++) std::cout << " " << i << " ";
    std::cout << "\n";
    for(int i = 5; i >= 0; i--){
        for(int j = 0; j <= 6; j++){
            if(board[i][j] == 1){
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color1);
                    //std::cout << " " << board[i][j] << " ";
                    std::cout << " " << " " << " ";
            }
            else if(board[i][j] == 2){
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color2);
                    //std::cout << " " << board[i][j] << " ";
                    std::cout << " " << " " << " ";
            }
            else{
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 240);
                    //std::cout << " " << board[i][j] << " ";
                    std::cout << " " << " " << " ";
            }
        }
        std::cout << "\n";
    }
    std::cout << "\n";
}

bool valid_place(int board[][7], int col){
    return (board[5][col] == 0);
}

void drop(int board[][7], int row, int col, int piece){
    board[row][col] = piece;
}

int get_next_open_row(int board[][7], int col){
    int r;
    for(r = 0 ;r <= 5; r++)
        if(board[r][col] == 0) return r;
}

bool check_win(int board[][7], int piece){
    int c, r;

    //Check horizontal

    for(c = 0 ;c <= 3; c++){
        for(r = 0; r <= 5; r++){
            if(board[r][c] == piece && board[r][c+1] == piece && board[r][c+2] == piece && board[r][c+3] == piece)
                return true;
        }
    }

    //Check vertical
    for(c = 0 ;c <= 6; c++){
        for(r = 0; r <= 2; r++){
            if(board[r][c] == piece && board[r+1][c] == piece && board[r+2][c] == piece && board[r+3][c] == piece)
                return true;
        }
    }

    //Check positively sloped diaganols

    for(c = 0 ;c <= 3; c++){
        for(r = 0; r <= 2; r++){
            if(board[r][c] == piece && board[r+1][c+1] == piece && board[r+2][c+2] == piece && board[r+3][c+3] == piece)
                return true;
        }
    }

    //Check negatively sloped diagonals

    for(c = 0 ;c <= 3; c++){
        for(r = 3; r <= 5; r++){
            if(board[r][c] == piece && board[r-1][c+1] == piece && board[r-2][c+2] == piece && board[r-3][c+3] == piece)
                return true;
        }
    }

    return false;
}

bool tie(int board[][7])
{
    return (board[5][0] && board[5][1] && board[5][2] && board[5][3] && board[5][4] && board[5][5] && board[5][6]);
}
