#include <cstdlib>
#include <ctime>
#include <memory>

#include "raylib.h"
#include "constants.hpp"
#include "gamemanager.hpp"
#include "pipemanager.hpp"
#include "pipe.hpp"
#include "bird.hpp"

void GameManager::InitLoop() {
  srand(time(0)); // Initializing the random stuff

  const auto pipeManager = std::make_unique<PipeManager>(*this);
  const auto bird = std::make_unique<Bird>();

  bird->Awake();

  while (!WindowShouldClose()) {
    const auto frameDelta = GetFrameTime();

    pipeManager->Tick(frameDelta);
    bird->Tick(frameDelta, pipeManager->GetNearestPipe(bird->GetPosition));

    BeginDrawing();
    ClearBackground(SKYBLUE);

    pipeManager->Render();

    EndDrawing();
  }
}
