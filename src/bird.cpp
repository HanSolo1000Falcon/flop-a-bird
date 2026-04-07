#include <algorithm>

#include "bird.hpp"
#include "birdimage.h"
#include "constants.hpp"
#include "raylib.h"

Vector2 Bird::GetPosition() const { return currentPosition; }

void Bird::Tick(const float &frameDelta, const Pipe &closestPipe) {
  const auto gapPosition = closestPipe.GetGapPosition();

  const auto formatted =
      -(closestPipe.GetTimeAlive() - constants::PIPE_LIFE_LENGTH);
  const auto pipeX =
      formatted * (constants::WINDOW_WIDTH / constants::PIPE_LIFE_LENGTH);

  const auto birdLeft = currentPosition.x;
  const auto birdRight = currentPosition.x + constants::BIRD_SIZE;
  const auto birdTop = currentPosition.y;
  const auto birdBottom = currentPosition.y + constants::BIRD_SIZE;

  const auto pipeRight = pipeX + constants::PIPE_WIDTH;
  const auto gapTop = gapPosition - constants::GAP_SIZE / 2;
  const auto gapBottom = gapPosition + constants::GAP_SIZE / 2;

  const bool overlapsX = birdRight > pipeX && birdLeft < pipeRight;
  const bool inGap = birdTop > gapTop && birdBottom < gapBottom;

  if (overlapsX && !inGap) {
    gameManager.TriggerDeath();
  } else if (!overlapsX && overlappedX) {
    gameManager.IncrementScore();
  }

  overlappedX = overlapsX;

  currentVelocity.y += constants::GRAVITY_FORCE * frameDelta;

  if (IsKeyPressed(KEY_SPACE)) {
    currentVelocity.y = -constants::BIRD_JUMP_FORCE;
  }

  currentPosition.x += currentVelocity.x * frameDelta;
  currentPosition.y += currentVelocity.y * frameDelta;
}

void Bird::Render() {
  DrawTexturePro(
      birbTexture,
      (Rectangle){0, 0, (float)birbTexture.width, (float)birbTexture.height},
      (Rectangle){currentPosition.x + constants::BIRD_SIZE / 2.0f,
                  currentPosition.y + constants::BIRD_SIZE / 2.0f,
                  constants::BIRD_SIZE, constants::BIRD_SIZE},
      (Vector2){constants::BIRD_SIZE / 2.0f, constants::BIRD_SIZE / 2.0f},
      std::clamp(currentVelocity.y / 4.0f, -90.0f, 90.0f), WHITE);
}

void Bird::Awake() {
  currentPosition = Vector2(20, 20);
  currentVelocity = Vector2(0, 0);

  auto birbImage =
      LoadImageFromMemory(".png", FlappyBird_png, FlappyBird_png_len);
  birbTexture = LoadTextureFromImage(birbImage);
  UnloadImage(birbImage);
}
