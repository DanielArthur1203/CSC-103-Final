#include "Shop.hpp"
#include "Player.hpp"
#include <iostream>

using namespace std;

Shop::Shop(){
    //TODO There should only be one shop instance so need to instantiate a bunch of Item objects and add then to inventory
}

optional<Item> Shop::getItemFromShop(string &name) const{
    for(auto it = shopInventory.begin(); it != shopInventory.end(); ++it){
        if(it->first.getItemName() == name){
            return it->first;
        }
    }
    return nullopt;
}

//only call this if you know the item exists in the shopInventory
int Shop::getItemLocation(Item &item) const{
    int loc = 0;
    for(int i = 0; i < shopInventory.size(); i++){
        pair<Item, int> test = shopInventory.at(i);
        if(test.first == item){
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
                shopInventory.at(shopIndex).second--; //deduct quantity value from shop list

                if(playerIndex.has_value()){//Not being nullopt implies that the item is already in the player's inventory
                    player.increaseItemQuantity(playerIndex.value(), quantity);
                    player.setCurrency(player.getCurrency() - (quantity * item.value().getValue()));
                }
                else{
                    player.addItem(item.value(), quantity);
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
