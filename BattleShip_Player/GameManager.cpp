// C++ BattleShip Project
// 20142697_권민수

#include "GameManager.h"

// constructors
GameManager::GameManager() {
  m_ships[0] = Ship(AIRCRAFT);
  m_ships[1] = Ship(BATTLESHIP);
  m_ships[2] = Ship(CRUISER);
  m_ships[3] = Ship(DESTROYER);
  m_ships[4] = Ship(DESTROYER);
  m_turns = 0;
}
GameManager::~GameManager() {}

// set, get
Ship* GameManager::getShips() {
  return m_ships;
}
Player GameManager::getAtt() {
  return m_Att;
};
Player GameManager::getDef() {
  return m_Def;
}
int GameManager::getTurns() {
  return m_turns;
}

// Utility
int GameManager::charToY(char a) {
  switch(a) {
    case 'A':
      return 0;
    case 'B':
      return 1;
    case 'C':
      return 2;
    case 'D':
      return 3;
    case 'E':
      return 4;
    case 'F':
      return 5;
    case 'G':
      return 6;
    case 'H':
      return 7;
  }
}
int GameManager::charToX(char a) {
  switch(a) {
    case '1':
      return 0;
    case '2':
      return 1;
    case '3':
      return 2;
    case '4':
      return 3;
    case '5':
      return 4;
    case '6':
      return 5;
    case '7':
      return 6;
    case '8':
      return 7;
  }
}
void GameManager::addTurns() {
  m_turns++;
}
bool GameManager::AttackByInput(char _y, char _x) {
  int y = charToY(_y);
  int x = charToX(_x);
  Position pos = Position(x,y);
  // set data
  if(m_Att.getBSMap()->getMapData(pos) != '0')
    return false;
  else {
    m_Att.SetHitResult(pos, m_Def.Attack(pos));
    UpdateHP(pos);
    return true;
  }
}
bool GameManager::UpdateHP(Position pos) {
  for(int i=0;i<5;i++) {
    int hp = m_ships[i].getSize();
    if(m_ships[i].getDir() == 0) {
      for(int j=0;j<m_ships[i].getSize();j++) {
        if(m_Att.getBSMap()->getMapData(Position(m_ships[i].getPos().getX(),m_ships[i].getPos().getY()+j)) == 'H' || (m_Att.getBSMap()->getMapData(Position(m_ships[i].getPos().getX(),m_ships[i].getPos().getY()+j)) == m_Att.getBSMap()->shipToChar(m_ships[i])))
          hp--;
      }
      m_ships[i].setHP(hp);
      if(isDeadShip(m_ships[i])) {
        for(int j=0;j<m_ships[i].getSize();j++) {
          m_Att.getBSMap()->setMapData(Position(m_ships[i].getPos().getX(),m_ships[i].getPos().getY()+j), m_Att.getBSMap()->shipToChar(m_ships[i]));
        }
      }
    }
    else {
      for(int j=0;j<m_ships[i].getSize();j++) {
        if(m_Att.getBSMap()->getMapData(Position(m_ships[i].getPos().getX()+j,m_ships[i].getPos().getY())) == 'H' || (m_Att.getBSMap()->getMapData(Position(m_ships[i].getPos().getX()+j,m_ships[i].getPos().getY())) == m_Att.getBSMap()->shipToChar(m_ships[i])))
          hp--;
      }
      m_ships[i].setHP(hp);
      if(isDeadShip(m_ships[i])) {
        for(int j=0;j<m_ships[i].getSize();j++) {
          m_Att.getBSMap()->setMapData(Position(m_ships[i].getPos().getX()+j,m_ships[i].getPos().getY()), m_Att.getBSMap()->shipToChar(m_ships[i]));
        }
      }
    }
  }
}
bool GameManager::EndCheck() {
  for(int i=0;i<5;i++) {
    if(!(isDeadShip(m_ships[i])))
      return false;
  }
  return true;
}
bool GameManager::isDeadShip(Ship _ship) {
  if(_ship.getHP() == 0)
    return true;
  else
    return false;
}
void GameManager::Init() {
  m_Att.Init(1);
  m_Def.Init(0);
  m_Def.SetUpShips(m_ships);
}
void GameManager::Render() {
  m_Att.Render();
  m_Def.Render();
}
