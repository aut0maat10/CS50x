/**
 * helpers.c
 *
 * Helper functions for Problem Set 3.
 */
 
#include <cs50.h>
#include <stdio.h> // for testing printf
#include "helpers.h"

/**
 * Returns true if value is in array of n values, else false.
 */
bool search(int value, int values[], int n)
{
    // TODO: implement a searching algorithm
    int first = 0;
    int last = n - 1;
    int mid = (first + last) /2;
    
    if (n <= 0)
    {
        return false;
    }
    
    while (first <= last)
    {
        
        if (values[mid] == value)
        {
            return true;
        }
        else if (value > values[mid])
        {
            first = mid + 1;
            mid = (first + last) / 2;
        }
        else if (value < values[mid])
        {
            last = mid - 1;
            mid = (first + last) / 2;
        }
        else
            break;
    }
    return false;
}


/**
 * Sorts array of n values.
 */
void sort(int values[], int n)
{
    // TODO: implement an O(n^2) sorting algorithm
   
    
    // iterate through all numbers in array
    
        for (int i = 0; i < n - 1; i++)
        {
            int swap_count = 0;
            for (int j = i; j < n; j++)
            {
                
                if (values[j] < values[i])
                {
                    int temp = values[j];
                    values[j] = values[i];
                    values[i] = temp;
                    swap_count = 1;
                }
             
            }
            if (swap_count == 0)
            {
                break;
            }
        }
    return;
}

