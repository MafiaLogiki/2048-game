#include <iostream>
#include <ctime>


void up(int pole[4][4], int not_visible[4][4])
{
    for (int i = 1; i < 4; ++i)
    {
        for (int j = 0; j < 4; ++j)
        {
            if (pole[i][j] != 0)
            {
                int temp = i - 1;
                while (temp >= 1 && pole[temp][j] == 0)
                {
                    temp--;
                }
                if (pole[temp][j] != 0)
                {
                    if (pole[temp][j] == pole[i][j] && not_visible[temp][j] == 0 && temp != i)
                    {
                        pole[temp][j] = 2 * pole[i][j];
                        pole[i][j] = 0;
                        not_visible[temp][j] = 1;
                    }
                    else
                    {
                        if (temp + 1 != i)
                        {
                            pole[temp + 1][j] = pole[i][j];
                            pole[i][j] = 0;
                        }
                    }
                }
                else
                {
                    if (temp != i)
                    {
                        pole[temp][j] = pole[i][j];
                        pole[i][j] = 0;
                    }
                }
            }
        }
    }
}


void down(int pole[4][4], int not_visible[4][4])
{
    for (int i = 2; i >= 0; --i)
    {
        for (int j = 0; j < 4; ++j)
        {
            if (pole[i][j] != 0)
            {
                int temp = i + 1;
                while (temp < 3 && pole[temp][j] == 0)
                {
                    temp++;
                }
                if (pole[temp][j] != 0)
                {
                    if (pole[temp][j] == pole[i][j] && not_visible[temp][j] == 0 && temp != i)
                    {
                        pole[temp][j] = 2 * pole[i][j];
                        pole[i][j] = 0;
                        not_visible[temp][j] = 1;
                    }
                    else
                    {
                        if (temp - 1 != i)
                        {
                            pole[temp - 1][j] = pole[i][j];
                            pole[i][j] = 0;
                        }
                    }
                }
                else
                {
                    if (temp != i)
                    {
                        pole[temp][j] = pole[i][j];
                        pole[i][j] = 0;
                    }
                }
            }
        }
    }
}


void left(int pole[4][4], int not_visible[4][4])
{
    for (int j = 1; j < 4; ++j)
    {
        for (int i = 0; i < 4; ++i)
        {
            if (pole[i][j] != 0)
            {
                int temp = j - 1;
                while (temp >= 1 && pole[i][temp] == 0)
                {
                    temp--;
                }
                if (pole[i][temp] != 0)
                {
                    if (pole[i][temp] == pole[i][j] && not_visible[i][temp] == 0 && temp != j)
                    {
                        pole[i][temp] = 2 * pole[i][j];
                        pole[i][j] = 0;
                        not_visible[i][temp] = 1;
                    }
                    else
                    {
                        if (temp + 1 != j)
                        {
                            pole[i][temp + 1] = pole[i][j];
                            pole[i][j] = 0;
                        }
                    }
                }
                else
                {
                    if (temp != j)
                    {
                        pole[i][temp] = pole[i][j];
                        pole[i][j] = 0;
                    }
                }
            }
        }
    }
}


void right(int pole[4][4], int not_visible[4][4])
{
    for (int j = 2; j >= 0; --j)
    {
        for (int i = 0; i < 4; ++i)
        {
            if (pole[i][j] != 0)
            {
                int temp = j + 1;
                while (temp < 3 && pole[i][temp] == 0)
                {
                    temp++;
                }
                if (pole[i][temp] != 0)
                {
                    if (pole[i][temp] == pole[i][j] && not_visible[i][temp] == 0 && temp != j)
                    {
                        pole[i][temp] = 2 * pole[i][j];
                        pole[i][j] = 0;
                        not_visible[i][temp] = 1;
                    }
                    else
                    {
                        if (temp - 1 != j)
                        {
                            pole[i][temp - 1] = pole[i][j];
                            pole[i][j] = 0;
                        }
                    }
                }
                else
                {
                    if (temp != j)
                    {
                        pole[i][temp] = pole[i][j];
                        pole[i][j] = 0;
                    }
                }
            }
        }
    }
}


void isGameEnded(int pole[4][4])
{
    int count{ 0 };
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            if (pole[i][j] != 0)
            {
                count++;
            }
        }
    }
    if (count == 16)
    {
        for (int i = 0; i < 4; i++)
        {
            for (int j = 0; j < 4; j++)
            {
                pole[i][j] = 0;
            }
        }
        std::cout << "YOU LOSE!" << std::endl;
        system("pause");
        system("cls");
    }
}


void updateNumbers(int pole[4][4])
{
    unsigned random_number = unsigned(std::time(nullptr));
    int row = 5;
    int column = 5;
    while (row > 4 || column > 4 || pole[row][column] != 0)
    {
        random_number = (random_number * 73129 + 95121) % 100000;
        row = random_number % 4;
        column = random_number % 4;
    }
    int whatNumberWeGet = rand() % 1000;
    if (whatNumberWeGet < 900)
    {
        pole[row][column] = 2;
    }
    else
    {
        pole[row][column] = 4;
    }
}
