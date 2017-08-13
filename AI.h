#ifndef __IA_H__
#define __IA_H__
#include <string>
#include <iostream>



class Player {
    public:
    void setPlayer(bool newPlayer); //Change the active player = new turn
    bool getPlayer(); //Gives the active player
    
    Player();
    
    private:
    bool player;
    
};

class Box {
    public:
    bool Empty; //Indicates if a token is in the box
    void setBox(Player player, bool token); //Play or cancel a play
    bool isEmpty();
    bool whichColor();
    
    Box();
    
    private:
    Player color; //Whose is the token if any
    
};

class Board {
    
    public:
    int getScore(); //Actual Score in the board for the AI
    void setToken(int row, Player player); //Place a Token on the first Box available
    void cancelPlay(int row, Player player); //Cancel last token played in selected row
    Box getBox(int line, int row); //get the box state on selected line and row (empty or not, color of the token)
    Board(Box tab[6][7], int line, int row);
    
    private:
    Box array[6][7];
    
    
};

int Recursive(int depth, Player P, Board board);
int BestPlay(Player P, Board board, int depth);

#endif
