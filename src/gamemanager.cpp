#include <cstdlib>
#include <ctime>
#include <memory>
#include <string>

#include "backgroundimage.hpp"
#include "bird.hpp"
#include "constants.hpp"
#include "gamemanager.hpp"
#include "pipemanager.hpp"
#include "raylib.h"

void GameManager::IncrementScore() { ++score; }
void GameManager::TriggerDeath() { dead = true; }

void GameManager::InitLoop() {
  srand(time(0)); // Initializing the random stuff

  const auto backgroundImage = LoadImageFromMemory(
      ".png", FlappyBirdBackground_png, FlappyBirdBackground_png_len);
  const auto backgroundTexture = LoadTextureFromImage(backgroundImage);

  const auto pipeManager = std::make_unique<PipeManager>();
  const auto bird = std::make_unique<Bird>(*this);

  pipeManager->Awake();
  bird->Awake();

  while (!WindowShouldClose()) {
    if (!dead) {
      const auto frameDelta = GetFrameTime();

      pipeManager->Tick(frameDelta);
      auto nearestPipe = pipeManager->GetNearestPipe(bird->GetPosition());
      if (nearestPipe) {
        bird->Tick(frameDelta, *nearestPipe);
      }
    }

    BeginDrawing();
    ClearBackground(SKYBLUE);

    DrawTexturePro(
        backgroundTexture,
        (Rectangle){0,
                    (float)backgroundTexture.height - constants::WINDOW_HEIGHT,
                    constants::WINDOW_WIDTH, constants::WINDOW_HEIGHT},
        (Rectangle){0, 0, constants::WINDOW_WIDTH, constants::WINDOW_HEIGHT},
        (Vector2){0, 0}, 0, WHITE);

    pipeManager->Render();
    bird->Render();

    if (dead) {
      DrawRectangle(0, 0, constants::WINDOW_WIDTH, constants::WINDOW_HEIGHT,
                    Fade(BLACK, 0.8));

      DrawText("YOU DIED",
               constants::WINDOW_WIDTH / 2 - MeasureText("YOU DIED", 150) / 2,
               constants::WINDOW_HEIGHT / 2 - 75, 150, RED);

      const auto scoreText = "SCORE: " + std::to_string(score);
      DrawText(scoreText.c_str(),
               constants::WINDOW_WIDTH / 2 -
                   MeasureText(scoreText.c_str(), 50) / 2,
               constants::WINDOW_HEIGHT / 2 + 95, 50, WHITE);
    } else {
      DrawText(std::to_string(score).c_str(), 20, 20, 80, WHITE);
    }

    EndDrawing();
  }
}
