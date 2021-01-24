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

    n = get_int()
    pre = get_list_ints()

    for i in range(1, n):
        pre[i] += pre[i - 1]

    p = pre[-1]
    if p == 1:
        print(-1)
        return

    max_chain = 1

    def longest_chain(prime, pre):
        divisible = 0
        for x in pre:
            if x % prime == 0:
                divisible += 1
        return divisible

    for i in range(2, p + 1):
        if i * i > p:
            break
        if p % i == 0:
            while p % i == 0:
                p //= i
            max_chain = max(max_chain, longest_chain(i, pre))

    if p > 1:
        max_chain = max(max_chain, longest_chain(p, pre))

    print(n - max_chain)
    pass

if __name__ == '__main__':
    main()
