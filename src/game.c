#include "game.h"
#include "enemy.h"
#include "levels/level.h"
#include "main.h"
#include <SDL3/SDL.h>
#include <stdbool.h>
#include <stdlib.h>

extern float GetDeltaTime(void);

static int finishScreen = 0;
Player player;
Ground ground;
bool isJumping;
EnemyQueue *enemyQueue;
double timeElapsed;
double lastTrigger = 0;
Level *currentLevel;
int currentEnemyIndex = 0;

static bool RectsOverlap(Rect a, Rect b) {
  return a.x < b.x + b.width && a.x + a.width > b.x &&
         a.y < b.y + b.height && a.y + a.height > b.y;
}

void DrawLevel1(void) {
  SDL_FRect r = {ground.collider.x, ground.collider.y, ground.collider.width,
                 ground.collider.height};
  SDL_SetRenderDrawColor(renderer, 139, 69, 19, 255); // BROWN
  SDL_RenderFillRect(renderer, &r);
}

void InitGameScreen(void) {
  finishScreen = 0;
  isJumping = true;
  enemyQueue = newQueue();
  currentLevel = &level_1;

  player.position = (Vec2){100, 400};
  player.collider = (Rect){player.position.x, player.position.y, 40, 80};
  ground.collider = (Rect){0, SCREEN_HEIGHT - 40, SCREEN_WIDTH, 40};
}

void UpdatePlayerCollider(Player *player) {
  player->collider.x = player->position.x;
  player->collider.y = player->position.y;
}

void MoveEnemies(EnemyQueue *enemyQueue, float deltaTime) {
  for (EnemyNode *enemyNode = enemyQueue->front; enemyNode != NULL;
       enemyNode = enemyNode->next) {
    enemyNode->enemy->position.x -=
        (float)enemyNode->enemy->velocity * deltaTime;
    enemyNode->enemy->collider.x = enemyNode->enemy->position.x;
  }
}

void UpdateGameScreen(void) {
  float deltaTime = GetDeltaTime();
  timeElapsed += deltaTime;

  const bool isFirstSpawn = currentEnemyIndex == 0 && timeElapsed > 1.0;

  const bool isReadyToSpawn =
      (((timeElapsed - lastTrigger) >= currentLevel->time_to_spawn) &&
       currentEnemyIndex < currentLevel->enemy_count);

  if (isFirstSpawn || isReadyToSpawn) {
    EnemyRaw *enemyRaw = &currentLevel->enemies[currentEnemyIndex];
    Enemy *enemy = (Enemy *)malloc(sizeof(Enemy));

    enemy->position = (Vec2){800, 400};
    enemy->collider =
        (Rect){enemy->position.x, enemy->position.y, 40, enemyRaw->height};
    enemy->velocity = enemyRaw->velocity;

    enqueue(enemyQueue, enemy);
    currentEnemyIndex++;
    lastTrigger = timeElapsed;
  }

  const bool *keys = SDL_GetKeyboardState(NULL);
  if (!isJumping && keys[SDL_SCANCODE_SPACE]) {
    player.velocity = 2000;
    isJumping = true;
  }

  // Update position if in a jump
  if (player.velocity > 0) {
    player.position.y -= player.velocity * deltaTime;
    player.position.y -= player.velocity * deltaTime;
    player.velocity -= 3000 * deltaTime;
  }

  // Gravity
  player.position.y += 1600 * deltaTime;

  UpdatePlayerCollider(&player);

  if (RectsOverlap(ground.collider, player.collider)) {
    // Rollback player position to contact with ground
    player.position.y =
        ground.collider.y - ground.collider.height - player.collider.height / 2;
    UpdatePlayerCollider(&player);
    isJumping = false;
  }

  MoveEnemies(enemyQueue, deltaTime);
}

void DrawGameScreen(void) {
  DrawLevel1();

  SDL_FRect playerRect = {player.collider.x, player.collider.y,
                          player.collider.width, player.collider.height};
  SDL_SetRenderDrawColor(renderer, 230, 41, 55, 255); // RED
  SDL_RenderFillRect(renderer, &playerRect);

  for (EnemyNode *enemyNode = enemyQueue->front; enemyNode != NULL;
       enemyNode = enemyNode->next) {
    SDL_FRect enemyRect = {
        enemyNode->enemy->collider.x, enemyNode->enemy->collider.y,
        enemyNode->enemy->collider.width, enemyNode->enemy->collider.height};
    SDL_SetRenderDrawColor(renderer, 0, 121, 241, 255); // BLUE
    SDL_RenderFillRect(renderer, &enemyRect);
  }
}

void UnloadGameScreen(void) {
  // TODO: Unload GAMEPLAY screen variables here!
}

int FinishGameScreen(void) { return finishScreen; }
