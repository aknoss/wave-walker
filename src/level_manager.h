#ifndef LEVEL_MANAGER_H
#define LEVEL_MANAGER_H

#include "enemy.h"

#define LEVEL_1_PATH "src/levels/level_1.csv"
#define LEVEL_2_PATH "src/levels/level_2.csv"
#define LEVEL_3_PATH "src/levels/level_3.csv"

void loadLevel(EnemyQueue *, const char *levelPath);

#endif // LEVEL_MANAGER_H
