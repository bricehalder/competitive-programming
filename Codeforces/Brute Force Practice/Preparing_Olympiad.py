import itertools

n, l, r, x = map(int, input().split())
diff = [int(i) for i in input().split()]

subsets = []
for i in range(2, n + 1):
    subsets.extend(itertools.combinations(diff, i))

g = [p for p in subsets if sum(p) >= l and sum(p) <= r and (max(p) - min(p) >= x)]

print(len(g))
