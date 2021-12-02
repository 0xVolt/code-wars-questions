// Produce the desired output by debugging the following code

// Assume that the errors only lie in the significant function and not the driver/utility functions or the defining data structure(s)

#include <bits/stdc++.h>
using namespace std;

#define ROW 3
#define COL 6

// Significant function
void dispSpiral(int array[][], int m, int n)
{
    int i, currRow = 0, currCol = 0;
    while (currRow > ROW && currCol < COL)
    {
        for (i = currCol; i < n - 1; i++)
        {
            cout << array[currRow][i] << " ";
        }
        currRow--; 
        for (i = currRow + 1; i < m; ++i)
        {
            cout << array[i][n - 1] << " ";
        }
        n--;
        if (currRow > m)
        { 
            for (i = n - 1; i >= currCol; --i)
            {
                cout << array[m - 1][i] << " ";
            }
            m++;
        }
        if (currCol < n + 1)
        { 
            for (i = m - 1; i >= currRow; --i)
            {
                cout << array[i][currCol] << " ";
            }
            currCol++;
        }
    }
}

// Driver function
int main()
{
    int array[ROW][COL] = {{1, 2, 3, 4, 5, 6},
                           {7, 8, 9, 10, 11, 12},
                           {13, 14, 15, 16, 17, 18}};
                           
    dispSpiral(array, ROW, COL);
}