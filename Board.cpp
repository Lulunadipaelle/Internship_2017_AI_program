#include "AI.h"

Board::Board(Box** tab)
{
    array = tab;
    //Actual Score in the board for the AI

    void setBox(row, player); //Place a Token on the first Box available 
    void getBox(line, row); //    
}

/*Board::~Board()
{
}*/

void Board:: getScore() {
    stdin << "Displaying AI's Score (WIP)" << endl;
    //TODO Définir le score à la fin
    
}

void Board::setToken(int row, Player player) {
 

}

Box Board::getBox(int line, int row) {
    return board[line][row];
}