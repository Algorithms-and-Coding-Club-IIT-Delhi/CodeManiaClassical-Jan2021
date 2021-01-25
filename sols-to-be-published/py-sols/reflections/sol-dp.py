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
    maxn = 10**5 + 3
    dp = [i // 2 for i in range(maxn)]
    for i in range(2, maxn):
        for j in range(i * 3, maxn, i * 2):
            dp[j] -= dp[i]
    q = get_int()
    for _ in range(q):
        k, b, c, d = get_tuple_ints()
        if k % 2 == 0:
            print(c * dp[k + 2])
        else:
            print((b + d) * dp[k + 2])
    pass

if __name__ == '__main__':
    main()
