/* Write a program that first asks the user how much 
change is owed and then spits out the minimum number 
of coins with which said change can be made. */

#include <cs50.h>
#include <stdio.h>
#include <math.h>

int main(void)
{
    float n;
    int coinCount = 0;
    int amount = 0;
    int quarter = 25;
    int dime = 10;
    int nickel = 5;
    int penny = 1;
    
    do
    {
        printf("Hey how much change is owed? \n");
        n = get_float();
        
    }
    while (n < 0);
    amount = round(n * 100);
    
    
    while (amount >= quarter) // quarters
    {
       coinCount++;
       amount -= quarter;
    }
    
    while (amount >= dime) // dimes
    {
       coinCount++;
       amount -= dime;
    }
    
    while (amount >= nickel)
    {
       coinCount++;
       amount -= nickel; // nickels
    }
    
    while (amount >= penny)
    {
       coinCount++;
       amount -= penny; // pennies
    }
    
    printf("%i\n", coinCount); // total number of coins used
}