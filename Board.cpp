#include "AI.h"

Board::Board(Box tab[6][7], int line, int row){
for(int i = 0;i<6;i++){
	for (int j = 0; j<7;j++){
		array[i][j] = tab[i][j];
		}
	}
    //Actual Score in the board for the AI   
}

/*Board::~Board()
{
}*/

int Board::getScore() {
    return 888;
    //TODO Définir le score à la fin
    
}

void Board::setToken(int row, Player player) {
    int i=0;
    while ((i<7) && (!array[i][row].isEmpty())) {
        i++;
    }
    if (i == 6) {
        std::cout << "Error : full row (Board::setToken)";
    } else {
        array[i][row].setBox(player, true);
    }
}
 void Board::cancelPlay(int row, Player player) {
    int i=5;
    while ((i>0) && (array[i][row].isEmpty())) {
        i--;
    }
        array[i][row].setBox(player, false);
    
 }
void Board::setBox(int line, int row, Player player, bool token) {
    array[line][row].setBox(player, token);
}
Box Board::getBox(int line, int row) {
    return this->array[line][row];
}
