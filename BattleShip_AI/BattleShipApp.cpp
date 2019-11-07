// C++ BattleShip Project
// 20142697_권민수
#include "BattleShipApp.h"
#include <iostream>
#include <cstring>

BattleShipApp::BattleShipApp() {

}

BattleShipApp::~BattleShipApp() {

}

void BattleShipApp::Play() {
  initscr();
  mvprintw(1,1,"1) Manual Input mode");
  mvprintw(2,1,"2) AI - random mode");
  mvprintw(3,1,"Please select gamemode : ");
  char mod = getch();
  clear();
  char y, x;
  if(mod == '1') {
    bool end_flag = false;
    Init();
    Render();
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
      if(end_flag) {
        mvprintw(20,40,"GAME OVER!!!!! YOU WIN!!!!!!!!");
        break;
      }
    }
  }
  else if(mod == '2') {
    float turncnt = 0;
    int cnt = 1;
    for(int i=0;i<10;i++) {
      bool end_flag = false;
      Init();
      Render();
      while(1) {
        if(end_flag)
          break;
        noecho();
        wclear(m_pInputPane->getWindow());
        m_pInputPane->Draw();

        char y = 65 + (rand()*time(NULL) % MAP_SIZE);
        char x = 49 + (rand()*time(NULL) % MAP_SIZE);
        char inp[80];
        inp[0] = y, inp[1] = x, inp[2] = ' ', inp[3] = '-', inp[4] = ' ';
        if(m_GM.AttackByInput(y,x)) {
          wclear(m_pInputPane->getWindow());
          m_pInputPane->Draw();
          refresh();
          Update();
          inp[5] = m_GM.getAtt().getBSMap()->getMapData(Position(m_GM.charToX(x),m_GM.charToY(y)));
          mvwaddstr(m_pInputPane->getWindow(),2,10,inp);
          wrefresh(m_pInputPane->getWindow());
          // mvprintw(20,40,"Press Any Key To Continue");
          // getch();
          if(m_GM.EndCheck())
            end_flag = true;
        }
        if(end_flag) {
          mvprintw(20,40,"Try ");
          mvprintw(20,44,"%d",cnt);
          mvprintw(20,46," :");
          mvprintw(20,49,"%d",m_GM.getTurns());
          mvprintw(20,52,"Turns      ");
          mvprintw(21,40,"Press any key to continue...");
          cnt++;
          getch();
          break;
        }
      }
      turncnt += m_GM.getTurns();
      clear();
    }
    turncnt /= 10;
    mvprintw(LINES/2,(COLS/2)-8,"Result: ");
    mvprintw(LINES/2,(COLS/2),"%f",turncnt);
    getch();
  }
  Destroy();
}


void BattleShipApp::Init() {
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
