#include "Item.hpp"

string Item::getItemName() const{
    return itemName;
}

void Item::setItemName(string itemName){
    this->itemName = itemName;
}
