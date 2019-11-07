# C++ Battleship Project
# 작성 일자 : 2018-05-28
# 학번 : 20142697 이름 : 권민수

CC = g++
TARGET = BattleShip
SOURCES = BattleShip.cpp \
					BattleShipApp.cpp \
				 	Pane.cpp \
				 	BattleShipMap.cpp \
				 	StatPane.cpp \
				 	InputPane.cpp \
					Ship.cpp \
					Player.cpp \
					GameManager.cpp
LDFLAGS = -lncurses

all :
	$(CC) -o $(TARGET) $(SOURCES) $(LDFLAGS)

clean :
	rm -rf *.o $()
