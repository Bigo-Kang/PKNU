T = int(input())

for t in range(T):
    # input
    M, X = input().split()
    M = int(M)
    X = int(X)
    data = input()
    data = [int(i) for i in data.split()]
    # using variable
    short = M + 1
    bl = False
    result = 0
    count = 0
    value = []
    for i in range(M):
        if data[i] >= X:
            short = 1
            break
        value.append(data[i])
        count += 1
        result = sum(value)

        if X > 0 > result:
            value.pop(0)
            count -= 1
            continue

        if result >= X:
            if count < short:
                short = count
            preVal = result
            while result <= preVal and len(value) > 0:
                preVal = result
                result -= value.pop(0)
                count -= 1
            # count += 1


    print('-1') if short == M + 1 else print(short)

