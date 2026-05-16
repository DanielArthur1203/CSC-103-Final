#include "LuckUpItem.hpp"

int LuckUpItem::getLuckIncrease() const{
    return luckIncrease;
}

void LuckUpItem::setLuckIncrease(int luckIncrease){
    this->luckIncrease = luckIncrease;
}

void LuckUpItem::useItem(Player &player){
    int currentPlayerLuck = player.getLuck();
    int itemLuckInc = this->luckIncrease;
    player.setLuck(currentPlayerLuck + itemLuckInc);
    player.decreaseItemQuantity(*this, 1);
}
