/*
Design and implement a program, initials, that, given a 
person’s name, prints a person’s initials.

Implement your program in a file called initials.c in a 
directory called initials.

Your program should prompt a user for their name using 
get_string to obtain their name as a string.

You may assume that the user’s input will contain only letters 
(uppercase and/or lowercase) plus single spaces between words. 
You don’t need to worry about names like Joseph Gordon-Levitt, 
Conan O’Brien, or David J. Malan!

Your program should print the user’s initials (i.e., the first 
letter of each word in their name) with no spaces or periods, 
followed by a newline (\n). 
*/

#include <cs50.h>
#include <stdio.h>
#include <ctype.h>
#include <string.h>

int main(void)
{
    // get name from user and check for validity
    string name = get_string();
    if (name != NULL)
    {
        printf("%c", toupper(name[0]));
    
        // loop through string and print initials after spaces
        // in uppercase 
    
        for (int i = 0; i < strlen(name); i++)
        {
            if (name[i] == ' ' && name[i+1] != '\0')
            {
            printf("%c", toupper(name[(i + 1)]));
            }
        }
        printf("\n"); // add new line
    }
}