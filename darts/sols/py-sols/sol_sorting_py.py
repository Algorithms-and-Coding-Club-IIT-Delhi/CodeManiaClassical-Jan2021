# fast IO

import sys
input = sys.stdin.readline
def print(x, end='\n'):
    sys.stdout.write(str(x) + end)

# IO helpers

def get_int():
    return(int(input()))
def get_list_ints():
    return(list(map(int, input().split())))
def get_char_list():
    s = input()
    return(list(s[:len(s) - 1]))
def get_tuple_ints():
    return(tuple(map(int, input().split())))
def print_iterable(p):
    print(" ".join(map(str, p)))

# main

n, q = get_tuple_ints()

a = [get_tuple_ints() for i in range(n)]
queries = [get_tuple_ints() for i in range(q)]

a.sort()

y = [Y for (X, Y) in a]

suffix_max = [0 for i in range(n)]
suffix_max[-1] = y[-1]

for i in range(n - 2, -1, -1):
    suffix_max[i] = max(suffix_max[i + 1], y[i])

for _ in range(q):
    x, y = queries[_]
    l, r, i_x = 0, n - 1, -1
    while l <= r:
        m = (l + r) // 2
        if a[m][0] >= x:
            i_x = m
            r = m - 1
        else:
            l = m + 1
    if i_x == -1:
        print(-1)
    else:
        l, r, i_y = i_x, n - 1, -1
        while l <= r:
            m = (l + r) // 2
            if suffix_max[m] >= y:
                i_y = m
                l = m + 1
            else:
                r = m - 1
        if i_y == -1:
            print(-1)
        else:
            print_iterable(a[i_y])
