#IFNDEF __IA_H__
#DEFINE __IA_H__
#include <stdlib>
#include <string>



class Player {
    Player();
    bool player;
    void setPlayer(bool newPlayer); //Change the active player = new turn
    bool getPlayer(); //Gives the active player
};

class Box {
    Box();
    bool isEmpty; //Indicates if a token is in the box
    Player color; //Whose is the token if any
    void setBox(Player player, bool token); //Play or cancel a play
    bool* getBox();
};

class Board {
    Board(Box** tab);
    Box** array[line][row];
    void getScore(); //Actual Score in the board for the AI
    void setToken(int row, Player player); //Place a Token on the first Box available 
    Box getBox(line, row); //get the box state on selected line and row (empty or not, color of the token)
    
};

int Recursive(int depth, Player P, Board board);
int BestPlay(Player P, Board board, int depth);

#ENDIF