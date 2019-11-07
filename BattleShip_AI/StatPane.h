// C++ BattleShip Project
// 20142697_권민수
#ifndef __STATPANE_H__
#define __STATPANE_H__

#include <ncurses.h>
#include "Pane.h"
// window for status
class StatPane : public Pane {
public:
  StatPane(int x, int y, int width, int height);
  ~StatPane();

  void Draw();
};

#endif //__STATPANE_H__
