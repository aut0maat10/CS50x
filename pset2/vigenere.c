#include <cs50.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int main(int argc, string argv[])
{
    
    if (argc != 2) // if argc is not 2, print error
    {
    printf("error!\n");
    return 1;
    }
    
    
    string key = argv[1];
    int keylen = strlen(key);
    
    // iterate through key, check that all characters are alphabetical
    for (int i = 0; i < keylen; i++) 
    {
        // if not alphabetical, print error message and exit
        if (isalpha(key[i]) == false)
        {
            printf("alphabetical characters only!\n");
            return 1;
        }
    }
            
            printf("plaintext: ");
            
            // prompt user for plaintext
            string plntxt = get_string();
            int plntxtlen = strlen(plntxt);
        
            if (plntxt != NULL)
            {
                printf("ciphertext: ");
                
                // loop through plaintext string
                for (int j = 0, k = 0; j < plntxtlen; j++)
                { 
                    // convert key from ASCII to alphabetical index
                    int key_index = tolower(key[k % keylen]) - 97;
                    
                    // if alphabetical characters in plaintext:
                    if (isalpha(plntxt[j]))
                    {
                        // if uppercase:
                        if (isupper(plntxt[j])) 
                        {
                            printf("%c", ((plntxt[j] - 65 + key_index) % 26) + 65);
                            k++;
                        }
                        //if lowercase:
                        if (islower(plntxt[j]))
                        {
                            printf("%c", ((plntxt[j] - 97 + key_index) % 26) + 97);
                            k++;
                        }
                
                    }
                    else // print out non-alphabetical characters
                    {
                        printf("%c", plntxt[j]);
                    }
                  
                }
            
            }
        printf("\n");
        return 0;
}