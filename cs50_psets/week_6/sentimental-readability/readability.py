text = input("Text: ")

# count letters
n_letters = 0
for i in range(len(text)):
    if text[i].isalpha():
        n_letters += 1

# count words
n_words = 1
for i in range(len(text)):
    if text[i] == " ":
        n_words += 1

# count sentences
n_sentences = 0
for i in range(len(text)):
    curr = text[i]
    if curr == "." or curr == "!" or curr == "?":
        n_sentences += 1

# compute grade level
l = (n_letters / n_words) * 100
s = (n_sentences / n_words) * 100
index = (0.0588 * l) - (0.296 * s) - 15.8
index = round(index)

if index < 0:
    print("Before Grade 1")
elif index >= 16:
    print("Grade 16+")
else:
    print(f"Grade {index}")