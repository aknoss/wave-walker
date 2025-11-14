#include "raylib.h"

#ifndef GAME_H
#define GAME_H

typedef Rectangle Collider;
extern Font font;

void InitGameScreen(void);
void UpdateGameScreen(void);
void DrawGameScreen(void);
void UnloadGameScreen(void);
int FinishGameScreen(void);

#endif // GAME_H
