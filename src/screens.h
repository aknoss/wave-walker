
#include "raylib.h"

#ifndef SCREENS_H
#define SCREENS_H

extern Font font;
extern Music music;
extern Sound fxCoin;

void InitGameplayScreen(void);
void UpdateGameplayScreen(void);
void DrawGameplayScreen(void);
void UnloadGameplayScreen(void);
int FinishGameplayScreen(void);

#ifdef __cplusplus
}
#endif

#endif // SCREENS_H
