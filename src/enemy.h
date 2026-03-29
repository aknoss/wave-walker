#ifndef ENEMY_H
#define ENEMY_H

#include "game.h"
#include <stdbool.h>

typedef struct {
  Vec2 position;
  Rect collider;
  float velocity;
} Enemy;

typedef struct EnemyNode {
  Enemy *enemy;
  struct EnemyNode *next;
} EnemyNode;

typedef struct EnemyQueue {
  int size;
  EnemyNode *front;
  EnemyNode *rear;
} EnemyQueue;

EnemyQueue *newQueue(void);
EnemyNode *newNode(Enemy *);
bool isQueueEmpty(EnemyQueue *);
void enqueue(EnemyQueue *, Enemy *);
Enemy *dequeue(EnemyQueue *);

#endif // ENEMY_H
