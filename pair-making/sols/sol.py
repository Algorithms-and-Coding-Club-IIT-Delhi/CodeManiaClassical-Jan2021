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

    n, k, p = get_tuple_ints()

    factorial = [1 for i in range(p)]
    inverse_factorial = [p - 1 for i in range(p)]

    for i in range(1, p):
        factorial[i] = factorial[i - 1] * i % p

    for i in range(p - 1, 0, -1):
        inverse_factorial[i - 1] = inverse_factorial[i] * i % p

    ans = 0
    for i in range(1, p):
        i_squared = i * i % p
        j = (inverse_factorial[i_squared] * factorial[i_squared - 1] % p) * k % p
        ans += ((n + p - i) // p) * ((n + p - j) // p)

    print(ans)

if __name__ == '__main__':
    main()
