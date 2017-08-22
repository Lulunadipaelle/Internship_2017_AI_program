#include "AI.h"

using namespace std;


int main(int argc, char **argv)
{
	std::cout << "Hello, World !\n" << endl;
	//Initialiser le board ici
    Player p1, p2;
    p2.setPlayer(false);
    int row;
    Box source[6][7];
    Board playboard(source, 6, 7);
    do {
        for (int i=5;i>=0;i--) {
            for (int j=0;j<7;j++) {
                if (playboard.getBox(i, j).isEmpty() == true) {
                    std::cout << "0 ";
                } else {
                    if (playboard.getBox(i, j).whichColor() == true) {
                        std::cout << "1 ";
                    } else {
                        std::cout << "2 ";
                    }
                }
            }
        std::cout << endl;
        }
        std::cout << "Your turn now ! Give the row where you want to play (between 0 and 6)" << endl;
        cin >> row;
        playboard.setToken(row, p2);        
        std::cout << "Fine, my turn now !" << endl;
        std::pair<int, int> play = BestPlay(p1, playboard, 8);
        
        playboard.setToken(play.second, p1);
        if (play.first >= 2) {
            std::cout << "I won !" << endl;
            break;
        } else if (play.first <= 0) {
            std::cout << "You won !" << endl;
            break;
        } else { 
        BoardToFile(playboard, "playboard.txt");

    
        }
    } while (1);
    
    return 0;
}