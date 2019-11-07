// C++ BattleShip Project
// 20142697_권민수
#ifndef __INPUTPANE_H__
#define __INPUTPANE_H__
#include <ncurses.h>

#include "Pane.h"
class InputPane : public Pane
{
public:
  InputPane(int x, int y, int width, int height);
  ~InputPane();

  void Draw();
  void Update();
};

#endif //__INPUTPANE_H__
