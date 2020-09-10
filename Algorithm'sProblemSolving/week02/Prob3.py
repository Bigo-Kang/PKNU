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
    result = 0
    count = 0
    # processing
    for i in range(M):
        result += data[i]
        count += 1

        if result >= X:
            if bl is False:
                bl = True
                short = count
                result = data[i]
                count = 1
            elif bl is True and short > count:
                short = count
                result = data[i]
                count = 1

        if X > 0 > result:
            result = 0
            count = 0

    print(short)
