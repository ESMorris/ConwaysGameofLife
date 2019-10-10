#ifndef MYLIB
#define MYLIB

#include <string>
#include <server.h>
#include <Cell.h>

class GameOfLife{

	
public:
	bool running;
	int rows;
	int cols;
	std::vector<std::vector<Cell>> board;


	GameOfLife();
	
	void start();

	void stop();

	void advance();

	ucm::json getBoard();
};

#endif
