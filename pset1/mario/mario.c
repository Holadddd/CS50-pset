#include <stdio.h>
#include <cs50.h>

int main(void)
{
    int height;

    do
    {
        printf("Height: ");
        height = get_int("");
    }
    while ((height <= 0) || (height > 8)) ;
    {
        for (int layer = 1; layer <= height; layer++)
        {
            for (int i = 1; i <= height; i++)
            {
                if ((i + layer) > height)
                {
                printf("#");
                }
                else
                {
                    printf(" ");
                }
            }
            printf(" ");
            for (int i = 1; i <= layer; i++)
            {
                printf("#");
            }
        printf("\n");
        }
    }
}