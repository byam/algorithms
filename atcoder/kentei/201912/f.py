from sys import stdin
import string

s = stdin.readline().rstrip()

wl = []
px = 0

for ix, v in enumerate(s):
    if v in string.ascii_uppercase and px < ix:
        # print(ix, v)

        wl.append(s[px:ix+1])
        px = ix + 1

# print(wl)
print("".join(sorted(wl, key=lambda x: x.upper())))
