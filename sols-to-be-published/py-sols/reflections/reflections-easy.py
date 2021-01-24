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
    k, b, c, d = get_tuple_ints()
    ans = 0
    for i in range(k + 3):
        if math.gcd(i, k + 2 - i) == 1:
            if i % 2 == 0:
                if (k + 2 - i) % 2 == 0:
                    assert False
                else:
                    ans += b
            else:
                if (k + 2 - i) % 2 == 0:
                    ans += d
                else:
                    ans += c
    print(ans)
    pass

if __name__ == '__main__':
    main()
