n = int(input()) + 90 % 360
ans = [n, (n-90) % 360, (n-180) % 360, (n-270) % 360]

for i in range(len(ans)): ans[i] = min(abs(90 - ans[i]), abs(450 - ans[i]))

print(ans.index(min(ans)))
