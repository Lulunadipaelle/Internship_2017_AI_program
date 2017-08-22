#include "AI.h"

std::pair<int, int> BestPlay(Player P, Board board, int depth) {
    int bestScore = -1;
    int row = -1;
    int score = -1;
    //int res[2] = {bestScore, row};
    for (int i=0;i<=6;i++) {
        //Vérifier que la colonne n'est pas pleine
        if (board.getBox(5,i).isEmpty()==true) {        
            board.setToken(i, P); //On joue dans la colonne non vide
            if (board.getScoreWinLose(P) == 2) { //Si on a gagné on renvoie la colonne où on doit jouer et le score pour win
                    score = 2;
                board.cancelPlay(i);
                if (P.getPlayer() == true) {
                    return std::make_pair(score, i);
                } else {
                    return std::make_pair(2-score,i);
                }
            } else { //Sinon on continue de parcourir l'arbre en cherchant le meilleur score
                
                if (depth == 1) {
                    score = board.getScoreWinLose(P);
                    //cout << "score : " << score << endl;
                } else {
                    P.setPlayer(!P.getPlayer());
                    std::pair<int, int> res = BestPlay(P, board, depth-1);
                        score = res.first;
                    P.setPlayer(!P.getPlayer());
                }
                board.cancelPlay(i);
                if (score > bestScore) {
                    bestScore = score;
                    row = i;
                }
            }
        }
    }
    //si le board est plein -> match nul
    if (row ==-1) {
        bestScore = 1;
    }
    if (P.getPlayer() == true) {
        //std::cout << "return : " << bestScore << row << endl;
        return std::make_pair(bestScore, row);
    } else {
        //std::cout << "return : " << 2-bestScore << row << endl;
        return std::make_pair(2-bestScore, row);
    }
}