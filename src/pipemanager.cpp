#include <memory>
#include <utility>

#include "constants.hpp"
#include "pipe.hpp"
#include "pipemanager.hpp"
#include "raylib.h"

Pipe *PipeManager::GetNearestPipe(const Vector2 &birdPosition) {
  const auto birdX = birdPosition.x;
  float selectedPipeDiff = 9999;
  Pipe *selectedPipe = nullptr;

  for (const auto &pipe : spawnedPipes) {
    const auto formatted =
        -(pipe->GetTimeAlive() - constants::PIPE_LIFE_LENGTH);
    const auto pipeX =
        formatted * (constants::WINDOW_WIDTH / constants::PIPE_LIFE_LENGTH);
    auto diff = pipeX - birdX;
    if (diff < 0) {
      diff = -diff;
    }
    if (diff < selectedPipeDiff) {
      selectedPipeDiff = diff;
      selectedPipe = pipe.get();
    }
  }
  return selectedPipe;
}

void PipeManager::Tick(const float &frameDelta) {
  pipeSpawnCooldown -= frameDelta;

  if (pipeSpawnCooldown <= 0) {
    auto pipe = std::make_unique<Pipe>();
    pipe->Awake();
    spawnedPipes.emplace_back(std::move(pipe));
    pipeSpawnCooldown = constants::PIPE_SPAWN_COOLDOWN;
  }

  for (const auto &pipe : spawnedPipes) {
    pipe->Tick(frameDelta);
  }

  const auto widthtime = constants::PIPE_WIDTH / (constants::WINDOW_WIDTH /
                                                  constants::PIPE_LIFE_LENGTH);
  std::erase_if(spawnedPipes, [widthtime](const auto &pipe) {
    return pipe->GetTimeAlive() > constants::PIPE_LIFE_LENGTH + widthtime;
  });
}

void PipeManager::Render() {
  for (const auto &pipe : spawnedPipes) {
    pipe->Render();
  }
}
