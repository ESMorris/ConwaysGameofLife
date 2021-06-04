#ifndef MYLIB
#define MYLIB

#include <string>
#include <server.h>
#include <Cell.h>

class GameOfLife{

	
public:
	// the running variable is for the start and stop button for the app
	bool running;
	int rows;
	int cols;
	// the alive neighbours variable is a counter to hold how many alive neighbours
	// are next to another live cell
	int alive_neighbours;
	std::vector<std::vector<Cell>> board;
	// this new vector is the future board that holds the changes that occur
	// after the original board vector goes through the game of life rules
	std::vector<std::vector<Cell>> future_board;


	GameOfLife();
	
	void start();

	void stop();

	void advance();

	ucm::json getBoard();
};

#endif
