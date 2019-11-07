// C++ BattleShip Project
// 20142697_권민수
#ifndef __BATTLESHIPAPP_H__
#define __BATTLESHIPAPP_H__
#include <ncurses.h>
#include "BattleShipMap.h"
#include "StatPane.h"
#include "InputPane.h"
#include "Pane.h"
#include "GameManager.h"

class BattleShipApp {
public:
  BattleShipApp();
  ~BattleShipApp();

  void Play();

protected:
  void Init();
  void Render();
  void Destroy();
  void Update();

protected:
  // BattleShipMap* m_pMap;
  StatPane* m_pStatPane;
  InputPane* m_pInputPane;
  GameManager m_GM;
};

#endif //__BATTLESHIPAPP_H__
