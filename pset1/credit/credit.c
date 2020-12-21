#include <stdio.h>
#include <cs50.h>
#include <math.h>
int checkValidNumber(long long number);
char* cardSupplier(long long number);

int main(void)
{
    long long number;

    do {
        printf("Number: ");
        number = get_long_long("");
    }
    while (checkValidNumber(number) != 0) ;
    {
        printf("%s\n", cardSupplier(number));
    }
}

int checkValidNumber(long long number)
{
    int numberDigitCount = ceil(log10((double) number));
    //Check digit of number 
    if ((numberDigitCount == 13) || (numberDigitCount == 15) || (numberDigitCount == 16))
    {
        int sum = 0;
        
        for (int i = 1 ; i <= numberDigitCount ; i++)
        {
            int temp = (number % ((long long)pow(10,i))) ;
            
            if (i > 1)
            {
                temp = ((number % ((long long)pow(10,i))) / ((long long)pow(10,i - 1)));
            }
            
            if (i % 2 == 1) 
            {
                sum += temp ;
            }
            else 
            {
                sum += (temp * 2) / 10;
                sum += (temp * 2) % 10;
            }
        }
        if ((sum % 10) == 0) 
        {
            return 0;
        }
        else 
        {
            return 1;
        }
    }
    //Wrong digit length
    return 1;
}

char* cardSupplier(long long number) 
{
    int numberDigitCount = ceil(log10((double) number));
    
    int temp = number / ((long long) pow(10 , (numberDigitCount - 2)));
    
    int firstInt = temp / 10;
    
    int secondInt = temp % 10;
    
    
    if (firstInt == 4) 
    {
        return "VISA";
    } 
    else if ((firstInt == 3) && ((secondInt == 4) || (secondInt == 7)))
    {
        return "All American Express";
    }
    else if ((firstInt == 5) && ((secondInt == 1) || (secondInt == 2) || (secondInt == 3) || (secondInt == 4) || (secondInt == 5)))
    {
        return "MasterCard";
    }
    return "Invalid";
}