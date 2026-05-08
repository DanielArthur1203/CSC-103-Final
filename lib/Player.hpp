#ifndef PLAYER_HPP
#define PLAYER_HPP

#include <string>
#include <vector>
#include <utility>
#include <optional>
#include "Item.hpp"
#include "Game.hpp"

using namespace std;

class Player{
    public:
        Player(string name, int age) : name(name), age(age){
            currency = to_underlying(extremeValues::defaultCurrency);
        } //member initializer list

        Player(){
            name = "nothing";
            age = to_underlying(extremeValues::minAge);
            currency = to_underlying(extremeValues::defaultCurrency);
        }

        string getName() const;
        int getAge() const;
        int getCurrency() const;
        optional<int> getItemQuantity(string &itemName) const;
        optional<int> getItemQuantity(Item &item) const;
        optional<Item> getItemFromInventory(string &itemName) const;
        optional<int> getItemIndex(Item &item) const;
        void printInventory() const;
        void setName(string &name);
        void setAge(int age);
        void addItem(Item &item);
        void addItem(Item &item, int quantity);
        void increaseItemQuantity(int index, int quantity);
        void setCurrency(int currency);
        void inventoryCleanup();
    private:
        string name;
        int age;
        int currency; //The amount of "money" the player has
        vector<pair<Item, int>> inventory; //Holds items and their quantities
        //Info on pair comes from https://en.cppreference.com/cpp/utility/pair
};
#endif