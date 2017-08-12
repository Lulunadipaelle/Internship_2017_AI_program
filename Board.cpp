#include "AI.h"

Board::Board(Box** tab[6][7], int line, int row)
{
    array = tab;
    //Actual Score in the board for the AI
   
}

/*Board::~Board()
{
}*/

int Board:: getScore() {
    return 888;
    //TODO Définir le score à la fin
    
}

void Board::setToken(int row, Player player) {
 

}

Box Board::getBox(int line, int row) {
    return array[line][row];
}