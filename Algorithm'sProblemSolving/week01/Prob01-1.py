from itertools import groupby

fopen = open('input01-1.txt', 'r')

T = fopen.readline()
T = int(T)


def readData():
    global N, M
    global data

    line = fopen.readline()
    line = [int(''.join(i)) for is_digit, i in groupby(line, str.isdigit) if is_digit]
    N, M = line

    line = fopen.readline()
    data = [int(''.join(i)) for is_digit, i in groupby(line, str.isdigit) if is_digit]
    data.sort()
    pass


def processing():
    listSum = data[M-1] - data[0]
    tail = 0
    min = listSum
    for i in range(M, N):
        tail += 1
        listSum = data[i] - data[tail]
        if listSum < min:
            min = listSum

    print('output is ', min)
    pass


for i in range(0, T):
    readData()
    processing()