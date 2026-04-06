#ifndef fab_pipe
#define fab_pipe

class Pipe {
  private:
    float timeAlive;
    int gapPosition;

  public:
    float GetTimeAlive();

    void Tick(const float &frameDelta);
    void Render();
    void Awake();
};

#endif
