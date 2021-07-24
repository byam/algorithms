from sys import stdin

l = [int (x) for x in stdin.readline().rstrip().split()]
l.sort()

print(l[-3])
