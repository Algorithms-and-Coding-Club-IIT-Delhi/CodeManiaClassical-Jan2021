# Fast IO

import sys
input = sys.stdin.readline
def print(x, end='\n'):
    sys.stdout.write(str(x) + end)

# IO helpers

def get_int():
    return int(input())
def get_list_ints():
    return list(map(int, input().split()))
def get_char_list():
    s = input()
    return list(s[:len(s) - 1])
def get_tuple_ints():
    return tuple(map(int, input().split()))
def print_iterable(p):
    print(" ".join(map(str, p)))

def main():

    n, q = get_tuple_ints()
    a = [get_tuple_ints() for i in range(n)]
    a.sort()
    queries = [get_tuple_ints() for i in range(q)]

    def find_maximal(l, r):
        if l == r:
            return [l]
        m = (l + r) // 2
        l_max = find_maximal(l, m)
        r_max = find_maximal(m + 1, r)
        max_second = 0
        for i in r_max:
            max_second = max(max_second, a[i][1])
        return r_max + [i for i in l_max if a[i][1] > max_second]

    max_indices = find_maximal(0, n - 1)
    a = [a[i] for i in max_indices]
    n = len(a)

    for _ in range(q):
        x, y = queries[_]
        l, r, i_x = 0, n - 1, -1
        while l <= r:
            m = (l + r) // 2
            if a[m][0] >= x:
                i_x = m
                l = m + 1
            else:
                r = m - 1
        if i_x == -1:
            print(-1)
        else:
            ans_x, ans_y = a[i_x]
            if ans_y < y:
                print(-1)
            else:
                print_iterable(a[i_x])

if __name__ == '__main__':
    main()
