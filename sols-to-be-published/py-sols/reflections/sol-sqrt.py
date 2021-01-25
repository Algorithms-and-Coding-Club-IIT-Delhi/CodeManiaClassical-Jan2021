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

def phi(n):
    ans = n
    for i in range(2, n + 1):
        if i * i > n:
            break
        if n % i == 0:
            ans -= ans // i
            while n % i == 0:
                n //= i
    if n > 1:
        ans -= ans // n
    return ans

def main():
    q = get_int()
    for _ in range(q):
        k, b, c, d = get_tuple_ints()
        if k % 2 == 0:
            print(c * phi(k + 2))
        else:
            print((b + d) * phi(k + 2) // 2)
    pass

if __name__ == '__main__':
    main()
