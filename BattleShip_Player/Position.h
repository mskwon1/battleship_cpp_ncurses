// C++ BattleShip Project
// 20142697_권민수
#ifndef __POSITION_H__
#define __POSITION_H__

class Position {
public:
  Position(int _x = 0, int _y = 0)
    : x(_x), y(_y)
  {}
  ~Position() {}

  Position& operator= (const Position& p) {
    x = p.x;
    y = p.y;
    return (*this);
  }

  bool operator== (const Position pos1) const {
    if(x == pos1.x && y == pos1.y)
      return true;
    else
      return false;
  }

  int getX() {
    return x;
  }

  int getY() {
    return y;
  }

  void setX(int _x) {
    x = _x;
  }

  void setY(int _y) {
    y = _y;
  }

private:
  int x;
  int y;
};

#endif //__POSITION_H__
