# BaekJoon 11003
from collections import namedtuple, deque

item = namedtuple('item', ['index', 'value'])

M, L = input().split()
M = int(M)
L = int(L)

deq = deque()

data = input()
data = [int(i) for i in data.split()]

for i in range(M):
    while deq.__len__() > 0 and deq[0].value >= data[i]:
        deq.remove(deq[0])

    deq.appendleft(item(i, data[i]))

    while deq[deq.__len__()-1].index < i-L+1:
        deq.remove(deq[deq.__len__()-1])

    print(deq[deq.__len__()-1].value)
