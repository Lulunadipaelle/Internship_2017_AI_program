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

int Board::getScoreWinLose(int row, Player P) { // TODO rajouter Player player en entrée pour adapter le score selon le joueur ?
    int line=0;
    int winScore = 2;
    /*if (P.getPlayer() == true) {
        winScore = 2;
    } else if (P.getPlayer() == false) {
        winScore = 2;
    }*/
    for (int i=5;i>=0;i--) {
        if (array[i][row].isEmpty() == false) {
            line = i;
            break;
        }
    }
    //test si on a gagné
    if ((line <3) && (row<=3)) {  // down left
        if ((array[line][row+1].isEmpty() == false) && (array[line][row+1].whichColor() == P.getPlayer()) && (array[line][row+2].isEmpty() == false) && (array[line][row+2].whichColor() == P.getPlayer()) && (array[line][row+3].isEmpty() == false) && (array[line][row+3].whichColor() == P.getPlayer())){
            //std::cout << "down left -> 2";
            return winScore; //  ->
        } else if ((array[line+1][row+1].isEmpty() == false) && (array[line+1][row+1].whichColor() == P.getPlayer()) && (array[line+2][row+2].isEmpty() == false) && (array[line+2][row+2].whichColor() == P.getPlayer()) && (array[line+3][row+3].isEmpty() == false) && (array[line+3][row+3].whichColor() == P.getPlayer())) {
            //std::cout << "down left / 2";
            return winScore; //  /
        } else {
            return 1;
        }
    }
    if ((line <3) && (row >=3)) {  // down right
        if ((array[line][row-1].isEmpty() == false) && (array[line][row-1].whichColor() == P.getPlayer()) && (array[line][row-2].isEmpty() == false) && (array[line][row-2].whichColor() == P.getPlayer()) && (array[line][row-3].isEmpty() == false) && (array[line][row-3].whichColor() == P.getPlayer())){
            //std::cout << "down right <- 2";
            return winScore; //  <-
        } else if ((array[line+1][row-1].isEmpty() == false) && (array[line+1][row-1].whichColor() == P.getPlayer()) && (array[line+2][row-2].isEmpty() == false) && (array[line+2][row-2].whichColor() == P.getPlayer()) && (array[line+3][row-3].isEmpty() == false) && (array[line+3][row-3].whichColor() == P.getPlayer())) {
            //std::cout << "down right / 2";
            return winScore; //  /
        } else {
            return 1;
        }
    }
    if ((line >= 3) && (row <= 3)) { // up left
        if ((array[line][row+1].isEmpty() == false) && (array[line][row+1].whichColor() == P.getPlayer()) && (array[line][row+2].isEmpty() == false) && (array[line][row+2].whichColor() == P.getPlayer()) && (array[line][row+3].isEmpty() == false) && (array[line][row+3].whichColor() == P.getPlayer())){
            //std::cout << "up left -> 2";
            return winScore; //  ->
        } else if ((array[line-1][row+1].isEmpty() == false) && (array[line-1][row+1].whichColor() == P.getPlayer()) && (array[line-2][row+2].isEmpty() == false) && (array[line-2][row+2].whichColor() == P.getPlayer()) && (array[line-3][row+3].isEmpty() == false) && (array[line-3][row+3].whichColor() == P.getPlayer())) {
            //std::cout << "up left / 2";
            return winScore; //  /
        } else if ((array[line-1][row].isEmpty() == false) && (array[line-1][row].whichColor() == P.getPlayer()) && (array[line-2][row].isEmpty() == false) && (array[line-2][row].whichColor() == P.getPlayer()) && (array[line-3][row].isEmpty() == false) && (array[line-3][row].whichColor() == P.getPlayer())){
            //std::cout << "down left | 2";
            return winScore; // |
        } else {
            return 1;
        }
    }
    if ((line >= 3) && (row >= 3)) {  // up right
        if ((array[line][row-1].isEmpty() == false) && (array[line][row-1].whichColor() == P.getPlayer()) && (array[line][row-2].isEmpty() == false) && (array[line][row-2].whichColor() == P.getPlayer()) && (array[line][row-3].isEmpty() == false) && (array[line][row-3].whichColor() == P.getPlayer())){
            //std::cout << "up right <- 2";
            return winScore; //  <-
        } else if ((array[line-1][row-1].isEmpty() == false) && (array[line-1][row-1].whichColor() == P.getPlayer()) && (array[line-2][row-2].isEmpty() == false) && (array[line-2][row-2].whichColor() == P.getPlayer()) && (array[line-3][row-3].isEmpty() == false) && (array[line-3][row-3].whichColor() == P.getPlayer())) {
            //std::cout << "up right / 2";
            return winScore; //  /
        } else if ((array[line-1][row].isEmpty() == false) && (array[line-1][row].whichColor() == P.getPlayer()) && (array[line-2][row].isEmpty() == false) && (array[line-2][row].whichColor() == P.getPlayer()) && (array[line-3][row].isEmpty() == false) && (array[line-3][row].whichColor() == P.getPlayer())){
            //std::cout << "up right | 2";
            return winScore; // |
        } else {
            return 1;
        }
    }
return 1;
    
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
 void Board::cancelPlay(int row) {
     Player p1;
    int i=5;
    while ((i>0) && (array[i][row].isEmpty())) {
        i--;
    }
        array[i][row].setBox(p1, false);
    
 }
void Board::setBox(int line, int row, Player player, bool token) {
    array[line][row].setBox(player, token);
}
Box Board::getBox(int line, int row) {
    return this->array[line][row];
}
