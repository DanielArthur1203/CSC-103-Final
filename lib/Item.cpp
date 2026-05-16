#include "Item.hpp"
#include "Player.hpp"
string Item::getItemName() const{
    return itemName;
}

void Item::setItemName(string &itemName){
    this->itemName = itemName;
}

int Item::getValue() const{
    return value;
}

void Item::setValue(int value){
    this->value = value;
}

void Item::useItem(Player &player){
    (void)player;
}
