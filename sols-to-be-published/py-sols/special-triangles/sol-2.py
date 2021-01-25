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

from math import gcd
def main():
    a, b = get_tuple_ints()
    g = gcd(a, b)
    a, b = a // g, b // g
    if b > 2:
        print(-1)
    else:
        if b == 1:
            a *= 2
        print(1)
        if a <= 2:
            print_iterable([0, 0, 1, 1, a + 2, 2])
        else:
            print_iterable([0, 0, 1, 2, a, a])
    pass

if __name__ == '__main__':
    main()
