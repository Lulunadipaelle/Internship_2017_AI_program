#include "AI.h"

using namespace std;


int main(int argc, char **argv)
{
	std::cout << "Hello, World !\n" << endl;
	//Initialiser le board ici
    Box source[6][7];
    Board playboard(source, 6, 7);
    BoardToFile(playboard);
    return 0;
}


int* Recursive(int depth, Player P, Board board, int row) {
    if (depth == 1) { //Conditions d'arrêt du calcul : on ne peut plus jouer ou l'un des joueurs a gagné
        int res[2] ;
        res[0]= board.getScore();
        res[1] = row;
        return res;
    } else {
        return BestPlay(P, board, depth);

    }
}

int* BestPlay(Player P, Board board, int depth) {
    int bestScore = 1;
    int row = -1;
    int res[2] = {bestScore, row};
    for (int i=0;i<=6;i++) {
        //Vérifier que la colonne n'est pas pleine
        if (board.getBox(6,i).isEmpty()==true) {        
            board.setToken(i, P); //On joue dans la colonne non vide
            if (board.getScore() == 100) { //Si on a gagné on renvoie la colonne où on doit jouer et le score pour win
                int score = board.getScore();
                board.cancelPlay(i, P);
                res[0] = score;
                res[1] = i;
                return res;
            } else {
                int score = Recursive(depth-1, P, board, i)[0];
                board.cancelPlay(i, P);
                if (score > bestScore) {
                    bestScore = score;
                    row = i;
                }
            }
        }
    }
    return res;
}

void BoardToFile(Board board) {
    ofstream boardFile("board.txt", ios::out | ios::trunc);
    if (boardFile) {
        for (int i=5;i>=0;i--) {
            for (int j=0;j<7;j++) {
                if (board.getBox(i, j).isEmpty() == true) {
                    boardFile << "0";
                } else {
                    if (board.getBox(i, j).whichColor() == true) {
                        boardFile << "1";
                    } else {
                        boardFile << "2";
                    }
                }
            }
            boardFile << endl;
        }
    } else {
        cerr << "Error while opening boardFile (BoardToFile)";
    }
}