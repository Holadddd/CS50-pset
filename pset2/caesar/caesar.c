#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <stdlib.h>

//prototype
char get_encrypt(int key, char Char);

int main (int argc, char *argv[])
{
    //只能接受一個數字參數
    if (argc != 2)
    {
        printf("argument is not correct");
        return 1;
    }
    //strtol is function make string to long
    int key = strtol(argv[1], NULL, 10);
    //判斷是否為正整數
    if (!(key > 0))
    {
        printf("Usage:./caesar key19 \n");
        return 1;
    }

    string plaintext = get_string("plaintext: ") ;

    int i = 0;
    while (plaintext[i] != 0)
    {
        char tmp = plaintext[i];
        plaintext[i] = get_encrypt(key, tmp);
        i += 1;
    }

    printf("ciphertext: %s\n", plaintext);
    return 0;
}

char get_encrypt(int key, char Char)
{
    int shift = key % 26 ;
    //ASCII position
    int seq = (int) Char;
    //lower case , a = 97
    if ((seq < 123) && (seq > 96))
    {
    int position = (((seq - 97) + shift) % 26) + 97;
    return (char) position;
    }
    //Upper case, A = 65
    if ((seq < 91) && (seq > 64))
    {
    int position = (((seq - 65) + shift) % 26) + 65;
    return (char) position;
    }
    //Not a alphabetical characters
    return Char;
}
