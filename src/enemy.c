#include "enemy.h"
#include <stdio.h>
#include <stdlib.h>

EnemyQueue *newQueue(void) {
  EnemyQueue *q = (EnemyQueue *)malloc(sizeof(EnemyQueue));
  q->front = q->rear = NULL;
  q->size = 0;
  return q;
}

EnemyNode *newNode(Enemy enemy) {
  EnemyNode *node = (EnemyNode *)malloc(sizeof(EnemyNode));
  node->enemy = enemy;
  node->next = NULL;
  return node;
}

bool isQueueEmpty(EnemyQueue *q) { return q->front == NULL; }

void enqueue(EnemyQueue *q, Enemy enemy) {
  EnemyNode *node = newNode(enemy);

  if (isQueueEmpty(q)) {
    q->front = q->rear = node;
  } else {
    q->rear->next = node;
    q->rear = node;
  }

  q->size++;
}

Enemy dequeue(EnemyQueue *q) {
  if (isQueueEmpty(q)) {
    printf("Error: queue is empty. Cannot dequeue.\n");
    Enemy errorEnemy;
    return errorEnemy;
  }

  EnemyNode *dequeuedNode = q->front;
  Enemy dequeuedEnemy = dequeuedNode->enemy;

  q->front = q->front->next;
  free(dequeuedNode);

  if (q->front == NULL) {
    q->rear = NULL;
  }

  q->size--;
  return dequeuedEnemy;
}
