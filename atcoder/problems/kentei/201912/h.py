from sys import stdin
from copy import deepcopy

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
c_n = [int(x) for x in stdin.readline().rstrip().split()]
c_n_org = deepcopy(c_n)
q = int(stdin.readline().rstrip())

sum_org = sum(c_n_org)
min_all = min(c_n_org)
min_odds = min(c_n_org[::2])

sub_all = 0
sub_odds = 0

for _ in range(q):
    # print(c_n, sub_all, sub_odds, min_odds, min_all)

    cur_l = [int(x) for x in stdin.readline().rstrip().split()]

    if cur_l[0] == 1:
        x = cur_l[1] - 1
        a = cur_l[2]

        if x % 2 != 0:
            if c_n[x] - sub_all >= a:
                c_n[x] -= a
                min_all = min(c_n[x] - sub_all, min_all)
        else:
            if c_n[x] - sub_all - sub_odds >= a:
                c_n[x] -= a
                min_all = min(c_n[x] - sub_all - sub_odds, min_all)
                min_odds = min(c_n[x] - sub_all - sub_odds, min_odds)

    if cur_l[0] == 2:
        a = cur_l[1]
        if min_odds >= a:
            sub_odds += a
            min_odds -= a
            min_all = min(min_odds, min_all)

    if cur_l[0] == 3:
        a = cur_l[1]
        if min_all >= a:
            sub_all += a
            min_odds -= a
            min_all -= a

# print(c_n, sub_all, sub_odds, min_odds, min_all)


print(sum(c_n_org) - sum(c_n) + sub_all * n + sub_odds * int( (n + 1) / 2) )
