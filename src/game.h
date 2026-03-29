#ifndef GAME_H
#define GAME_H

#include <SDL3/SDL.h>
#include "scene.h"

typedef struct {
  float x;
  float y;
} Vec2;

typedef struct {
  float x;
  float y;
  float width;
  float height;
} Rect;

typedef struct {
  Vec2 position;
  Rect collider;
  int velocity;
} Player;

typedef struct {
  Rect collider;
} Ground;

Scene GameSceneConstructor(void);

void InitGameScreen(void);
void UpdateGameScreen(void);
void DrawGameScreen(void);
void UnloadGameScreen(void);
int FinishGameScreen(void);

#endif // GAME_H
