//
// Created by 강대원 on 2017. 11. 16..
//

#ifndef POS_H
#define POS_H

typedef struct pos {
    int x, y;
} Position;
Position move_to(Position pos, int dir);
#endif //POS_H
