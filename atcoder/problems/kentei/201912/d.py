from sys import stdin

n = int(stdin.readline().rstrip())

a = [False] * n

fake_num = 0
del_num = 0

for _ in range(n):
    cur = int(stdin.readline().rstrip())

    if a[cur - 1] is False:
        a[cur - 1] = True
    else:
        fake_num = cur

if fake_num == 0:
    print("Correct")
else:
    del_num = [i for i in range(n) if a[i] is False][0] + 1
    print("{} {}".format(fake_num, del_num))
