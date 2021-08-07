n = input()
new_n = str(int(n[0] + n[2] + n[4] + n[3] + n[1]) ** 5)

print(new_n[(len(new_n) - 5):])
