#include "level_manager.h"
#include "enemy.h"
#include "raylib.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void loadLevel(EnemyQueue *enemyQueue, const char *levelPath) {
  FILE *file = fopen(levelPath, "r");
  if (!file) {
    TraceLog(LOG_ERROR, "Error opening file");
    return;
  }

  char line[64];

  // Skip the header
  if (fgets(line, sizeof(line), file) == NULL) {
    TraceLog(LOG_ERROR, "Empty file\n");
    return;
  }

  while (fgets(line, sizeof(line), file)) {
    line[strcspn(line, "\n")] = 0;

    char *t1 = strtok(line, ",");
    char *t2 = strtok(NULL, ",");
    char *t3 = strtok(NULL, ",");

    if (!t1 || !t2 || !t3) {
      TraceLog(LOG_ERROR, "Invalid row, skipping\n");
      continue;
    }

    float height = strtof(t1, NULL);
    float velocity = strtof(t2, NULL);
    float timeToSpawn = strtof(t3, NULL);
    TraceLog(LOG_DEBUG, "%f, %f, %f", height, velocity, timeToSpawn);
  }
}
