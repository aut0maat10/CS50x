#include <cs50.h>
#include <stdio.h>

int main(void)
{
    printf("Enter height - a positive number < 24: \n");
    
    int height, i, j, k, l, m;
    
    do
    {
       printf("Height: ");
       height = get_int();
    }
    while (height < 0 || height > 23);
    
    
    for (i = 0; i < height; i++) // rows
    {
        for (j = 0; j < height - i - 1; j++) // spaces
        {
            printf(" ");
        }
        for (k = 0; k < i + 1; k++ )
        {
            printf("#"); // left pyramid
        }
        for (l = 0; l < i - k + 2; l++)
        {
            printf("  "); // gap
        }
        for (m = 0; m < i + 1 ; m++)
        {
            printf("#"); // right pyramid
        }
        printf("\n");
    }
   
}