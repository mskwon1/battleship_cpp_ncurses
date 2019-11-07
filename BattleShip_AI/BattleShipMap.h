// C++ BattleShip Project
// 20142697_권민수
#ifndef __BATTLESHIPMAP_H__
#define __BATTLESHIPMAP_H__
#include <ncurses.h>
#include "Pane.h"
#include "Ship.h"
#include "Position.h"

#define MAP_SIZE 8

class BattleShipMap : public Pane {
public:
  BattleShipMap(int x, int y);
  ~BattleShipMap();

  void Draw();
  void setMapData(Position pos, char c);
  char getMapData(Position pos);
  char shipToChar(const Ship _ship);

protected:
  char m_mapData[MAP_SIZE][MAP_SIZE];
};

#endif //__BATTLESHIPMAP_H__
