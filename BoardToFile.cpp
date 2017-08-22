#include "AI.h"

using namespace std;

void BoardToFile(Board board, char const *filename) {
    ofstream boardFile(filename, ios::out | ios::trunc);
    if (boardFile) {
        for (int i=5;i>=0;i--) {
            for (int j=0;j<7;j++) {
                if (board.getBox(i, j).isEmpty() == true) {
                    boardFile << "0 ";
                } else {
                    if (board.getBox(i, j).whichColor() == true) {
                        boardFile << "1 ";
                    } else {
                        boardFile << "2 ";
                    }
                }
            }
            boardFile << endl;
        }
        boardFile.close();
    } else {
        cerr << "Error while opening boardFile (BoardToFile)" <<endl;
    }
}