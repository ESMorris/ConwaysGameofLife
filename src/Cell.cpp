#include <Cell.h>


Cell::Cell(){
    alive = false;
}

void Cell::make_Dead(){
    alive = false;
}

void Cell::make_Alive(){
    alive = true;
}

bool Cell::check_alivedead(){
    return alive;
}


