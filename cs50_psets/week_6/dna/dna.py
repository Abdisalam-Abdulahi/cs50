import csv
import sys
from sys import argv


def main():

    # TODO: Check for command-line usage
    if len(argv) != 3:
        print("Incorrect number of files")
        sys.exit(1)

    # TODO: Read database file into a variable
    raws = []
    with open(argv[1]) as file:
        reader = csv.DictReader(file)
        for raw in reader:
            raws.append(raw)

    # TODO: Read DNA sequence file into a variable
    with open(argv[2]) as txtFile:
        seq = txtFile.read()

    # TODO: Find longest match of each STR in DNA sequence
    t_dict = {}
    for i in range(1, len(reader.fieldnames)):
        count = longest_match(seq, reader.fieldnames[i])
        t_dict[reader.fieldnames[i]] = count
    # TODO: Check database for matching profiles
    for dic in raws:
        #print(dic)
        same = False
        for k, v, in dic.items():
            # print(k, v, t_dict.get(k))
            if k in t_dict and t_dict.get(k) == int(v):
                same = True
                
            else:
                same = False
                break
        if same == True:
            print(dic["name"])
            sys.exit(0)
    print("No match")
    return


def longest_match(sequence, subsequence):
    """Returns length of longest run of subsequence in sequence."""

    # Initialize variables
    longest_run = 0
    subsequence_length = len(subsequence)
    sequence_length = len(sequence)

    # Check each character in sequence for most consecutive runs of subsequence
    for i in range(sequence_length):

        # Initialize count of consecutive runs
        count = 0

        # Check for a subsequence match in a "substring" (a subset of characters) within sequence
        # If a match, move substring to next potential match in sequence
        # Continue moving substring and checking for matches until out of consecutive matches
        while True:

            # Adjust substring start and end
            start = i + count * subsequence_length
            end = start + subsequence_length

            # If there is a match in the substring
            if sequence[start:end] == subsequence:
                count += 1
            
            # If there is no match in the substring
            else:
                break
        
        # Update most consecutive matches found
        longest_run = max(longest_run, count)

    # After checking for runs at each character in sequence, return longest run found
    return longest_run


main()
