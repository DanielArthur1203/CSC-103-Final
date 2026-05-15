#include "AttackUpItem.hpp"

int AttackUpItem::getBoostValue() const{
    return boostValue;
}

void AttackUpItem::setBoostValue(int boostValue){
    this->boostValue = boostValue;
}

void AttackUpItem::useItem(Player &player){
    int playerCurrentAttack = player.getAttack();
    int itemAttackInc = this->boostValue;
    player.setAttack(playerCurrentAttack + itemAttackInc);
    player.decreaseItemQuantity(*this, 1);
}