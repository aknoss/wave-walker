
#include "raylib.h"

#ifndef SCREENS_H
#define SCREENS_H

extern Font font;

void InitGameScreen(void);
void UpdateGameScreen(void);
void DrawGameScreen(void);
void UnloadGameScreen(void);
int FinishGameScreen(void);

#endif // SCREENS_H
