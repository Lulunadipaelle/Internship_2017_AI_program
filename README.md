# Internship_2017_AI_tester

This Project is a AI tester for a Connect 4 game.

The prototypes for all the classes are in AI.h.

-Board class simulates a playboard with boxes to put token.
It contains an array of boxes, getters, a method to play a token on the board, a method to cancel the last play played, and the method which calculates the score of the actual board.

-Method getScoreWinLose :
This method calculates for the actual state of the board the score of the given player :
*If there's 4 token lining up in the board, the method returns the win score 2
*If there isn't it returns 1.
The method checks for each box if there's a token in it, then it tests the alignement regarding the zone of the board the token is in.


-Box class simulates a case of the playboard where a token can be played.
Player class simulates the player for tokens or for turn.


-The main function gets the playboard given by the referee with FileToBoard, then calls the BestPlay function to get the row where to play and give it to the referee.

-The BestPlay function is a recursive function which for each row simulates a play to determine the best row to play. The more is the depth the more accurate and resource consuming is the algorithm. 
If a play is a winning play the algorithm stops and this row is returned.
If a play is a losing play (ie. the other player wins), the winning score is deduced from the score.

-The FileToBoard function takes a .txt file and return a Board object containing the state described by the file.
*The file must be written this way (example) :
0 0 0 0 0 0 0
0 0 0 0 0 0 0
1 0 0 0 0 0 0 
2 1 0 0 0 0 0
1 2 0 0 0 0 0
2 1 0 0 0 0 0
1 = AI
2 = other player.

-The BoardToFile writes in a .txt file a given Board object.