#include <iostream>
#include <fstream>
#include <string>
#include <string.h>

using namespace std;

int checkSurround(string arr[], int a, int b, string sample[])
{
    string up, left, down, right;
    up = left = down = right = "";
    for (int i = 0; i < 4; i++)
    {
        if (arr[i] == "UP")
        {
            if (sample[a - 1][b] == '#')
            {
                down = "yes";
            }
            else if (sample[a - 1][b] == '.' || sample[a - 1][b] == '@')
            {
                down = "no";
            }
        }
        else if (arr[i] == "LEFT")
        {
            if (sample[a][b - 1] == '#')
            {
                left = "yes";
            }
            else if (sample[a][b - 1] == '.' || sample[a][b - 1] == '@')
            {
                left = "no";
            }
        }
        else if (arr[i] == "DOWN")
        {
            if (sample[a + 1][b] == '#')
            {
                down = "yes";
            }
            else if (sample[a + 1][b] == '.' || sample[a + 1][b] == '@')
            {
                down = "no";
            }
        }
        else if (arr[i] == "RIGHT")
        {
            if (sample[a][b + 1] == '#')
            {
                right = "yes";
            }
            else if (sample[a][b + 1] == '.' || sample[a][b + 1] == '@')
            {
                right = "no";
            }
        }
    }
    if (up == "no" || left == "no" || down == "no" || right == "no")
    {
        return 0;
    }
    else
        return 1;
}

int main()
{
    fstream fi("rb.inp");
    fstream fo("rb.out");
    int m, n;
    fi >> m >> n;
    string arr[n];
    int tong = m * n;
    int offsetX = m - 1, offsetY = n - 1;
    for (int i = 0; i < n; i++)
    {
        fi >> arr[i];
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (arr[i][j] == '#')
            {
                tong--;
            }
            else
            {
                if (i - 1 < 0)
                {
                    if (j - 1 < 0)
                    {
                        string pos[] = {"", "DOWN", "RIGHT", ""};
                        int kt = checkSurround(pos, i, j, arr);
                        if (kt == 1)
                        {
                            tong--;
                        }
                    }
                    else if (j + 1 > offsetX)
                    {
                        string pos[] = {"LEFT", "DOWN", "", ""};
                        int kt = checkSurround(pos, i, j, arr);
                        if (kt == 1)
                        {
                            tong--;
                        }
                    }
                    else
                    {
                        string pos[] = {"LEFT", "DOWN", "RIGHT", ""};
                        int kt = checkSurround(pos, i, j, arr);
                        if (kt == 1)
                        {
                            tong--;
                        }
                    }
                }
                else if (i + 1 > offsetY)
                {
                    if (j - 1 < 0)
                    {
                        string pos[] = {"", "DOWN", "RIGHT", ""};
                        int kt = checkSurround(pos, i, j, arr);
                        if (kt == 1)
                        {
                            tong--;
                        }
                    }
                    else if (j + 1 > offsetX)
                    {
                        string pos[] = {"LEFT", "DOWN", "", ""};
                        int kt = checkSurround(pos, i, j, arr);
                        if (kt == 1)
                        {
                            tong--;
                        }
                    }
                    else
                    {
                        string pos[] = {"LEFT", "", "RIGHT", "UP"};
                        int kt = checkSurround(pos, i, j, arr);
                        if (kt == 1)
                        {
                            tong--;
                        }
                    }
                }
                else if (j - 1 < 0)
                {
                    string pos[] = {"LEFT", "", "RIGHT", "UP"};
                    int kt = checkSurround(pos, i, j, arr);
                    if (kt == 1)
                    {
                        tong--;
                    }
                }
                else if (j + 1 > offsetX)
                {
                }
            }
        }
    }
    for (int i = 0; i < n; i++)
    {
        fo << arr[i] << endl;
    }
    fo << tong;
    fi.close();
    fo.close();
    return 0;
}