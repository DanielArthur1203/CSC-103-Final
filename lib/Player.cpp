#include "Player.hpp"
#include "Game.hpp"
#include <iostream>
#include <algorithm>

using namespace std;

string Player::getName() const{
    return name;
}

int Player::getAge() const{
    return age;
}

int Player::getCurrency() const{
    return currency;
}

/*I know about optionals from documentation https://en.cppreference.com/cpp/utility/optional
To make it simple this method will return the quantity of an item given as an optional. If the item is not there
the returned optional will be nullopt. Better than return a garbage value like -1.*/
optional<int> Player::getItemQuantity(string &itemName) const{
    for(auto it = inventory.begin(); it != inventory.end(); ++it){
        if(it->first->getItemName() == itemName){
            return it->second;
        }
    }
    return nullopt;
}

optional<int> Player::getItemQuantity(Item &item) const{
    for(auto it = inventory.begin(); it != inventory.end(); ++it){
        Item* itemCurr = it->first.get();
        if(*(itemCurr) == item){
            return it->second;
        }
    }
    return nullopt;
}

/// @brief Returns an Item object from the player's inventory if it exists
/// @param itemName 
/// @return If an item with name itemName is in the inventory then return the Item object as an optional<Item>
///otherwise return nullopt
optional<Item> Player::getItemFromInventory(string &itemName) const{
    for(auto it = inventory.begin(); it != inventory.end(); ++it){
        if(it->first->getItemName() == itemName){
            return *(it->first);
        }
    }
    return nullopt;
}

void Player::printInventory() const{
    cout << "Your inventory: \n";
    for(auto it = inventory.begin(); it != inventory.end(); ++it){
        cout << it->first->getItemName() << " ................................ " << it->second << "\n";
    }
}

void Player::setName(string &name){
    this->name = name;
}

void Player::setAge(int age){
    this->age = age;
}

void Player::addItem(Item &item){
    //Info on to_underlying comes from here https://en.cppreference.com/cpp/utility/to_underlying
    //Needs C++23 to work
    inventory.emplace_back(make_unique<Item>(item), to_underlying(extremeValues::minItemQuantity) + 1); //makes the new item quantity 1
}

void Player::addItem(Item &item, int quantity){
    //emplace_back info comes from here https://stackoverflow.com/questions/4303513/push-back-vs-emplace-back
    //Need it since push_back apparently copies when you put in its arguments and I can't copy a unique_ptr
    inventory.emplace_back(make_unique<Item>(item), quantity);
}

void Player::setCurrency(int currency){
    this->currency = currency;
}

optional<int> Player::getItemIndex(Item &item) const{
    for(int i = 0; i < inventory.size(); i++){
        if(*(inventory.at(i).first) == item){
            return i;
        }
    }
    return nullopt;
}
//only use if the index is within range
void Player::increaseItemQuantity(int index, int quantity){
    inventory.at(index).second += quantity;
}

//removes any pairs in inventory that have a quantity of 0
void Player::inventoryCleanup(){
    //Info about how erase_if works comes from here https://en.cppreference.com/cpp/container/vector/erase2
    erase_if(inventory, [](pair<unique_ptr<Item>, int> &p){
        return p.second == 0;
    });
}

int Player::getInventorySize() const{
    return inventory.size();
}

int Player::getAttack() const{
    return attack;
}

void Player::setAttack(int attack){
    this->attack = attack;
}

/*decreases the quantity of an item in the inventory
only use if you know the item is in the inventory and the decrement is
greater than or equal to the item's quantity*/
void Player::decreaseItemQuantity(Item &item, int decrement){
    auto index = getItemIndex(item);
    if(index.has_value()){
        inventory.at(index.value()).second -= decrement;
    }
}

int Player::getHealth() const{
    return health;
}

void Player::setHealth(int health){
    this->health = health;
}

int Player::getLuck() const{
    return luck;
}

void Player::setLuck(int luck){
    this->luck = luck;
}

//only use this if you know the item exists in the inventory
//Do not confuse with useItem from item class
void Player::useAnItem(Item &item){
    item.useItem(*this);
}
