all: Board.cpp AI.h Box.cpp Player.cpp main.cpp
	g++ Board.cpp AI.h Box.cpp Player.cpp main.cpp -o test
