#include "HealthUpItem.hpp"

int HealthUpItem::getHealthIncrease() const{
    return healthIncrease;
}

void HealthUpItem::setHealthIncrease(int healthIncrease){
    this->healthIncrease = healthIncrease;
}

void HealthUpItem::useItem(Player &player){
    int playerCurrentHealth = player.getHealth();
    int itemHealthInc = this->healthIncrease;
    player.setHealth(playerCurrentHealth + itemHealthInc);
    player.decreaseItemQuantity(*this, 1);
}
