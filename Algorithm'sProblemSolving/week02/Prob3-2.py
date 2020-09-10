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
    result = []
    # processing
    for i in range(M):
        result.append(data[i])
        if data[i] == X:
            short = 1
            break
        val = sum(result)
        length = len(result)
        if val >= X:
            if short == -1:
                short = length
            elif short > 0 and short > length:
                short = length
        if X > 0 and val < 1:
            result.pop(0)
        while sum(result) > X:
            result.pop(0)


    print(short)
