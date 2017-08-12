#include "AI.h"

Player::Player()
{
    player = true;
}

/*Player::~Player()
{
}*/

void Player::setPlayer(bool newPlayer) {
    player = newPlayer;
}

bool Player::getPlayer() {
    return player;
}
