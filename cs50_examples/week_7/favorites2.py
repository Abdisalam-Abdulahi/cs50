from cs50 import SQL

db =  SQL("sqlite:///favorites.db")

favorite = input("Favorite: ")
raws = db.execute("SELECT COUNT(*) AS n FROM favorites WHERE problem = ?", favorite)
raw = raws[0]
print(raw["n"])
