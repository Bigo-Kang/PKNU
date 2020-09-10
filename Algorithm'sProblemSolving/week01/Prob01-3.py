from itertools import groupby

fopen = open('input01-3.txt', 'r')

T = fopen.readline()
T = int(T)


def readData():
    N = fopen.readline()
    N = int(N)

    line = fopen.readline()
    data = [int(''.join(i)) for is_digit, i in groupby(line, str.isdigit) if is_digit]

    return N, data


def processing(N, data):
    total, headMax, tailMax = 0, 0, 0
    head = 0
    tail = N-1
    while head <= tail:
        if data[head] < data[tail]:
            if headMax < data[head]:
                headMax = data[head]
            else:
                total += headMax - data[head]
            head += 1
        else:
            if data[tail] > tailMax:
                tailMax = data[tail]
            else:
                total += tailMax - data[tail]
            tail -= 1

    print("Water is ", total)
    pass


for i in range(0, T):
    M, data = readData()
    processing(M, data)