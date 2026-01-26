s = input("Do you agree? ")

s = s.lower()
if s in ["y", "yes"]:
    print("agreed")
else:
    print("not agreed")