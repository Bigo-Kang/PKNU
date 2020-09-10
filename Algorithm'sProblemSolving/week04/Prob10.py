import itertools

M, K = input().split()
M = int(M)
K = int(K)

data = list(itertools.combinations(range(1, M + 1), K))

for i in data:
    for j in i:
        print(j, end=' ')
    print()
