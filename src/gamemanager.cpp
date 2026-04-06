#include <cstdlib>
#include <ctime>
#include <memory>

#include "raylib.h"
#include "constants.hpp"
#include "gamemanager.hpp"
#include "pipemanager.hpp"
#include "pipe.hpp"

void GameManager::InitLoop() {
  srand(time(0)); // Initializing the random stuff

  const auto pipeManager = std::make_unique<PipeManager>(*this);

  while (!WindowShouldClose()) {
    const auto frameDelta = GetFrameTime();

    pipeManager->Tick(frameDelta);

    BeginDrawing();
    ClearBackground(SKYBLUE);

    pipeManager->Render();

    EndDrawing();
  }
}
