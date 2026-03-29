# CLAUDE.md

This file provides guidance to Claude Code (claude.ai/code) when working with code in this repository.

## Project

Wave Walker is a 2D side-scrolling platform game (T-Rex runner style) written in C using SDL3.

## Build & Run

```bash
make            # build debug binary to build/game
./build/game    # run the game
make clean      # remove build artifacts
```

Requires SDL3 installed on the system.

Run `clang-format -i <file>` on every changed file before committing.

## Architecture

- **main.c / main.h** — Entry point, SDL3 window/renderer setup, event loop, delta time calculation. Owns the global `window`, `renderer`, and frame loop.
- **game.c / game.h** — Game screen logic: player physics (jump/gravity), enemy spawning from level data, collision detection, and rendering. Defines `Vec2` and `Rect` types used throughout. Uses `SDL_GetKeyboardState` for input.
- **enemy.c / enemy.h** — Linked-list FIFO queue for managing active enemies on screen.
- **scene.h** — Scene framework with `SceneId` enum and `Scene` struct (update/draw function pointers). Not yet wired into main loop.
- **levels/level.h, levels/level_1.c** — Data-driven level definitions. Each level has an array of `EnemyRaw` (height, velocity) and a spawn interval.

### Data flow

Levels define enemy waves → `UpdateGameScreen` spawns enemies into the queue at timed intervals → enemies move left each frame → `DrawGameScreen` renders all active entities as colored rectangles.

### Key patterns

- Delta-time physics throughout (no fixed timestep).
- Custom `Vec2`/`Rect` structs instead of SDL geometry types to keep headers lightweight.
- Global state for player, ground, and enemy queue in game.c.
