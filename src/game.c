#include "game.h"
#include "enemy.h"
#include "levels/level.h"
#include "raylib.h"
#include <stdbool.h>
#include <stdlib.h>

static int finishScreen = 0;
Player player;
Ground ground;
bool isPlayerOnGround;
EnemyQueue *enemyQueue;
double timeElapsed;
double lastTrigger = 0;
Level *currentLevel;
int currentEnemyIndex = 0;

void DrawLevel1(void) { DrawRectangleRec(ground.collider, BROWN); }

void InitGameScreen(void) {
  finishScreen = 0;
  isPlayerOnGround = false;
  enemyQueue = newQueue();
  currentLevel = &level_1;

  player.position = (Vector2){100, 400};
  player.collider = (Rectangle){player.position.x, player.position.y, 40, 80};
  ground.collider =
      (Rectangle){0, GetScreenHeight() - 40, GetScreenWidth(), 40};
}

void UpdatePlayerCollider(Player *player) {
  player->collider.x = player->position.x;
  player->collider.y = player->position.y;
}

void MoveEnemies(EnemyQueue *enemyQueue, float deltaTime) {
  for (EnemyNode *enemyNode = enemyQueue->front; enemyNode != NULL;
       enemyNode = enemyNode->next) {
    TraceLog(LOG_DEBUG, "TEst");
    enemyNode->enemy->position.x +=
        (float)enemyNode->enemy->velocity * deltaTime;
    enemyNode->enemy->collider.x = enemyNode->enemy->position.x;
  }
}

void UpdateGameScreen(void) {
  float deltaTime = GetFrameTime();
  timeElapsed += deltaTime;

  if ((timeElapsed - lastTrigger >= currentLevel->time_to_spawn) &&
      currentEnemyIndex < currentLevel->enemy_count) {
    EnemyRaw *enemyRaw = &currentLevel->enemies[currentEnemyIndex];
    Enemy *enemy = (Enemy *)malloc(sizeof(Enemy));

    enemy->position = (Vector2){800, 400};
    enemy->collider =
        (Rectangle){enemy->position.x, enemy->position.y, 40, enemyRaw->height};

    enqueue(enemyQueue, enemy);
    currentEnemyIndex++;
    lastTrigger = timeElapsed;
  }

  if (CheckCollisionRecs(ground.collider, player.collider)) {
    isPlayerOnGround = true;
  } else {
    isPlayerOnGround = false;
  }
  if (isPlayerOnGround && IsKeyDown(KEY_SPACE)) {
    player.velocity = 2500;
  }
  if (player.velocity > 0) {
    player.position.y -= player.velocity * deltaTime;
    player.velocity -= 3000 * deltaTime;
  }
  if (!isPlayerOnGround) {
    player.position.y += 600 * deltaTime;
  }
  MoveEnemies(enemyQueue, deltaTime);
  UpdatePlayerCollider(&player);
}

void DrawGameScreen(void) {
  DrawLevel1();
  DrawRectangleRec(player.collider, RED);

  for (EnemyNode *enemyNode = enemyQueue->front; enemyNode != NULL;
       enemyNode = enemyNode->next) {
    DrawRectangleRec(enemyNode->enemy->collider, BLUE);
  }
}

void UnloadGameScreen(void) {
  // TODO: Unload GAMEPLAY screen variables here!
}

int FinishGameScreen(void) { return finishScreen; }
