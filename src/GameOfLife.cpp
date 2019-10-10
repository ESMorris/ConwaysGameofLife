#include <GameOfLife.h>
#include <iostream>
#include <vector>

GameOfLife::GameOfLife(){
	rows = 5;
	cols = 5;
	running = false;

	// make a vector called temp
	std::vector<Cell> temp;

	for (int i = 0; i < rows; i++)
	{
		temp.clear();
		for (int j = 0; j < cols; j++)
		{
			temp.push_back(Cell());
		}
		board.push_back(temp);
		future_board.push_back(temp);
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

	for (int i = 1; i < rows - 1; i++)
	{
		for (int j = 1; j < cols - 1; j++)
		{
			// A counter to detect how many neighbours a certain cell has around it
			alive_neighbours = 0;
			
			for (int k = -1; k <= 1; k++)
			{
				for (int l = -1; l <= 1; l++)
				{
					if ((board[i+k][j+l].check_alivedead() == true))
					{
						alive_neighbours++;
					}
				}
			}
			if (board[i][j].check_alivedead() == true)
			{
				alive_neighbours--;
			}
			// check rules of life
			if ((board[i][j].check_alivedead() == true) && (alive_neighbours < 2))
			{
				future_board[i][j].make_Dead();
			}
			else if ((board[i][j].check_alivedead() == true) && (alive_neighbours > 3))
			{
				future_board[i][j].make_Dead();
			}
			else if ((board[i][j].check_alivedead() == false) && (alive_neighbours == 3))
			{
				future_board[i][j].make_Alive();
			}
			else
			{
				future_board[i][j] = board[i][j];
			}
		}
	}
	board = future_board;
	
	



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


