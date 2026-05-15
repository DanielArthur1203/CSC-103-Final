#include "Shop.hpp"
#include "Player.hpp"
#include "Constants.hpp"
#include "AttackUpItem.hpp"
#include "HealthUpItem.hpp"
#include "LuckUpItem.hpp"
#include <iostream>

using namespace std;

Shop::Shop(){
    //Can't think of a less tedious and ugly looking way to do this without giving myself a headache
    //Using a linked list(list<unique_ptr<Item>>) is more work than what it's worth 
    //having to constantly use move() is annoying
    AttackUpItem attackUp1("Rusty Sword", 200, 35);
    AttackUpItem attackUp2("Silver Sword", 300, 65);
    AttackUpItem attackUp3("Legendary Sword", 400, 100);
    HealthUpItem healthUp1("Small Potion", 100, 25);
    HealthUpItem healthUp2("Medium Potion", 150, 50);
    HealthUpItem healthUp3("Large Potion", 200, 100);
    LuckUpItem luckUp("Lucky Charm", 150, 1);

    addItemToShop(attackUp1, 10);
    addItemToShop(attackUp2, 5);
    addItemToShop(attackUp3, 1);
    addItemToShop(healthUp1, 15);
    addItemToShop(healthUp2, 10);
    addItemToShop(healthUp3, 5);
    addItemToShop(luckUp, 20);
}

optional<Item> Shop::getItemFromShop(string &name) const{
    for(auto it = shopInventory.begin(); it != shopInventory.end(); ++it){
        if(it->first->getItemName() == name){
            return *(it->first);
        }
    }
    return nullopt;
}

//only call this if you know the item exists in the shopInventory
int Shop::getItemLocation(Item &item) const{
    int loc = 0;
    for(int i = 0; i < shopInventory.size(); i++){
        if(*(shopInventory.at(i).first) == item){
            loc = i;
            break;
        }
    }
    return loc;
}


void Shop::buyItem(Player &player, string &itemName, int quantity){
    auto item = getItemFromShop(itemName);
    if(item.has_value()){
        if(quantity > to_underlying(extremeValues::minItemQuantity)){
            if(player.getCurrency() >= quantity * item.value().getValue()){ //checking if player has enough currency to buy the item
                int shopIndex = getItemLocation(item.value());
                auto playerIndex = player.getItemIndex(item.value());
                shopInventory.at(shopIndex).second -= quantity; //deduct quantity value from shop list

                if(playerIndex.has_value()){//Not being nullopt implies that the item is already in the player's inventory
                    player.increaseItemQuantity(playerIndex.value(), quantity);
                    player.setCurrency(player.getCurrency() - (quantity * item.value().getValue()));
                }
                else{
                    player.addItem(item.value(), quantity);
                    player.setCurrency(player.getCurrency() - (quantity * item.value().getValue()));
                }
            }
            else{
                cout << "You do not have enough currency to buy " << quantity << " " << itemName << "'s\n";
            }
        }
        else{
            cout << "Please choose a purchase quantity greater than 0\n";
        }
    }
    else{ //If the item doesn't exist in the shopInventory
        cout << "Item with name " << itemName << " does not exist in shop\n";
    }
}

//meant to be a helper for the constructor 
void Shop::addItemToShop(Item &item, int quantity){
    shopInventory.emplace_back(make_unique<Item>(item), quantity);
}

void Shop::printShopInventory(){
    cout << "Shop Inventory: \n";
    for(auto it = shopInventory.begin(); it != shopInventory.end(); ++it){
        cout << it->first->getItemName() << "\t................................\t" << it->second << "\n";
    }
    cout << "\n\n\n";
}
