#include "raylib.h"

#ifndef GAME_H
#define GAME_H

typedef struct Player {
  Vector2 position;
  Rectangle collider;
} Player;
typedef struct Object {
  Rectangle collider;
} Object;
extern Font font;

void InitGameScreen(void);
void UpdateGameScreen(void);
void DrawGameScreen(void);
void UnloadGameScreen(void);
int FinishGameScreen(void);

#endif // GAME_H
