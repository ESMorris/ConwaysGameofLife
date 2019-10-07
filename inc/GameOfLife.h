#ifndef MYLIB
#define MYLIB

#include <string>
#include <server.h>
#include <Cell.h>

class GameOfLife{
public:
	GameOfLife();
	
	void start();
	void stop();
	void advance();

	ucm::json getBoard() const;

};

#endif
