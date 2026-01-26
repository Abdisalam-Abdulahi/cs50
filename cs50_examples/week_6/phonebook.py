people = [
    {"name": "kelly", "number": "+1-617-495-1000"},
    {"name": "david", "number": "+1-617-495-1000", "email": "david@mail.com"},
    {"name": "john harvard", "number": "+1-949-468-2750"}
]

name = input("Enter name: ")


for person in people:
    if person["name"] == name:
        number = person["number"]
        print(f"name: {name}, number: {number}")
        break
else:
    print("not Found")