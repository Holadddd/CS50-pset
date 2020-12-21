from cs50 import get_string

#CheckMethod
def checkValidNumber(number):
    numberDigitCount = len(number)

    if ((numberDigitCount == 13) or (numberDigitCount == 15) or (numberDigitCount == 16)):
        sum = 0

        for i in range(1, numberDigitCount + 1, 1):
            temp = (int(number) % (pow(10,i)))

            if i > 1:
                temp = ((int(number) % (pow(10,i))) / (pow(10,i - 1)))

            if (i % 2 == 1):
                sum += temp
            else:
                sum += (temp * 2) / 10
                sum += (temp * 2) % 10

        if ((sum % 10) == 0):

            return False
        else:

            return True
    #Wrong digit length
    return False
#=====
def getCardSupplier(number):
    # numberDigitCount = len(number)

    # temp = int(number) / (pow(10 , (numberDigitCount - 2)))

    firstInt = number[0]

    secondInt = number[1]

    if (int(firstInt) == 4):
        return "VISA"
    if (int(firstInt) * 10 + int(secondInt)) in [34,37]:
        return "All American Express"
    if (int(firstInt) * 10 + int(secondInt)) in [51,52,53,54,55]:
        return "MasterCard"

    return "Invalid"
#=====
number = get_string("Number: ")

if checkValidNumber(number):
    cardSupplier = getCardSupplier(number)
    print(cardSupplier)
