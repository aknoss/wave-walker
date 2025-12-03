#include "game.h"
#include "raylib.h"
#include <stdbool.h>

static int finishScreen = 0;
Player player;
EnemyWave *waves;
Ground ground;
bool isPlayerOnGround;

void DrawLevel1(void) { DrawRectangleRec(ground.collider, BROWN); }

void InitGameScreen(void) {
  finishScreen = 0;
  isPlayerOnGround = false;

  player.position = (Vector2){100, 400};
  player.collider = (Rectangle){player.position.x, player.position.y, 40, 80};
  ground.collider =
      (Rectangle){0, GetScreenHeight() - 40, GetScreenWidth(), 40};
}

void UpdateCollider(Player *player) {
  player->collider.x = player->position.x;
  player->collider.y = player->position.y;
}

void UpdateGameScreen(void) {
  float deltaTime = GetFrameTime();

  if (CheckCollisionRecs(ground.collider, player.collider)) {
    isPlayerOnGround = true;
  } else {
    isPlayerOnGround = false;
  }
  if (isPlayerOnGround && IsKeyDown(KEY_SPACE)) {
    player.velocity = 4500;
  }
  if (player.velocity > 0) {
    player.position.y -= player.velocity * deltaTime;
    player.velocity -= 200;
  }
  if (!isPlayerOnGround) {
    player.position.y += 600 * deltaTime;
  }
  UpdateCollider(&player);
}

void DrawGameScreen(void) {
  DrawLevel1();
  DrawRectangleRec(player.collider, RED);
}

void UnloadGameScreen(void) {
  // TODO: Unload GAMEPLAY screen variables here!
}

int FinishGameScreen(void) { return finishScreen; }
