#ifndef CONNECTFOUR_H
#define CONNECTFOUR_H

#include <bits/stdc++.h>
#include <windows.h>

class ConnectFour
{
public:
    ConnectFour(int color1, int color2);
    void run();

private:
    bool game_over = false;
    int player = 0;
    int color1, color2;
    std::array<std::array<int, 7>, 6> board;
    std::array<int, 6> turns;

    bool is_valid_column(const int);
    void drop(const int);
    int winner();
    bool is_board_full();
    void board_show();
};

#endif // CONNECTFOUR_H
