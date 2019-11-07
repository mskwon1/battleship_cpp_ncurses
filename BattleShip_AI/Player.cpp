// C++ BattleShip Project
// 20142697_권민수

#include "Player.h"

// constructors
Player::Player() {

}
Player::~Player() {

}

// Setters
// 랜덤으로 x,y좌표와 가로,세로 정보를 받아 가능성을 체크한 후 SET
void Player::SetUpShips(Ship* _ships) {
  // SetShipHorz(_ships[0]);
  // SetShipHorz(_ships[0]);
  // m_pMap->setMapData(Position(1,1),_ships[4]);
  for(int i=0;i<5;i++) {
    while(1) {
      // 난수 생성(랜덤)
      int x = rand()*time(NULL) % MAP_SIZE;
      int y = rand()*time(NULL) % MAP_SIZE;
      int direction = (rand()*time(NULL) % 2) + 1;
      bool re = false;

      // 가로로 배치 할 때
      if(direction == 1) {
        if(y+_ships[i].getSize()-1<MAP_SIZE) {
          for(int j=0;j<_ships[i].getSize();j++) {
            if(m_pMap->getMapData(Position(x,y+j)) != '0') {
              re = true;
              break;
            }
          }
          if(re)
            continue;
          else {
            // std::cout << "REACHED" << std::endl;
            _ships[i].setPosition(Position(x,y));
            _ships[i].setDir(0);
            SetShipHorz(_ships[i]);
            break;
          }
        }
        else
          continue;
      }

      // 세로로 배치 할 때
      else if(direction == 2) {
        if(x+_ships[i].getSize()-1<MAP_SIZE) {
          for(int j=0;j<_ships[i].getSize();j++) {
            if(m_pMap->getMapData(Position(x+j,y)) != '0') {
              re = true;
              break;
            }
          }
          if(re)
            continue;
          else {
            _ships[i].setPosition(Position(x,y));
            _ships[i].setDir(1);
            SetShipVert(_ships[i]);
            break;
          }
        }
        else
          continue;
      }
    }
  }
}
// 세로로 SET하는 함수
void Player::SetShipVert(Ship _ship) {
  for(int i=0;i<_ship.getSize();i++) {
    m_pMap->setMapData(Position((_ship.getPos()).getX()+i,(_ship.getPos()).getY()), m_pMap->shipToChar(_ship));
  }
}
// 가로로 SET하는 함수
void Player::SetShipHorz(Ship _ship) {
  for(int i=0;i<_ship.getSize();i++) {
    m_pMap->setMapData(Position((_ship.getPos()).getX(),(_ship.getPos()).getY()+i), m_pMap->shipToChar(_ship));
  }
}

// Utility
void Player::SetHitResult(Position pos, char res) {
  m_pMap->setMapData(pos, res);
}
char Player::Attack(Position pos) {
  switch(m_pMap->getMapData(pos)) {
    case '0':
      return 'M';
    default:
      return 'H';
  }
}
void Player::Init(int sel) {
  if(sel == 0) {
    m_pMap = new BattleShipMap(10,3);
  }
  else {
    m_pMap = new BattleShipMap(10,15);
  }
}
void Player::Render() {
  m_pMap->Draw();
}
