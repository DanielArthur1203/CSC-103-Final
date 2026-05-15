#ifndef SHOP_HPP
#define SHOP_HPP

#include "Item.hpp"
#include "Player.hpp"
#include <memory>
#include <utility>
#include <vector>

using namespace std;

class Shop{
    public:
        Shop();
        optional<Item> getItemFromShop(string &name) const;
        int getItemLocation(Item &item) const;
        void buyItem(Player &player, string &itemName, int quantity);
        void addItemToShop(Item &item, int quantity);
        void printShopInventory();
    private:
        vector<pair<unique_ptr<Item>, int>> shopInventory; //The int is the quantity of the item
};
#endif