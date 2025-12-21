#include "level.h"

static EnemyRaw enemies[] = {
    {100, 10},
    {100, 10},
    {100, 10},
};
const int enemy_count = 3;
const float time_to_spawn = 3;

Level level_1 = {.enemies = enemies,
                 .enemy_count = enemy_count,
                 .time_to_spawn = time_to_spawn};
