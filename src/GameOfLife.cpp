#include <GameOfLife.h>
#include <iostream>
#include <vector>

GameOfLife::GameOfLife(){
	rows = 5;
	cols = 5;
	running = false;

	// make a vector called Cell
	std::vector<Cell> temp;

	for (int i = 0; i < rows; i++)
	{
		temp.clear();
		for (int j = 0; j < cols; j++)
		{
			temp.push_back(Cell());
		}
		board.push_back(temp);
	}

	// This is the starting position of the board
	board[2][1].make_Alive();
	board[2][2].make_Alive();
	board[2][3].make_Alive();
}


void GameOfLife::start(){
	running = true;

}

void GameOfLife::stop(){
	running = false;
	
}

void GameOfLife::advance(){
	
	// To advance the board I have to implement the rules of the game of life








}

ucm::json GameOfLife::getBoard(){
	ucm::json result;
	ucm::json temp_json;

	for (int i = 0; i < rows; i++)
	{
		temp_json.clear();
		for (int j = 0; j < cols; j++)
		{
			temp_json.push_back(board[i][j].check_alivedead());
		}
		result.push_back(temp_json);
	}
	return result;
}


