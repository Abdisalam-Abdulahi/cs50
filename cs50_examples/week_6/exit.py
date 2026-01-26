import sys

if len(sys.argv) != 2:
    print("missing command line argument")
    sys.exit(1)

print("hello,", sys.argv[1])
sys.exit(0)