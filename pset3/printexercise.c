// excercise for cs50 game of fifteen:
// print 2D array

#include <cs50.h>
#include <stdio.h> 

int main(void)
{
    //int i = 0, j = 0;
    int d = 4;
    int number = d * d;
    int board[4][4];
    
    for (int i = 0; i < d; i++) // row
    {
        for (int j = 0; j < d; j++) // column
        {
            // print numbers in descending order
            board[i][j] = --number;
            // print underscore instead of 0
            if (board[i][j] == 0)
            {
                printf("  _");
            }
            else // print tile number
            {
                // add spaces before single digit numbers
                printf("%3i", board[i][j]);
            }
        }
        printf("\n");
    }
}

/* result:

15 14 13 12
11 10  9  8
 7  6  5  4
 3  2  1  _

 */