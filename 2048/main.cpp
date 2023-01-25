#include <iostream>
#include "game_logic.h"



void draw_pole(int pole[4][4])
{
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            if (pole[i][j] != 0)
                std::cout << pole[i][j] << "      ";
            else
                std::cout << "       ";
        }
        std::cout << std::endl << "-----------------------" << std::endl;
    }
}


int main()
{
    int pole[4][4] = { {0, 0, 0, 0}, {0, 0, 0, 0}, {0, 0, 0, 0}, {0, 0, 0, 0} };
    while (true)
    {
        updateNumbers(pole);
        isGameEnded(pole);
        int not_visible[4][4] = { {0, 0, 0, 0}, {0, 0, 0, 0}, {0, 0, 0, 0}, {0, 0, 0, 0} };
        draw_pole(pole);
        char key_pressed;
        std::cin >> key_pressed;
        switch (key_pressed)
        {
        case 'w':
            up(pole, not_visible);
            break;
        case 'd':
            right(pole, not_visible);
            break;
        case 'a':
            left(pole, not_visible);
            break;
        case 's':
            down(pole, not_visible);
            break;
        default:
            break;
        }
        system("cls");
    }
    return 0;
}