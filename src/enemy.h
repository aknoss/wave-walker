#ifndef ENEMY_H
#define ENEMY_H

#include "raylib.h"

typedef struct {
  Vector2 position;
  Rectangle collider;
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

#endif // ENEMY.H
