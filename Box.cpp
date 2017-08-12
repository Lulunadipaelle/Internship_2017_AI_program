#include "AI.h"

Box::Box()
{
    isEmpty = true;
    color.setPlayer(false);
    
}

void Box::setBox(Player player, bool token) {
    if (token == true) {
        isEmpty = false;
        color.setPlayer(player.getPlayer());
    } else {
        isEmpty = true;
    }
}

bool* Box::getBox() {
    return [isEmpty, color.getPlayer()];
}
/*Box::~Box()
{
}*/

