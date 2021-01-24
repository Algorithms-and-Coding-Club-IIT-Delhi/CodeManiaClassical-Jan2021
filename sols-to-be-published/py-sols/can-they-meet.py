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
    q = get_int()
    for _ in range(q):
        a, b, x = get_tuple_ints()
        if a == 0 and b == 0:
            if x == 0:
                print(1)
            else:
                print(0)
            continue
        g = math.gcd(a, b)
        if x % 2 == 0 and (x // 2) % g == 0:
            print(1)
            continue
        x -= a + b
        if x % 2 == 0 and (x // 2) % g == 0:
            print(1)
            continue
        print(0)
    pass

if __name__ == '__main__':
    main()
