#include <iostream>
using namespace std;

int board[8][8] = { 0 };

void Board()
{
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            if (board[i][j] == -1) {
                cout << " Q ";
            }
            else {
                cout << " . ";
            }
        }
        cout << endl;
    }
}

void placeQueen(int i, int j)
{
    for (int x = 0; x < 8; ++x) 
    {
        board[x][j] += 1;
        board[i][x] += 1;

        int p;
        p = j - i + x;
        if (p >= 0 && p < 8) {
            board[x][p] += 1;
        }

        p = j + i - x;
        if (p >= 0 && p < 8) {
            board[x][p] += 1;
        }
    }
    board[i][j] = -1;
    cout << endl;
    for (int y = 0; y < 8; y++)
    {
        for (int z = 0; z < 8; z++)
        {
            cout << board[y][z] << " ";
        }
        cout << endl;
    }
    cout << endl;
    Board();
}

void removeQueen(int i, int j)
{
    for (int x = 0; x < 8; ++x) {
        board[x][j] -= 1;
        board[i][x] -= 1;

        int p;
        p = j - i + x;
        if (p >= 0 && p < 8) {
            board[x][p] -= 1;
        }

        p = j + i - x;
        if (p >= 0 && p < 8) {
            board[x][p] -= 1;
        }
    }
    board[i][j] = 0;
}

bool Check(int i)
{
    bool result = false;

    for (int j = 0; j < 8; ++j)
    { 
        if (board[i][j] == 0) 
        { 
            placeQueen(i, j); 

            if (i == 7)
            {
                result = true;
            }  
            else if (!(result = Check(i + 1)))
            {
                removeQueen(i, j);
            }
                
        }
        if (result) break;
    }
    return result;
}

int main()
{
    Check(0);
    return 0;
}
