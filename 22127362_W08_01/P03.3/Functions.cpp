#include "Header.h"

void Print(int n, int Chess[][MAX_SIZE])
{
    for (int i = 0; i < n; i++)
    {
        cout << endl;
        for (int j = 0; j < n; j++)
        {
            cout << Chess[i][j] << " ";
        }
    }
    return;
}

void caseTest(int n, int d, int c, int SIZE, int Chess[][MAX_SIZE], bool& printed, int dd[], int dc[])
{
    for (int i = 0; i < 8; i++)
    {
        if (n == 1)
        {
            Chess[d][c] = 1;
            caseTest(n + 1, d, c, SIZE, Chess, printed, dd, dc);
        }
        else
        {
            int dmoi = d + dd[i];
            int cmoi = c + dc[i];
            if (dmoi >= 0 && dmoi < SIZE && cmoi >= 0 && cmoi < SIZE && Chess[dmoi][cmoi] == 0)
            {
                Chess[dmoi][cmoi] = n;
                if (n == SIZE * SIZE)
                {
                    Print(SIZE, Chess);
                    printed = true;
                    return;
                }
                else
                {
                    caseTest(n + 1, dmoi, cmoi, SIZE, Chess, printed, dd, dc);
                    Chess[dmoi][cmoi] = 0;
                }
            }
        }
    }
}



void knightTour() {
    int dd[] = { -2,-1,1,2,2,1,-1,-2 }, dc[] = { 1,2,2,1,-1,-2,-2,-1 };
    int size;
    cout << "Enter the size of the chessboard (up to " << MAX_SIZE << "): ";
    cin >> size;

    int Chess[MAX_SIZE][MAX_SIZE] = { 0 };
    bool printed = false;
    caseTest(1, 0, 0, size, Chess, printed, dd, dc);
    if (!printed)
        cout << "No solution";
}

