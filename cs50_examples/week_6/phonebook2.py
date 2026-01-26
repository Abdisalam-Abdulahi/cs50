import csv

name = input("name: ")
number = input("number: ")

with open("phone-book.csv", "a") as file:
    writer = csv.DictWriter(file, fieldnames=["name", "number"])
    writer.writerow({"name": name, "number": number})