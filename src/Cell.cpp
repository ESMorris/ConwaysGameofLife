#include <Cell.h>

// This is the starting state for all the cells in the game
// They're set to false
Cell::Cell(){
    alive = false;
}
// Makes a cell false
void Cell::make_Dead(){
    alive = false;
}
// Makes a cell true
void Cell::make_Alive(){
    alive = true;
}
// Basically checks to see if the cell at a certain position is either alive or dead
bool Cell::check_alivedead(){
    return alive;
}


