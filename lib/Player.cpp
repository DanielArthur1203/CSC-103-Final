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
        cout << it->first.getItemName() << "................................" << it->second;
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
