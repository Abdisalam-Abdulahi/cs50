#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
 
int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        printf("Usage: ./recover FILE\n");
        return 1;
    }
    FILE *card = fopen(argv[1], "r");
    if (card == NULL)
    {
        printf("Could not open file.\n");
        return 2;
    }

    uint8_t buffer[512];
    bool writing = false;
    FILE *img = NULL;
    int count = 0;

    while (fread(buffer, 1, 512, card) != 0)
    {
        bool header = false;
        if (buffer[0] == 0xff && buffer[1] == 0xd8 && buffer[2] == 0xff && (buffer[3] & 0xf0) == 0xe0)
        {
            header = true;
        }
        if (writing == false && header == true)
        {
            char filename[8];
            sprintf(filename, "%03i.jpg", count);
            img = fopen(filename, "w");
            if (img == NULL)
            {
                return 3;
            }
            fwrite(buffer, 1, 512, img);
            writing = true;
            count++;
            // header = false;
        }
        else if (writing == true && header == false)
        {
            fwrite(buffer, 1, 512, img);
        }
        else if (writing && header == true)
        {
            fclose(img);
            char filename[8];
            sprintf(filename, "%03i.jpg", count);
            img = fopen(filename, "w");
            if (img == NULL)
            {
                return 3;
            }
            fwrite(buffer, 1, 512, img);
            count++;
            // break;
        }
    }
    if(writing)
    {
        fclose(img);
        fclose(card);
    }
}



/**
 *         char filename[8];
        FILE *img;
        if (buffer[0] == 0xff && buffer[1] == 0xd8 && buffer[2] == 0xff && (buffer[3] & 0xf0) == 0xe0)
        {

            check += 1;
            // char filename[8];
            sprintf(filename, "%03i.jpg", 0);
            img = fopen(filename, "w");
            if (img == NULL)
            {
                printf("could not open\n");
                return 3;
            }
        }
        if (check > 1)
        {
            fclose (img);
            break;  
        }
        if (check != 0)
        {
            fwrite(buffer, 1, 512, img);
        }
    }
 */