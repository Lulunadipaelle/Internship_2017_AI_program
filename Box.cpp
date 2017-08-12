#include "AI.h"

Box::Box()
{
    isEmpty = true;
    color = Player();
    
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
    bool res[2] = {isEmpty, color.getPlayer()};
    return res;
}
/*Box::~Box()
{
}*/

