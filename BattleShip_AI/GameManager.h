// C++ BattleShip Project
// 20142697_권민수
#ifndef __GAMEMANAGER_H__
#define __GAMEMANAGER_H__

#include "Player.h"
#include "Ship.h"
const int MAX_SHIPS = 5;

class GameManager {
private:
  Player m_Att;
  Player m_Def;
  Ship m_ships[MAX_SHIPS];
  int m_turns;
public:
  // constructors
  GameManager();
  ~GameManager();

  // set, get
  Ship* getShips();
  Player getAtt();
  Player getDef();
  int getTurns();

  // Utility
  int charToY(char a);
  int charToX(char a);
  void addTurns();
  bool AttackByInput(char _y, char _x);
  bool isDeadShip(Ship _ship);
  void Init();
  void Render();
  bool UpdateHP(Position pos);
  bool EndCheck();

};

#endif //__GAMEMANAGER_H__
