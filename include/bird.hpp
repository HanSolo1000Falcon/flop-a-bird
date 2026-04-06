#ifndef fab_bird
#define fab_bird

#include <memory>

#include "raylib.h"

class Bird {
  private:
    Vector2 currentPosition;
    Vector2 currentVelocity;
    
  public:
    Vector2 GetPosition() { return currentPosition; }

    void Tick(const float &frameDelta, const std::unique_ptr<Pipe> &closestPipe);
    void Render();
    void Awake();
};

#endif
