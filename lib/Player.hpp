#ifndef PLAYER_HPP
#define PLAYER_HPP

#include <string>
#include <vector>
#include <utility>
#include <optional>
#include "Item.hpp"

using namespace std;

class Player{
    public:
        Player(string name, int age) : name(name), age(age){} //member initializer list

        Player(){
            name = "nothing";
            age = 18;
        }

        string getName() const;
        int getAge() const;
        optional<int> getItemQuantity(string itemName) const;
        void printInventory() const;
        void setName(string name);
        void setAge(int age);
        void addItem(Item item);
        void addItem(pair<Item, int>);
    private:
        string name;
        int age;
        vector<pair<Item, int>> inventory; //Holds items and their quantities
};
#endif