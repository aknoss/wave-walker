#include "level.h"

static EnemyRaw enemies[] = {
    {100, 100},
    {100, 100},
    {100, 100},
};
const int enemy_count = 3;
const float time_to_spawn = 1.0;

Level level_1 = {.enemies = enemies,
                 .enemy_count = enemy_count,
                 .time_to_spawn = time_to_spawn};
