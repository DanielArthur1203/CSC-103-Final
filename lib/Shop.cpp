#include "Shop.hpp"
#include "Player.hpp"
#include <iostream>
using namespace std;

Shop::Shop(){

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
            int index = getItemLocation(item.value());
            
        }
        else{
            cout << "Please choose a purchase quantity greater than 0\n";
        }
    }
    else{ //If the item doesn't exist in the shopInventory
        cout << "Item with name " << itemName << " does not exist in shop\n";
    }
}
