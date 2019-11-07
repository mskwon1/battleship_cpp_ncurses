// C++ BattleShip Project
// 20142697_권민수
#ifndef __SHIP_H__
#define __SHIP_H__

#include "Position.h"
#include <iostream>

enum shipType {
  WATER,
  AIRCRAFT,
  BATTLESHIP,
  CRUISER,
  DESTROYER
};

class Ship {
public:
  Ship();
  Ship(shipType _type);
  ~Ship();

  int getHP() const;
  int setHP(int _hp);
  int getSize() const;
  void setDir(int _dir);
  int getDir() const;
  shipType getType() const;
  Position getPos() const;

  void setPosition(const Position pos);
  bool HitCheck(const Position pos);

private:
  int s_hp;             // 배의 체력
  int s_size;           // 배의 사이즈(칸)
  int s_dir;            // 배의 방향 (0 = 가로, 1 = 세로)
  shipType s_type;      // 배의 종류
  Position s_pos;       // 배의 TOP-LEFT 포지션
};

#endif //__SHIP_H__
