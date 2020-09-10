import collections
from itertools import groupby
import copy

location = collections.namedtuple('location', ['x', 'y', 'dir'])

fopen = open('input12.txt')
T = fopen.readline()
T = int(T)

# global : n, maze
Max = 16    # #define ??
offset = [[0, 1], [1, 0], [0, -1], [-1, 0]]

def readData():
    global n
    n = fopen.readline()
    n = int(n)
    global maze, visit
    maze = [[0 for col in range(n)] for row in range(n)]
    visit = [[[0 for col in range(n)] for row in range(n)] for depth in range(4)]
    for k in range(n):
        line = fopen.readline()
        line = [int(''.join(i)) for is_digit, i in groupby(line, str.isdigit) if is_digit]
        maze[k] = copy.copy(line)
    return n


def loc(pos, sr):
    tmp = location._make((pos.x+offset[(pos.dir + sr) % 4][0], pos.y+offset[(pos.dir + sr) % 4][1], (pos.dir+sr) % 4))
    print(tmp)
    return tmp
    pass


def processing(pos):
    for i in range(M):
        print(maze[i], sep='\n')
    print()
    if (
            pos.x < 0 or pos.x >= n or pos.y < 0 or pos.y >= n or maze[pos.x][pos.y] != 0 or visit[pos.x][pos.y][pos.dir] != 0
    ):
        return False
    if pos.x == n-1 and pos.y == n-1:
        return True
    visit[pos.x][pos.y][pos.dir] = 1
    for i in range(2):
        pawn = loc(pos, i)
        if processing(pawn) is True:
            return True
    return False
    pass


for t in range(0, T):
    M = readData()
    start = location._make((0, 0, 0))
    print(type(start), type(start.x), type(start.y), type(start.dir))
    if processing(start) is True:
        print('yes')
    else:
        print('no')
