#include "AI.h"
using namespace std;
int main(int argc, char **argv)
{
	std::cout << "Hello, World !\n" << endl;
	//Initialiser le board ici
    Box** playboard[7][6];
    
    return 0;
}


int Recursive(int depth, Player P, Board board) {
    
    
    if (depth == 1) { //Conditions d'arrêt du calcul : on ne peut plus jouer ou l'un des joueurs a gagné
        return board.getScore();
    } else {
        return BestPlay(P, board, depth);

    }
}

int BestPlay(Player P, Board board, int depth) {
    int bestScore = 1;
    int row = -1;
    for (int i=0;i<=6;i++) {
        //Vérifier que la colonne n'est pas pleine
        if (board.getBox(6,i).isEmpty()==true) {        
            board.setToken(i, P); //On joue dans la colonne non vide
            if board.getScore() = 100 {
                
            }

/*            if (P.getPlayer() == true) {
                
//                return max(score max actuel, Recursive(depth-1, P, newboard));
            } else {
//                return -max( - score max actuel, Recursive(depth-1, P, newboard));
            }*/
        //annuler le coup
        }
    }
    return 0;
}