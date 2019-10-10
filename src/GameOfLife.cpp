#include <GameOfLife.h>
#include <iostream>
#include <vector>

GameOfLife::GameOfLife(){
	rows = 5;
	cols = 5;
	running = false;

	// make a vector called temp that holds the true's and falses within the vector itself
	std::vector<Cell> temp;

	for (int i = 0; i < rows; i++)
	{
		temp.clear();
		for (int j = 0; j < cols; j++)
		{
			temp.push_back(Cell());
		}
		// we make copies of the temp vector to create two 2d vectors
		// With board being the original board 
		board.push_back(temp);
		// Future board being a temporary copy of the original board
		future_board.push_back(temp);
	}

	// This is the starting position of the board
	// They will show up as black squares on the web app
	// indicating that they're alive cells
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
	// First for loop to check the rows
	for (int i = 1; i < 4; i++)
	{
		// Nested for loop to check the columns
		// it is from 1 to 3
		// This is because it allows us to check the corners of the 5x5 array without a segmentation fault
		for (int j = 1; j < 4; j++)
		{
			// A counter to detect how many live neighbours a certain cell has around it
			alive_neighbours = 0;
			
			//  These 2 for loops help with staying within the 5x5 array
			// The bounds of these for loops help us as stated above to check the corners of the 5x5 array without a segmentation fault
			for (int k = -1; k <= 1; k++)
			{
				for (int l = -1; l <= 1; l++)
				{
					// Checking the neighbours for an alive cell 
					if ((board[i+k][j+l].check_alivedead() == true))
					{
						// if an alive cell is found then we increment the counter by 1
						alive_neighbours++;
					}
				}
			}
			// Checking for duplicate alive neighbours
			if (board[i][j].check_alivedead() == true)
			{
				// If a duplicate alive neighbour is found then we decrement the counter by 1
				alive_neighbours--;
			}
			// check rules of life
			// --------------------------------------------------------
			// Any live cell with fewer than 2 live neighbours dies
			// as if by underpopulation
			if ((board[i][j].check_alivedead() == true) && (alive_neighbours < 2))
			{
				// based on the rule above make future board dead or false in this case
				future_board[i][j].make_Dead();
			}
			// Any live cell with more than 3 live neighbours dies
			// as if by overpopulation
			else if ((board[i][j].check_alivedead() == true) && (alive_neighbours > 3))
			{
				// based on the rule above make future board dead or false in this case
				future_board[i][j].make_Dead();
			}
			// Any dead cell with exactly 3 live neighbours becomes a live cell
			// as if by reproduction
			else if ((board[i][j].check_alivedead() == false) && (alive_neighbours == 3))
			{
				// based on the rule above make future board alive or true in this case
				future_board[i][j].make_Alive();
			}
			// Any live cell with 2 or 3 live neighbours lives on to the next generation
			else
			{
				// copy the contents of the original board at that location to the future board
				future_board[i][j] = board[i][j];
			}
		}
	}
	// Update the board by copying the future boards contents to the original board
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
			// Reads the contents of the original board into a temporary Json
			temp_json.push_back(board[i][j].check_alivedead());
		}
		result.push_back(temp_json);
	}
	return result;
}


