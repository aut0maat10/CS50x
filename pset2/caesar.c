#include <cs50.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int main(int argc, string argv[])
{
     // convert string to int
    if (argc != 2)           // ideally, argc is 2
    {
        printf("Error!");
        return 1;
    }
    else
    {  
        int key = atoi(argv[1]);
        // prompt for plaintext from user
        printf("plaintext: "); 
        string pltext = get_string();
        // make sure get_string returns a string
        if (pltext != NULL)
        {
            printf("ciphertext: ");
            // iterate through string one character at at time
            for (int i = 0, n = strlen(pltext); i < n; i++)
            {
                // check if alphabetical character
                if (isalpha(pltext[i]))
                {
                    // if uppercase, keep uppercase
                    if (isupper(pltext[i]))
                    {
                    // from ASCII to alphabetical index and back (uppercase index)
                    printf("%c",(((pltext[i] - 65) + key) % 26) + 65); 
                    }
                    // if lowercase, keep lowercase
                    if (islower(pltext[i]))
                    {
                    // from ASCII to alphabetical index and back (lowercase index)
                    printf("%c", (((pltext[i] - 97) + key) % 26) + 97);
                    }
                }
                // if not alphabetical character, just print character
                else
                {
                    printf("%c", pltext[i]);
                }
            }
        }
    }
    printf("\n");
    return 0;
}