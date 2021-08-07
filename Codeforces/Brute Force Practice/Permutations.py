import math
import itertools

n, k = map(int, input().split())
orig_list = []
for i in range(n):
    orig_list.append(input())

curr_min = max(list(map(int, orig_list))) - min(list(map(int, orig_list)))

num_list = orig_list.copy()

poss = list(itertools.permutations(range(k)))

for permutation in poss:
    num_list = orig_list.copy()
    for idx,num in enumerate(num_list):
        num = [num[idx] for idx in permutation]
        output = ''
        for x in num:
            output += x
        num_list[idx] = output
#     print(num_list)
    if max(list(map(int, num_list))) - min(list(map(int, num_list))) < curr_min:
        curr_min = max(list(map(int, num_list))) - min(list(map(int, num_list)))
        best_list = num_list
        best_perm = permutation

print(best_perm)
print(best_list)
print(curr_min)
