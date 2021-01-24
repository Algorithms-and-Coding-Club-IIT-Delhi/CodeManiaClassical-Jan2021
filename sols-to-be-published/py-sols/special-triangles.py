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

import math
def main():
    a, b = get_tuple_ints()
    g = math.gcd(a, b)
    a, b = a // g, b // g
    if b > 2:
        print(-1)
    else:
        if b == 1:
            a *= 2
        print(1)
        print_iterable([0, 2 * a, 2, a, 3, 0])
    pass

if __name__ == '__main__':
    main()
