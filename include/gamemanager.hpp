#ifndef fab_gamemanager
#define fab_gamemanager

class GameManager {
private:
  int score;
  bool dead;

public:
  GameManager() : score(0), dead(false) {}

  void IncrementScore();
  void TriggerDeath();

  void InitLoop();
};

#endif
