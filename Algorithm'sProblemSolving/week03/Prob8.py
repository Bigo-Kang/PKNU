from itertools import groupby

fopen = open('input08.txt')
T = fopen.readline()
T = int(T)


def readData():
    line = fopen.readline()
    line = [int(''.join(i)) for is_digit, i in groupby(line, str.isdigit) if is_digit]
    N, K = line

    data = fopen.readline()
    list(data)
    return N, K, data


def processing(N, K, data):
    count = [0] * 26    # alphabet
    maxCnt = 0
    head = 0
    a = int(ord('A'))
    # print(type(int(ord(data[head]))), type(a))
    for tail in range(N):
        valTail = int(ord(data[tail]))
        count[valTail - a] += 1
        while count[valTail - a] > K:
            valHead = int(ord(data[head]))
            count[valHead - a] -= 1
            head += 1

        length = tail - head + 1
        if length > maxCnt:
            maxCnt = length
    print(maxCnt)
    pass


for t in range(0, T):
    M, K, data = readData()
    processing(M, K, data)
