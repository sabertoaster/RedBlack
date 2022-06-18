#include <iostream>
#include <fstream>
#include <string>
#include <string.h>

using namespace std;
int m, n;

// void start(int a, int b, string arr1[], string arr2[])
void start(string *arr2)
{

    for (int i = 0; i < n; i++)
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
    }
}

int main()
{
    ifstream fi("rb.inp");
    ofstream fo("rb.out");
    fi >> m >> n;
    string arr[n], alt[n];
    int offsetX = m - 1, offsetY = n - 1;
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
    // start(initX, initY, &arr[n], &alt[n]);

    string *pointer;
    pointer = alt;
    start(pointer);
    for (int i = 0; i < n; i++)
    {
        cout << alt[i] << endl
             << i << endl;
    }
    fi.close();
    fo.close();
    return 0;
}