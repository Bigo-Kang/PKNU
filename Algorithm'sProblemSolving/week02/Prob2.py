from itertools import groupby
import numpy as np
import copy

fopen = open('input02-2.txt', 'r')

T = fopen.readline()
T = int(T)


def readData():
    line = fopen.readline()
    line = [int(''.join(i)) for is_digit, i in groupby(line, str.isdigit) if is_digit]
    N, M = line

    line = fopen.readline()
    data = [int(''.join(i)) for is_digit, i in groupby(line, str.isdigit) if is_digit]

    return N, M, data


def processing(N, M, data):
    result = [1] * N
    test = copy.copy(data)
    minPaper = max(data)
    bl = True
    for i in range(N, M):
        index = test.index(max(test))
        result[index] += 1
        test[index] = data[index] / result[index]
        test[index] = np.ceil(test[index])

        if minPaper > max(test):
            minPaper = max(test)

    for i in range(0, N):
        val = result[i] * minPaper
        if val < data[i]:
            bl = False

    print(int(minPaper)) if bl is True else print(int(minPaper+1))


for t in range(T):
    M, M, data = readData()
    processing(M, M, data)