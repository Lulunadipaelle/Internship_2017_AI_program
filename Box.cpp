#include "AI.h"

Box::Box()
{
    Empty = true;
    color = Player();
    
}

void Box::setBox(Player player, bool token) {
    if (token == true) {
        Empty = false;
        color.setPlayer(player.getPlayer());
    } else {
        Empty = true;
    }
}

bool Box::isEmpty() {
    return Empty;
}

bool Box::whichColor() { //à refaire
    return color.getPlayer();
}
/*Box::~Box()
{
}*/

