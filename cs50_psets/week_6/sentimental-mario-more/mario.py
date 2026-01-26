while True:
    try:
        height = int(input("Height: "))
        if height > 0 and height <= 8:
            break
    except ValueError:
        continue


for raw in range(height):
    space = height  
    space = space - (raw + 1)
    print(" " * space, end="")

    for col in range(raw + 1):
        print("#", end="")

    print("  ", end="")

    for col in range(raw + 1):
        print("#", end="")
    
    print()

