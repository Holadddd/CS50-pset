#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>
//512 for each element size
#define BUFFER_COUNT 65536
#define BUFFER_SIZE 512

int checkIsHeader(uint8_t *buffer);

int main(int argc, char *argv[])
{
    if (argc != 2)
    {
    //No card argument
        return 0;
    }

    FILE *file = fopen(argv[1], "r");
    //Buffer 512
    uint8_t *storeBuffer = (uint8_t*) malloc(BUFFER_SIZE);

    int numberOfReadingIndex = 0;

    int tmpSize = fread(storeBuffer, 1, BUFFER_SIZE, file);

    while (tmpSize >= BUFFER_SIZE)
    {
        if (checkIsHeader(storeBuffer))
        {
            //Create a new jpeg file
            char *filename = malloc(sizeof(char)*3 + 1);
            sprintf(filename, "%03i.jpg", numberOfReadingIndex);
            FILE *newFile = fopen(filename, "w");

            fwrite(storeBuffer, BUFFER_SIZE, 1, newFile);

            tmpSize = fread(storeBuffer, 1, BUFFER_SIZE, file);
            //Keep writing into file until read another header
            while ((tmpSize >= BUFFER_SIZE) && !checkIsHeader(storeBuffer))
            {
                //Keep writing the file
                fwrite(storeBuffer, BUFFER_SIZE, 1, newFile);

                tmpSize = fread(storeBuffer, 1, BUFFER_SIZE, file);

            }
            //free the last file and name
            free(filename);
            fclose(newFile);
            numberOfReadingIndex += 1;
        }
        else
        {
            //Keep reading until find header
            tmpSize = fread(storeBuffer, 1, BUFFER_SIZE, file);
        }
    }
}

int checkIsHeader(uint8_t *buffer)
{
    if ((buffer[0] == 0xff && buffer[1] == 0xd8 && buffer[2] == 0xff) && ((buffer[3] & 0xf0) == 0xe0))
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
