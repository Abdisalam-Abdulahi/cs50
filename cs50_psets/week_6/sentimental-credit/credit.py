import sys

numbers = input("Number: ")
# numbers = "4003600000000014"

# check the validty of the card
# Reversed_numbers = "4100000000063004"
og_numbers = numbers
numbers = numbers[::-1]
sum = 0
for i in range(1, len(numbers), 2):
    if len(str(int(numbers[i]) * 2)) > 1:
        tmp = int(numbers[i]) * 2
        sum += tmp // 10
        sum += tmp % 10
    else:
        sum += int(numbers[i]) * 2


for i in range(0, len(numbers), 2):
    sum += int(numbers[i])

if (sum % 10) != 0:
    print("INVALID")
    sys.exit(1)

first = og_numbers[0]
second = og_numbers[1]

# check for the capmany
if (first + second == "34" or first + second == "37") and len(og_numbers) == 15:
    print("AMEX")
elif (first + second == "51" or first + second == "52" or first + second == "53"
      or first + second == "54" or first + second == "55") and len(og_numbers) == 16:
    print("MASTERCARD")
elif first == "4" and (len(og_numbers) == 13 or len(og_numbers) == 16):
    print("VISA")

