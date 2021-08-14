t = int(input())

def gcd(a, b):
    if (b == 0):
        return a
    return gcd(b, a % b)

for case in range(t):
    m = int(input())

    k = 1
    kf = 1
    res = list()

    while(True):
        start = int((m * kf) ** (1.0/k))
        if (start <= k): break

        cur = 1

        for i in range(0, 2 * k + 1):
            n = int(start - k + i)
            cur *= n

            if (i + 1 >= k):
                if (cur == m * kf):
                    if (n - k != k):
                        res.insert(0, (n, n - k))
                    res.insert(0, (n, k))

                cur //= n + 1 - k


        k += 1
        kf *= k

    print(len(res))
    for (ni, ki) in res:
        print("({},{})".format(ni, ki), end=" ")
    print()