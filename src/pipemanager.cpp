#include <iostream>
#include <utility>
#include <memory>

#include "raylib.h"
#include "pipemanager.hpp"
#include "pipe.hpp"
#include "constants.hpp"

std::unique_ptr<Pipe> &PipeManager::GetNearestPipe(const Vector2 &birdPosition) {
  const auto birdX = birdPosition.x;

  for (const auto &pipe : spawnedPipes) {
    
  }
}

void PipeManager::Tick(const float& frameDelta) {
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

  const auto widthtime = constants::PIPE_WIDTH / (constants::WINDOW_WIDTH / constants::PIPE_LIFE_LENGTH);
  std::erase_if(spawnedPipes, [widthtime](const auto& pipe) {
    return pipe->GetTimeAlive() > constants::PIPE_LIFE_LENGTH + widthtime;
  });
}

void PipeManager::Render() {
  for (const auto &pipe : spawnedPipes) {
    pipe->Render();
  }
}
