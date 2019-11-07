// C++ BattleShip Project
// 20142697_권민수

#include "InputPane.h"
#include <iostream>
using namespace std;

InputPane::InputPane(int x, int y, int width, int height)
  :Pane(x, y, width, height)
  {
    // Title
    mvwprintw(m_pWindow, 0, 3, "< INPUT >");
  }
InputPane::~InputPane() {

}

void InputPane::Draw() {
  wattron(m_pWindow, COLOR_PAIR(3));
  box(m_pWindow,0,0);
  mvwprintw(m_pWindow, 0, 3, "< INPUT >");
  mvwprintw(m_pWindow, 1, 2, "Input position...(ex A3)");
  mvwprintw(m_pWindow, 2, 2, "Input : ");
  wattroff(m_pWindow, COLOR_PAIR(3));

  wrefresh(m_pWindow);
}

void InputPane::Update() {

}
