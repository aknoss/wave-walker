#include "raylib.h"

#ifndef GAME_H
#define GAME_H

typedef struct {
  Vector2 position;
  Rectangle collider;
  int velocity;
} Player;

typedef struct {
  Rectangle collider;
} Ground;
extern Font font;

void InitGameScreen(void);
void UpdateGameScreen(void);
void DrawGameScreen(void);
void UnloadGameScreen(void);
int FinishGameScreen(void);

#endif // GAME_H
