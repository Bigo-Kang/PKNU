T = int(input())


# def bigK(result, begin, end, base):
#
#     maxVal = 0
#     for k in range(begin, end):




for t in range(T):
    # input
    M, X = input().split()
    M = int(M)
    X = int(X)
    data = input()
    data = [int(i) for i in data.split()]
    data.insert(0, 0)

    sumVal = [0]
    base = 0
    begin = 1
    minLen = M + 1

    for i in range(1, M + 1):
        sumVal[i] = sumVal[i-1] + data[i]
        if  sumVal[i] - base <= 0:
            base = sumVal[i]
            begin = i + 1
        elif sumVal[i] - base >= X:
            k = bigK(sumVal[i]-X, begin, i, base)
            if i - k < minLen:
                minLen = i - k
                base = sumVal[k]
                begin = k + 1

    print(minLen)
