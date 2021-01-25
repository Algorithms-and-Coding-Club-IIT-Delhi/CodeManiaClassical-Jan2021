import sys

def main():
    n = int(input())
    l, r = 1, n
    while l <= r:
        m = (l + r) // 2
        print(m)
        sys.stdout.flush()
        result = input()
        if result == "guessed":
            break
        elif result == "lesser":
            l, r = m + 1, r - (r - m) // 2
        else:
            l, r = l + (m - l) // 2, m - 1
    pass

if __name__ == '__main__':
    main()
