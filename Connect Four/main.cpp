#include <bits/stdc++.h>
#include <windows.h>
#include "rules.h"

using namespace std;

int board[6][7];

bool game_over = false;
int player = 0;
int col;

int color1, color2;

int close = 1;

int main()
{
    //ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cout << "Color List: \n";
    cout << "1. Red = 1 \n2. Blue = 2 \n3. Yellow = 3 \n4. Green = 4 \n5. Purple = 5 \n";
    cout << "Player 1 please choise your color: "; cin >> color1;
    cout << "\n";
    switch(color1){
        case 1:
            cout << "Color List: \n";
            cout << "1. Blue = 1 \n2. Yellow = 2 \n3. Green = 3 \n4. Purple = 4 \n";
            cout << "Player 2 please choise your color: "; cin >> color2;
            color1 = 192;
            if(color2 == 1) color2 = 151;
            else if(color2 == 2) color2 = 224;
            else if(color2 == 3) color2 = 164;
            else if(color2 == 4) color2 = 223;
            break;
        case 2:
            cout << "Color List: \n";
            cout << "1. Red = 1 \n2. Yellow = 2 \n3. Green = 3 \n4. Purple = 4 \n";
            cout << "Player 2 please choise your color: "; cin >> color2;
            color1 = 151;
            if(color2 == 1) color2 = 192;
            else if(color2 == 2) color2 = 224;
            else if(color2 == 3) color2 = 164;
            else if(color2 == 4) color2 = 223;
            break;
        case 3:
            cout << "Color List: \n";
            cout << "1. Red = 1 \n2. Blue = 2 \n3. Green = 3 \n4. Purple = 4 \n";
            cout << "Player 2 please choise your color: "; cin >> color2;
            color1 = 224;
            if(color2 == 1) color2 = 192;
            else if(color2 == 2) color2 = 151;
            else if(color2 == 3) color2 = 164;
            else if(color2 == 4) color2 = 223;
            break;
        case 4:
            cout << "Color List: \n";
            cout << "1. Red = 1 \n2. Blue = 2 \n3. Yellow = 3 \n4. Purple = 4 \n";
            cout << "Player 2 please choise your color: "; cin >> color2;
            color1 = 164;
            if(color2 == 1) color2 = 192;
            else if(color2 == 2) color2 = 151;
            else if(color2 == 3) color2 = 224;
            else if(color2 == 4) color2 = 223;
            break;
        case 5:
            cout << "Color List: \n";
            cout << "1. Red = 1 \n2. Blue = 2 \n3. Yellow = 3 \n4. Green = 4 \n";
            cout << "Player 1 please choise your color: "; cin >> color2;
            color1 = 223;
            if(color2 == 1) color2 = 192;
            else if(color2 == 2) color2 = 151;
            else if(color2 == 3) color2 = 224;
            else if(color2 == 4) color2 = 164;
            break;
    }

    board_show(board, color1, color2);
    while(!game_over){
        // Player 1 Turn
        if(player == 0){
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),15);
            cout << "Plyer 1 please make your choise by selecting the column (0-6): ";
            cin >> col; cout << "\n";

            if(col >= 0 && col <= 6){
                if(valid_place(board, col)){
                    int row = get_next_open_row(board, col);
                    drop(board, row, col, 1);

                    if(check_win(board,1)){
                        board_show(board, color1, color2);
                        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),224);
                        cout << "PLAYER 1 WINS!!!\n\n";
                        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),15);
                        cout << "Press 0 to close\n\n";
                        cin >> close;
                        game_over = true;
                    }
                }
                else player--;
            }
            else player--;
        }

        // Player 2 Turn

        else{
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),15);
            cout << "Plyer 2 please make your choise by selecting the column (0-6): ";
            cin >> col; cout << "\n";

            if(col >= 0 && col <= 6){
                if(valid_place(board, col)){
                    int row = get_next_open_row(board, col);
                    drop(board, row, col, 2);

                    if(check_win(board,2)){
                        board_show(board, color1, color2);
                        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),224);
                        cout << "PLAYER 2 WINS!!!\n";
                        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),15);
                        cout << "Press 0 to close\n\n";
                        cin >> close;
                        game_over = true;
                    }
                }
                else player--;
            }
            else player--;
        }

        if(tie(board)){
            board_show(board, color1, color2);
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),224);
            cout << "It's a tie!\n";
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),15);
            cout << "Press 0 to close\n\n";
            cin >> close;
            game_over = true;
        }

        if(close) board_show(board, color1, color2);

        player++;
        player %= 2;
    }
    if(!close) return 0;
}
