// C++ BattleShip Project
// 20142697_권민수
#include "BattleShipApp.h"
#include <iostream>
#include <cstring>
using namespace std;

BattleShipApp::BattleShipApp() {

}

BattleShipApp::~BattleShipApp() {

}

void BattleShipApp::Play() {
  Init();
  Render();
  keypad(stdscr,true);
  bool end_flag = false;
  char y, x;
  while(1) {
    if(end_flag)
      break;
    echo();
    wclear(m_pInputPane->getWindow());
    m_pInputPane->Draw();
    y = wgetch(m_pInputPane->getWindow());
    x = wgetch(m_pInputPane->getWindow());
    noecho();
    wgetch(m_pInputPane->getWindow());

    if(y >= 65 && y <=72 && x >= 49 && x <= 56 && m_GM.AttackByInput(y,x)) {
      mvprintw(20,40,"                            ");
      refresh();
      Update();
      if(m_GM.EndCheck())
        end_flag = true;
    }
    else {
      mvprintw(20,40,"WRONG INPUT ... please retry");
      refresh();
    }
    if(end_flag)
      break;
  }
  Destroy();
}


void BattleShipApp::Init() {
  initscr();
  start_color();
  cbreak();
  refresh();

  // color setting
  init_pair(1,COLOR_GREEN, COLOR_BLACK);
  init_pair(2,COLOR_CYAN, COLOR_BLACK);
  init_pair(3,COLOR_YELLOW, COLOR_BLACK);
  init_pair(4,COLOR_BLACK, COLOR_WHITE);

  // m_pMap = new BattleShipMap();
  m_GM.Init();
  m_pStatPane = new StatPane(40, 2, 30, 7);
  m_pInputPane = new InputPane(40, 10, 30, 4);
}
void BattleShipApp::Render() {
  mvprintw(1,5,"<< Battle Ship Game >>");

  // m_pMap->Draw();
  m_GM.Render();
  mvprintw(3,14,"%s","DEF");
  mvprintw(15,14,"%s","ATT");
  m_pStatPane->Draw();
  m_pInputPane->Draw();
  move(12,50);

  refresh();
}
void BattleShipApp::Destroy() {
  mvprintw(20,40,"GAME OVER!!!!! YOU WIN!!!!!!!!");
  getch();
  endwin();
  // delete m_pMap;
}

void BattleShipApp::Update() {
  // 턴을 추가하고
  m_GM.addTurns();
  // 업데이트된 mapdata를 Render 한다
  m_GM.Render();
  // 턴 정보 업데이트
  wattron(m_pStatPane->getWindow(), COLOR_PAIR(2));
  mvwprintw(m_pStatPane->getWindow(), 1, 9,"%d", m_GM.getTurns());
  wattroff(m_pStatPane->getWindow(), COLOR_PAIR(2));
  // ncurses window 새로고침
  wrefresh(m_pStatPane->getWindow());
  wrefresh(m_pInputPane->getWindow());
  refresh();
}
