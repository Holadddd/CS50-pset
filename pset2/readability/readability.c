#include <stdio.h>
#include <cs50.h>
#include <string.h>

int getTheGrade(int letters, int words, int sentences);

int main(void)
{

    string text = get_string("Text: ");

    //Last space index
    int spaceIndex = -1;

    int letters = 0;
    int words = 0;
    int sentences = 0;

    for (int i = 0 ; i <= strlen(text) ; i++)
    {
        int codeNumber = text[i];
        //Check the space, (space)=32
        if (codeNumber == 32){
            letters += i - spaceIndex - 1;
            words += 1;
            spaceIndex = i;
        }
        //Check the comma, ;=59 '=39
        if ((codeNumber == 59) || (codeNumber == 39))  {
            letters -= 1;
        }
        //consider any sequence of characters that ends with a . or a ! or a ? to be a sentence
        //Chechk the sentences, !=33 .=46 ?=63
        if ((codeNumber == 33) || (codeNumber == 46) || (codeNumber == 63))
        {
            letters -= 1;
            sentences += 1;
        }
        //Check is end of the text
        if (codeNumber == 0)
        {
            letters += i - spaceIndex - 1;
            words += 1;
        }
    }

    // printf("Letters: %i, Words: %i, Sentences %i .\n", letters, words, sentences);
    int index = getTheGrade(letters, words, sentences);
    if (index < 1)
    {
        printf("Before Grade 1\n");
    }
    else if (index > 16)
    {
        printf("Grade 16+\n");
    }
    else
    {
        printf("Grade %i\n", index);
    }
}

int getTheGrade(int letters, int words, int sentences)
{
    //index = 0.0588 * L - 0.296 * S - 15.8
    double l = ((double) letters / (double) words) * 100;
    double s = ((double) sentences / (double) words) * 100;
    double index = 0.0588 * l - 0.296 * s - 15.8;
    return (int)index;
}