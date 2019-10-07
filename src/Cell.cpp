#include <Cell.h>


Cell::Cell(){
    alive = false;
}

void Cell::make_Dead(){
    alive = false;
}

bool Cell::check_alivedead(){
    return alive;
}


