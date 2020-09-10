# 해답
from itertools import groupby
import numpy as np

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
    div = M//N
    upper = max(data) // div
    lower = 1
    minPaper = upper
    box = []
    while lower <= upper:
        mid = lower + (upper - lower)/2
        box[:] = np.ceil([x / mid for x in data])
        count = sum(box)
        if count < M:
            upper = mid - 1
        else:
            if mid < minPaper and count == M:
                minPaper = mid
            lower = mid + 1
    print('minimum is ', round(minPaper))


for t in range(T):
    M, M, data = readData()
    processing(M, M, data)