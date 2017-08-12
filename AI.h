#IFNDEF __IA_H__
#DEFINE __IA_H__
#include <stdlib>
#include <string>



class Player {
    Player();
    bool player;
    setPlayer(bool newPlayer); //Change the active player = new turn
    getPlayer(); //Gives the active player
};

class Box {
    Box();
    bool isToken; //Indicates if a token is in the box
    Player color; //Whose is the token if any
};

class Board {
    Board(Box** tab);
    Box** board[line][row];
    void getScore(); //Actual Score in the board for the AI
    void setBox(int row, Player player); //Place a Token on the first Box available 
    void getBox(line, row); //
    
};



#ENDIF