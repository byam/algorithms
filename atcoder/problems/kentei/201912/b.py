from sys import stdin

n = int(stdin.readline().rstrip())

cur, past = 0, 0

for i in range(n):
    cur = int(stdin.readline().rstrip())

    if i == 0:
        past = cur
        continue

    if cur == past:
        print("stay")
    if cur < past:
        print("down {}".format(past - cur))
    if cur > past:
        print("up {}".format(cur - past))

    past = cur
