#ifndef SHOP_HPP
#define SHOP_HPP

#include "Item.hpp"
//#include "Game.hpp"
#include "Player.hpp"
#include <utility>
#include <vector>

using namespace std;

class Shop{
    public:
        Shop();

        optional<Item> getItemFromShop(string &name) const;
        int getItemLocation(Item &item) const;
        void buyItem(Player &player, string &itemName, int quantity);
    private:
        vector<pair<Item, int>> shopInventory; //The int is the quantity of the item
};
#endif