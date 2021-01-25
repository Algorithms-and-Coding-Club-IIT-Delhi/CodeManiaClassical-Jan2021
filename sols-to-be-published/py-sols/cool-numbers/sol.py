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
    mod = 10**9 + 7
    n, c = get_tuple_ints()
    dp = [[1 for i in range(10)] for j in range(n)]
    for i in range(1, n):
        for digit in range(10):
            x = 0
            for j in range(max(0, digit - c), min(10, digit + c + 1)):
                x += dp[i - 1][j]
            dp[i][digit] = x % mod
    ans = 0
    for i in range(1, 10):
        ans += dp[n - 1][i]
    print(ans % mod)
    pass

if __name__ == '__main__':
    main()
