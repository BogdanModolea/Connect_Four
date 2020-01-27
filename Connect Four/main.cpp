#include <bits/stdc++.h>
#include <windows.h>

#include "ConnectFour.h"

using namespace std;

std::map<int, std::string> getColors() {
    return {
        {192, "red"},
        {151, "blue"},
        {224, "yellow"},
        {164, "green"},
        {223, "purple"}
    };
}

int getPlayerColor(int player, std::map<int, std::string>& colors) {
    std::cout << "Color list:" << '\n';
    std::vector<int> colorV;
    int idx = 1;
    for(auto p : colors) {
        std::cout << idx << "." << p.second << " = " << idx << '\n';
        ++idx;
        colorV.push_back(p.first);
    }
    std::cout << '\n';
    int color;
    cout << "Player " << player << " please choose your color: ";
    std::cin >> color;
    int color1 = colorV[color - 1];
    colors.erase(colorV[color - 1]);
    return color1;
}


int main()
{
    std::map<int, std::string> colors = getColors();
    int color1 = getPlayerColor(1, colors);
    int color2 = getPlayerColor(1, colors);

    ConnectFour game(color1, color2);
    game.run();
    return 0;
}
