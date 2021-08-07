import itertools

n, m = map(int, input().split())
names = []
incomp = []
solns = []

for i in range(n):
    names.append(input())

for i in range(m):
    incomp.append(input().split())

if m is 0:
    print(n)
    names.sort()
    for i in names:
        print(i)

else:
    done = False
    for x in range(n, 0, -1):
        poss = list(itertools.combinations(names, x))
        for p in poss:
            if not done:
                bad = 0
                for i in incomp:
                    if (not(i[0] in p and i[1] in p)):
                        num = len(p)
                    else:
                        bad += 1
                if bad is 0:
                    for name in p:
                        solns.append(name)
                        done = True

    print(num)
    solns.sort()
    for name in solns:
        print(name)
