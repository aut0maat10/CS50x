// Implement a program that recovers JPEGs from 
// a forensic image, per the below.
// $ ./recover card.raw

#include <stdio.h>

#define BLOCK 512 

int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        fprintf(stderr, "Usage: ./recover image\n");
        return 1;
    }
    
    // open file and check for errors
    FILE *fileptr = fopen(argv[1], "r");
    if (fileptr == NULL)
    {
        fprintf(stderr, "Could not open file.\n");
        return 2;
    }
    
    
    unsigned char buffer[BLOCK]; // make buffer
    int jpegindex = 0;  // jpeg count
    FILE* outfile = NULL; // outfile
    int picfound = 0; // determine jpegs found
    
    while (fread(buffer, BLOCK, 1, fileptr) == 1) 
    {
        // check for start of jpeg
        if (buffer[0] == 0xff && buffer[1] == 0xd8 && buffer[2] == 0xff && (buffer[3] & 0xf0) == 0xe0)
        {
            // when start of new picture found, close the old one
            if (picfound != 0)
            {
                fclose(outfile);
            }
            // new jpeg found, ready to start writing
            else
            {
                picfound = 1;
            }
            
            // array to hold name of jpeg files - 001.jpg, 002.jpeg, etc.
            char filename[8];
            
            //create filename for jpeg
            sprintf (filename, "%03d.jpg", jpegindex);
            outfile = fopen(filename, "w");
            jpegindex++;
        }
        if (picfound != 0)
        {
            // write jpeg to outfile 1 BLOCK (512 bytes) at a time
            fwrite(buffer, BLOCK, 1, outfile);
        }
    }
    // close any remaining files and return 0
    if (picfound != 0)
    {
        fclose(outfile);
    }
    
    fclose(fileptr);
    
    return 0;
}