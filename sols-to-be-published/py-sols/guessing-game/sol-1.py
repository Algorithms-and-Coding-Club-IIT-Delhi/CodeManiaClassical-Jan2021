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
    l, r = 1, n
    while l <= r:
        m = (l + r) // 2
        print(m)
        sys.stdout.flush()
        result = "".join(get_char_list())
        if result == "guessed":
            break
        elif result == "lesser":
            l, r = m + 1, (m + r + 1) // 2
        else:
            l, r = (l + m) // 2, m - 1
    pass

if __name__ == '__main__':
    main()
