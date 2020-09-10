T = int(input())

for t in range(T):
    # input
    M, X = input().split()
    M = int(M)
    X = int(X)
    data = input()
    data = [int(i) for i in data.split()]
    # using variable
    short = int(-1)
    bl = False
    count = 0
    # processing
    for i in range(M):
        result = 0
        for j in range(i, M):
            result += data[j]

            if result >= X:
                if short > j - i + 1:
                    short = j - i + 1
                    break
    print(short)