// C++ BattleShip Project
// 20142697_권민수
#include "BattleShipMap.h"

BattleShipMap::BattleShipMap(int x, int y)
  :Pane(x,y,MAP_SIZE+3,MAP_SIZE+2)
{
  for(int i=0;i<MAP_SIZE;++i) {
    for(int j=0;j<MAP_SIZE;++j) {
      // map initialization
      m_mapData[i][j] = '0';
    }
  }

  // mvwprintw(m_pWindow, 0, 3, "< MAP >");
}
BattleShipMap::~BattleShipMap() {

}

void BattleShipMap::Draw() {
  wattron(m_pWindow, COLOR_PAIR(1));

  for(int i=0;i<MAP_SIZE;++i) {
    for(int j=0;j<MAP_SIZE;++j) {
      if(m_mapData[i][j] == '0' || m_mapData[i][j] == 'M') {
        wattron(m_pWindow, COLOR_PAIR(1));
        mvwprintw(m_pWindow, i+1, j+2, "%c", m_mapData[i][j]);
        wattroff(m_pWindow, COLOR_PAIR(1));
      }
      else {
        wattron(m_pWindow, COLOR_PAIR(4));
        mvwprintw(m_pWindow, i+1, j+2, "%c", m_mapData[i][j]);
        wattroff(m_pWindow, COLOR_PAIR(4));
      }
    }
  }

  for(int i=0;i<MAP_SIZE;++i) {
    mvprintw(i+m_y+1, m_x-1, "%c", 'A'+i);
    mvprintw(m_y+m_height, m_x+2+i, "%d", 1+i);
  }

  wrefresh(m_pWindow);
}

void BattleShipMap::setMapData(Position pos, char c) {
  m_mapData[pos.getY()][pos.getX()] = c;
}

char BattleShipMap::getMapData(Position pos) {
  return m_mapData[pos.getY()][pos.getX()];
}

char BattleShipMap::shipToChar(const Ship _ship) {
  switch(_ship.getType()) {
    case AIRCRAFT:
      return 'A';
    case BATTLESHIP:
      return 'B';
    case CRUISER:
      return 'C';
    case DESTROYER:
      return 'D';
    case WATER:
      return '0';
  }
}
