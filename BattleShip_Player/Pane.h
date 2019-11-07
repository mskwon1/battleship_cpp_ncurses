// C++ BattleShip Project
// 20142697_권민수
#ifndef __PANE_H__
#define __PANE_H__
#include <ncurses.h>

class Pane {
public:
  Pane(int x, int y, int width, int height);
  virtual ~Pane();

  virtual void Draw();
  WINDOW* getWindow();

protected:
  int m_width, m_height;
  int m_x, m_y;
  WINDOW* m_pWindow;
};

#endif //__PANE_H__
