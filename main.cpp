#include <iostream>
#include <fstream>
#include <string>
#include <string.h>

using namespace std;
int m, n, count = 0;
int offsetX, offsetY;
string temp[4];
string *checkSurround(string arr[], int a, int b, string *sample)
{
    for (int i = 0; i < 9; i++)
    {
        for (int j = 0; j < 10; j++)
        {
            cout << sample[i][j];
        }
        cout << endl;
    }
    string up, left, down, right;
    up = left = down = right = "no";
    for (int i = 0; i < 4; i++)
    {
        if (arr[i] == "")
        {
            continue;
        }
        else if (arr[i] == "UP")
        {
            if (sample[a - 1][b] == '0')
            {
                up = "no";
            }
            else if (sample[a - 1][b] == '1')
            {
                up = "yes";
            }
        }
        else if (arr[i] == "LEFT")
        {
            if (sample[a][b - 1] == '0')
            {
                left = "no";
            }
            else if (sample[a][b - 1] == '1')
            {
                left = "yes";
            }
        }
        else if (arr[i] == "DOWN")
        {
            if (sample[a + 1][b] == '0')
            {
                down = "no";
            }
            else if (sample[a + 1][b] == '1')
            {
                down = "yes";
            }
        }
        else if (arr[i] == "RIGHT")
        {
            if (sample[a][b + 1] == '0')
            {
                right = "no";
            }
            else if (sample[a][b + 1] == '1')
            {
                right = "yes";
            }
        }
    }
    temp[0] = up;
    temp[1] = left;
    temp[2] = down;
    temp[3] = right;
    return temp;
}

void start(int a, int b, string *arr2, int (*queue)[400][2], string arr[])
{
    arr2[b][a] = '0';
    string pos[4];
    if (b - 1 < 0)
    {
        if (a - 1 < 0)
        {

            pos[0] = "";
            pos[1] = "";
            pos[0] = "";
            pos[0] = "";
            {"", "", "DOWN", "RIGHT"};
            string *kt = checkSurround(pos, b, a, arr2);
            if (kt[2] == "yes")
            {
            }
        }
        else if (a + 1 > offsetX)
        {
            string pos[] = {"", "LEFT", "DOWN", ""};
            string *kt = checkSurround(pos, b, a, arr2);
        }
        else
        {
            string pos[] = {"", "LEFT", "DOWN", "RIGHT"};
            string *kt = checkSurround(pos, b, a, arr2);
        }
    }
    else if (b + 1 > offsetY)
    {
        if (a - 1 < 0)
        {
            string pos[] = {"UP", "", "", "RIGHT"};
            string *kt = checkSurround(pos, b, a, arr2);
        }
        else if (a + 1 > offsetX)
        {
            string pos[] = {"UP", "LEFT", "DOWN", ""};
            string *kt = checkSurround(pos, b, a, arr2);
        }
        else
        {
            string pos[] = {"UP", "LEFT", "", "RIGHT"};
            string *kt = checkSurround(pos, b, a, arr2);
        }
    }
    else if (a - 1 < 0)
    {
        string pos[] = {"UP", "", "DOWN", "RIGHT"};
        string *kt = checkSurround(pos, b, a, arr2);
    }
    else if (a + 1 > offsetX)
    {
        string pos[] = {"UP", "LEFT", "DOWN", ""};
        string *kt = checkSurround(pos, b, a, arr2);
    }
    else
    {
        string pos[] = {"UP", "LEFT", "DOWN", "RIGHT"};
        string *kt = checkSurround(pos, b, a, arr2);
    }

    /* for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            switch (arr2[i][j])
            {
            case '0':
                arr2[i][j] = 'a';
                break;
            case '1':
                arr2[i][j] = 'b';
                break;
            case '2':
                arr2[i][j] = 'c';
                break;

            default:
                break;
            }
        }
    } */
}

int main()
{
    ifstream fi("rb.inp");
    ofstream fo("rb.out");
    fi >> m >> n;
    string arr[n], alt[n];
    offsetX = m - 1, offsetY = n - 1;
    int initX = 0, initY = 0;
    for (int i = 0; i < n; i++)
    {
        fi >> arr[i];
        alt[i] = arr[i];
        for (int j = 0; j < m; j++)
        {
            if (arr[i][j] == '#')
            {
                alt[i][j] = '0';
            }
            else if (arr[i][j] == '.')
            {
                alt[i][j] = '1';
            }
            else
            {
                initX = j;
                initY = i;
                alt[i][j] = '2';
            }
        }
        fo << alt[i] << endl;
    }
    // pointer hang cho`
    int queue[400][2];
    memset(queue, 0, sizeof queue);
    int(*pointerQ)[400][2];
    pointerQ = &queue;
    // pointer cua mang alt //
    string *pointerA;
    pointerA = alt;

    start(initX, initY, pointerA, pointerQ, arr);

    fi.close();
    fo.close();
    return 0;
}