from sys import stdin

try:
    n = int(stdin.readline().rstrip())
    print(n*2)
except ValueError:
    print("error")
