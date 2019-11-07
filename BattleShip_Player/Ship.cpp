// C++ BattleShip Project
// 20142697_권민수

#include "Ship.h"
using namespace std;

// constructors
Ship::Ship() {}
Ship::Ship(shipType _type = WATER)
: s_type(_type)
{
  switch(_type) {
    case WATER:
      s_hp = 0;
      s_size = 0;
      break;
    case AIRCRAFT:
      s_hp = 5;
      s_size = 5;
      break;
    case BATTLESHIP:
      s_hp = 4;
      s_size = 4;
      break;
    case CRUISER:
      s_hp = 3;
      s_size = 3;
      break;
    case DESTROYER:
      s_hp = 2;
      s_size = 2;
      break;
  }
}
Ship::~Ship() {

}

// get, set functions
int Ship::getHP() const {
  return s_hp;
}
int Ship::setHP(int _hp) {
  s_hp = _hp;
}
int Ship::getSize() const {
  return s_size;
}
void Ship::setDir(int _dir) {
  s_dir = _dir;
}
int Ship::getDir() const{
  return s_dir;
}
shipType Ship::getType() const {
  return s_type;
}
Position Ship::getPos() const {
  return s_pos;
}
void Ship::setPosition(const Position pos) {
  s_pos = pos;
}
bool Ship::HitCheck(const Position pos) {

}
