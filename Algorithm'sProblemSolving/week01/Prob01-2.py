from itertools import groupby

fopen = open('input01-2.txt', 'r')

T = fopen.readline()
T = int(T)


def readData():
    global N
    global arrive, depart

    line = fopen.readline()
    N = int(line)
    arrive = list(range(N))
    depart = list(range(N))

    for i in range(0, N):
        line = fopen.readline()
        arrive[i], depart[i] = [int(''.join(j)) for is_digit, j in groupby(line, str.isdigit) if is_digit]

    depart.sort()
    # print('arr = %d, dep = %d' %(len(arrive), len(depart)))
    # print('arr = ', arrive, '\t dep = ', depart)
    pass


def processing():
    platform = 1
    for dep in range(0, N-1):
        overlap = 0
        for arr in range(dep + 1, N):
            if arrive[arr] >= depart[dep]:
                break
            overlap += 1

        if platform - 1 < overlap:
            platform = overlap + 1

    print('platform is ', platform)
    pass


for i in range(0, T):
    readData()
    processing()
