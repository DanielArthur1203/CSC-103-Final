#include "Player.hpp"
#include "Game.hpp"
#include <iostream>

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
        if(it->first.getItemName() == itemName){
            return it->second;
        }
    }
    return nullopt;
}

optional<int> Player::getItemQuantity(Item &item) const{
    for(auto it = inventory.begin(); it != inventory.end(); ++it){
        if(it->first == item){
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
        if(it->first.getItemName() == itemName){
            return it->first;
        }
    }
    return nullopt;
}

void Player::printInventory() const{
    cout << "Your inventory: \n";
    for(auto it = inventory.begin(); it != inventory.end(); ++it){
        cout << it->first.getItemName() << " ................................ " << it->second << "\n";
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
    pair<Item, int> newItemPair(item, to_underlying(extremeValues::minItemQuantity) + 1); //makes the new item quantity 1
    inventory.push_back(newItemPair);
}

void Player::addItem(Item &item, int quantity){
    pair<Item, int> newItemPair(item, quantity);
    inventory.push_back(newItemPair);
}

void Player::setCurrency(int currency){
    this->currency = currency;
}

optional<int> Player::getItemIndex(Item &item) const{
    for(int i = 0; i < inventory.size(); i++){
        if(inventory.at(i).first == item){
            return i;
        }
    }
    return nullopt;
}
//only use if the index is within range
void Player::increaseItemQuantity(int index, int quantity){
    inventory.at(index).second += quantity;
}

void Player::inventoryCleanup(){
    //TODO Remove an pairs in the inventory that a quantity less than or equal to 0
}
