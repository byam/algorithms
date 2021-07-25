from sys import stdin

def init_2d(m, n, val=False):
    """
    Create 2d array (m x n) with val
    """
    return [[val for x in range(m)] for y in range(n)]

def filter_indexes(l, con_val):
    """
    Filtering indexes with value condition
    """
    return [i for i, x in enumerate(l) if x == con_val]

n = int(stdin.readline().rstrip())
nn = init_2d(n, n, 0)

m = 3
nm = init_2d(n, m)
ml = [0 for x in range(m)]

for i in range(n - 1):
    cl = [int(x) for x in stdin.readline().rstrip().split()]
    for clx, clv in enumerate(cl):
        nn[i][i+1+clx] = clv
        nn[i+1+clx][i] = clv

# print(*nn, sep="\n")
# print(*nm, sep="\n")
# print(ml)

def get_min_group(ix):

    sum_l = [0 for x in range(m)]

    for mx in range(m):
        gxl = filter_indexes(nm[mx], True)
        # print("filter_indexes: ", gxl)
        if len(gxl) > 0:
            for gxlv in gxl:
                sum_l[mx] += nn[ix][gxlv]
            # print("sum_l[mx]: ", sum_l[mx])

    val = max(sum_l)
    group = sum_l.index(val)

    # print("sum_l: ", ix, sum_l)
    return val, group

for nx in range(n):
    add_val, group = get_min_group(nx)
    # print(add_val, group)
    nm[group][nx] = True
    ml[group] += add_val

    # print(*nm, sep="\n")
    # print(ml)

print(sum(ml))
