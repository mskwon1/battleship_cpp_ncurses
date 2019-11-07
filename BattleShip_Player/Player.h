// C++ BattleShip Project
// 20142697_권민수
#ifndef __PLAYER_H__
#define __PLAYER_H__

#include "BattleShipMap.h"
#include <ncurses.h>
#include <cstdlib>
#include <cstdio>
#include <ctime>

class Player {
private:
  BattleShipMap* m_pMap;
public:
  // constructors
  Player();
  ~Player();

  // Setters
  void SetUpShips(Ship* _ships);
  void SetShipHorz(Ship _ship);
  void SetShipVert(Ship _ship);
  BattleShipMap* getBSMap() {
    return m_pMap;
  }

  // Utility
  void SetHitResult(Position pos, char res);
  char Attack(Position pos);
  void Init(int sel);
  void Render();

};

#endif //__PLAYER_H__
