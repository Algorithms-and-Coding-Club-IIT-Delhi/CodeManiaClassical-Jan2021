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
    a.sort(reverse=True)
    queries = [None for i in range(q)]
    for i in range(q):
        x, y = get_tuple_ints()
        queries[i] = (x, y, i)
    queries.sort()

    y_max = -1
    maximal = [None for i in range(n)]
    cur = 0
    for (x, y) in a:
        if y_max < y:
            maximal[cur] = (x, y)
            y_max = y
            cur += 1

    a = maximal
    n = cur

    ptr = n - 1
    answer = [-1 for i in range(q)]

    for (x, y, i) in queries:
        while ptr >= 0 and maximal[ptr][0] < x:
            ptr -= 1
        if ptr >= 0 and maximal[ptr][1] >= y:
            answer[i] = ptr

    for x in answer:
        if x == -1:
            print(-1)
        else:
            print_iterable(maximal[x])

if __name__ == '__main__':
    main()
