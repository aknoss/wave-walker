#ifndef LEVEL_H
#define LEVEL_H

typedef struct {
  const float height;
  const float velocity;
} EnemyRaw;

typedef struct {
  EnemyRaw *enemies;
  const int enemy_count;
  const float time_to_spawn;
} Level;

extern Level level_1;

#endif // LEVEL_H
