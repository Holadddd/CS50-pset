from cs50 import get_int

height = get_int("Height: ")

while ((height > 0) and (height <= 8)) :
    for layer in range (0, height, 1):
        blank = ""
        block = ""

        for i in range(0, (height - layer), 1):
            blank += " "

        for i in range(0, layer + 1, 1):
            block += "#"

        print(blank ,block, " ", block, blank)

    height = get_int("Height: ")