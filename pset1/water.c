#include <cs50.h>
#include <stdio.h>

int main(void)

{
    printf("How much time do you spend in the shower (in minutes)?\n");
    
    int minutes = get_int();
    int bottle = 12;
    int total = minutes * bottle;
    
    if (minutes > 0)
{
    printf("Minutes: %i\nBottles: %i\n", minutes, total);  
} 
    else 
{
    printf("Oops, please enter a positive number!\n");
}
   
}