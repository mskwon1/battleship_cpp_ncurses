// C++ BattleShip Project
// 20142697_권민수

#include "StatPane.h"

StatPane::StatPane(int x, int y, int width, int height)
  :Pane(x,y,width,height)
{
  // Title
  mvwprintw(m_pWindow, 0, 3, "< STATUS >");
}
StatPane::~StatPane() {

}

void StatPane::Draw() {
  wattron(m_pWindow, COLOR_PAIR(2));
  mvwprintw(m_pWindow, 1, 2, "Turn : 0");
  mvwprintw(m_pWindow, 2, 2, "AIRCRAFT : AAAAA");
  mvwprintw(m_pWindow, 3, 2, "BATTLESHIP : BBBB");
  mvwprintw(m_pWindow, 4, 2, "CRUISER : CCC");
  mvwprintw(m_pWindow, 5, 2, "DESTROYER : DD DD");
  wattroff(m_pWindow, COLOR_PAIR(2));

  wrefresh(m_pWindow);
}
