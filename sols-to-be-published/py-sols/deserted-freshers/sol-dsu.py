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

class DSU:
    def __init__(self, n):
        self.n = n
        self.par = [i for i in range(n)]
        self.siz = [1 for i in range(n)]

    def make_set(self, v):
        self.par[v] = v
        self.siz[v] = 1

    def find_set(self, v):
        if v == self.par[v]:
            return v
        self.par[v] = self.find_set(self.par[v])
        return self.par[v]

    def union_sets(self, a, b):
        a = self.find_set(a)
        b = self.find_set(b)
        if a != b:
            if self.siz[a] < self.siz[b]:
                a, b = b, a
            self.par[b] = a
            self.siz[a] += self.siz[b]

    def components(self):
        representative = [self.find_set(i) for i in range(self.n)]
        answer = [[] for i in range(self.n)]
        for i in range(self.n):
            answer[representative[i]].append(i)
        return [x for x in answer if x]

def main():

    n, m = get_tuple_ints()
    a = get_list_ints()

    visited = [False for i in range(n)]
    g = [[] for i in range(n)]
    components = [[] for i in range(n)]

    dsu = DSU(n)

    for i in range(m):
        u, v = get_tuple_ints()
        dsu.union_sets(u - 1, v - 1)

    components = dsu.components()

    indices = sorted([i for i in range(n)], key=lambda x : -a[x])
    components.sort(key=lambda x : -len(x))

    current_rank = 0
    assigned_vertex = [0 for i in range(n)]
    for component in components:
        for x in component:
            assigned_vertex[indices[current_rank]] = x + 1
            current_rank += 1

    print_iterable(assigned_vertex)
    pass

if __name__ == '__main__':
    main()
