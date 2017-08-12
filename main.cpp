#include <stdio.h>

using namespace std;
int main(int argc, char **argv)
{
	stdin << "Hello, World !" << endl;
	//Initialiser le board ici
    
    //Box empty = new Box;
    Box** playboard[7][6];
    
    return 0;
}


int Recursive(int depth, Player P, Board board) {
    
    
    if ((depth == 1) || (abs(board.getScore())) = 100) { //Conditions d'arrêt du calcul : on ne peut plus jouer ou l'un des joueurs a gagné
        return board.getScore();
    } else {
        return BestPlay(P, board, depth);

    }
}

int BestPlay(Player P, Board board, int depth) {
    for int (i=0;i<=6;i++) {
        Board newBoard = board;
        if 
        newBoard.setBox(i, P);
        if (P == true) {
                return max(score max actuel, Recursive(depth-1, P, newboard));
            }
        } else {
                return -max( - score max actuel, Recursive(depth-1, P, newboard));
            }
        }
    }
}