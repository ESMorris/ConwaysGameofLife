#include <GameOfLife.h>
#include <iostream>

GameOfLife::GameOfLife(){

}


void GameOfLife::start(){

}

void GameOfLife::stop(){
	
}

void GameOfLife::advance(){

}

ucm::json GameOfLife::getBoard() const {
	ucm::json result;
	result.push_back({false, false, false, false, false});
	result.push_back({false, false, false, false, false});
	result.push_back({false, true, true, true, false});
	result.push_back({false, false, false, false, false});
	result.push_back({false, false, false, false, false});
	return result;
}


