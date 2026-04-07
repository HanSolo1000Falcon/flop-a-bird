#ifndef fab_pipe
#define fab_pipe

#include "raylib.h"

class Pipe {
private:
  float timeAlive;
  int gapPosition;

  Texture2D pipeTexture;

public:
  float GetTimeAlive() const;
  int GetGapPosition() const;

  void Tick(const float &frameDelta);
  void Render();
  void Awake(Texture2D pipeTexture);
};

#endif
