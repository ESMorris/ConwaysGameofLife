#include <GameOfLife.h>
#include <iostream>
#include <vector>

GameOfLife::GameOfLife(){
	rows = 5;
	cols = 5;

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
	 


}


void GameOfLife::start(){

}

void GameOfLife::stop(){
	
}

void GameOfLife::advance(){

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


