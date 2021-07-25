from sys import stdin

n, q = [int(x) for x in stdin.readline().rstrip().split()]

nn = [[False for x in range(n)] for y in range(n)]

def get_indexes(l, con_val):
    return [i for i, x in enumerate(l) if x == con_val]

def get_followers(ll, i, con_val):
    return [ix for ix, l in enumerate(ll) if l[i] == con_val]

def show():
    for i in range(n):
        for j in range(n):
            if nn[i][j]:
                print("Y", end="")
            else:
                print("N", end="")
        else:
            print()

for _ in range(q):

    cur = [int(x) for x in stdin.readline().rstrip().split()]

    if len(cur) == 3 and cur[0] == 1:
        a = cur[1] - 1
        b = cur[2] - 1
        nn[a][b] = True

    elif cur[0] == 2:
        a = cur[1] - 1
        followers = get_followers(nn, a, True)
        for f in followers:
            nn[a][f] = True

    elif cur[0] == 3:
        a = cur[1] - 1
        follows = get_indexes(nn[a], True)
        for f in follows:
            f_follows = get_indexes(nn[f], True)
            for ff in f_follows:
                nn[a][ff] = True

show()
