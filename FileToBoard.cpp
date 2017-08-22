#include "AI.h"

using namespace std;

Board FileToBoard(char const *filename) {
    Box source[6][7];
    int stock;
    bool test = true;
    std::cout << test <<endl;
    Player p1,p2;
    p2.setPlayer(false);
    Board board(source, 6, 7);
    ifstream boardFile(filename, ios::in);
    if (boardFile) {
        for (int i=5;i>=0;i--) {
            for (int j =0;j<7;j++) {
                boardFile >> stock;
                std::cout << stock;
                switch (stock) {
                    case 0:
                        board.setBox(i,j,p1,false);
                        
                    break;
                    case 1:
                        board.setBox(i,j,p1,true);
                        
                    break;
                    case 2:
                        board.setBox(i,j,p2,true);
                    break;
                }
            }
        }
        boardFile.close();
    } else {
        cerr << "Error while opening boardFile (FileToBoard)" << endl;
    }
    return board;
}