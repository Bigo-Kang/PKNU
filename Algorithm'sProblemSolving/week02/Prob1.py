data = []
K, M = input().split()
K = int(K)
M = int(M)

for i in range(K):
    data.append(int(input()))

right = max(data)
left = int(1)
maxLen = 0

while right >= left:
    middle = (right + left) // 2
    count = 0
    for i in range(0, K):
        count += data[i] // middle

    if count >= M:
        left = middle + 1
        if middle > maxLen:
            maxLen = middle
    else:
        right = middle - 1

print(maxLen)

