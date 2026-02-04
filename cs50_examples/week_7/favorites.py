import csv

with open("favorites.csv", "r") as file:
    reader = csv.DictReader(file)
    
    count = {}

    for raw in reader:
        favorite = raw["language"]
        if favorite in count:
            count[favorite] += 1 
        else:
            count[favorite] = 1


for favorite in count:
    print(favorite, count[favorite])