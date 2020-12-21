from cs50 import get_string

def getTheGrade(letters, words, sentences):
    #index = 0.0588 * L - 0.296 * S - 15.8
    l = (letters / words) * 100
    s = (sentences / words) * 100
    index = 0.0588 * l - 0.296 * s - 15.8
    print("index before interger", index)
    return round(index)
#=====
text = get_string("Text: ")

#Last space index
spaceIndex = -1

letters = 0
words = 0
sentences = 0

for i in range(0, len(text), 1):
    char = text[i]

    #Check the space, (space)=32
    if (char == " "):
        letters += i - spaceIndex - 1
        words += 1
        spaceIndex = i

    #Check the comma, ;=59 '=39
    if ((char == ";") or (char == "'")):
        letters -= 1

    #consider any sequence of characters that ends with a . or a ! or a ? to be a sentence
    #Chechk the sentences, !=33 .=46 ?=63
    if ((char == "!") or (char == ".") or (char == "?")):
        letters -= 1
        sentences += 1

    # #Check is end of the text
    # if (char == None):
    #     letters += i - spaceIndex - 1
    #     words += 1
letters += i - spaceIndex - 1
words += 1

index = getTheGrade(letters, words, sentences)
if (index < 1):
    print("Before Grade 1")

if (index > 16):
    print("Grade 16+")

if (index >= 1 and index <= 16):
    print("Grade ", index)