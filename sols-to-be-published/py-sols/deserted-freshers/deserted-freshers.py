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

from collections import deque
def main():
    n, m = get_tuple_ints()
    a = get_list_ints()
    visited = [False for i in range(n)]
    g = [[] for i in range(n)]
    components = [[] for i in range(n)]
    for i in range(m):
        u, v = get_tuple_ints()
        u -= 1
        v -= 1
        g[u].append(v)
        g[v].append(u)
    component = 0
    for v in range(n):
        if visited[v]:
            continue
        q = deque([])
        q.append(v)
        visited[v] = True
        while q:
            v = q.popleft()
            components[component].append(v)
            for u in g[v]:
                if not visited[u]:
                    q.append(u)
                    visited[u] = True
        component += 1
    total_components = component
    indices = sorted([i for i in range(n)], key=lambda x : -a[x])
    components.sort(key=lambda x : -len(x))
    current_rank = 0
    assigned_vertex = [0 for i in range(n)]
    for component in range(total_components):
        for x in components[component]:
            assigned_vertex[indices[current_rank]] = x + 1
            current_rank += 1
    print_iterable(assigned_vertex)
    pass

if __name__ == '__main__':
    main()
