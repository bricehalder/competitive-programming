from math import sqrt
a,b,c = map(int, input().split())

x = (-b + sqrt(b**2 - 4*a*c)) / (2 * a), (-b - sqrt(b**2 - 4*a*c)) / (2 * a)

print(max(x))
print(min(x))
