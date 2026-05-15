#ifndef PLAYER_HPP
#define PLAYER_HPP

#include <string>
#include <vector>
#include <utility>
#include <optional>
#include <memory>
#include "Item.hpp"
#include "Constants.hpp"
//#include "Game.hpp"

using namespace std;

class Player{
    public:
        Player(string name, int age) : name(name), age(age){
            currency = to_underlying(extremeValues::defaultCurrency);
            luck = to_underlying(extremeValues::minLuck);
            health = to_underlying(extremeValues::defaultHealth);
            attack = to_underlying(extremeValues::defaultAttack);
        } //member initializer list

        Player(){
            name = "nothing";
            //age = 18;
            age = to_underlying(extremeValues::minAge);
            currency = to_underlying(extremeValues::defaultCurrency);
            luck = to_underlying(extremeValues::minLuck);
            health = to_underlying(extremeValues::defaultHealth);
            attack = to_underlying(extremeValues::defaultAttack);
            //currency = 0;
        }

        string getName() const;
        int getAttack() const;
        int getHealth() const;
        int getLuck() const;
        int getAge() const;
        int getCurrency() const;
        int getInventorySize() const;
        optional<int> getItemQuantity(string &itemName) const;
        optional<int> getItemQuantity(Item &item) const;
        optional<Item> getItemFromInventory(string &itemName) const;
        optional<int> getItemIndex(Item &item) const;
        void printInventory() const;
        void setName(string &name);
        void setAttack(int attack);
        void setHealth(int health);
        void setLuck(int luck);
        void setAge(int age);
        void addItem(Item &item);
        void addItem(Item &item, int quantity);
        void increaseItemQuantity(int index, int quantity);
        void decreaseItemQuantity(Item &item, int decrement);
        void setCurrency(int currency);
        void inventoryCleanup();
        void useAnItem(Item &item);
    private:
        string name;
        int attack;
        int health;
        int luck;
        int age;
        int currency; //The amount of "money" the player has
        //I know about smart pointers from here https://en.cppreference.com/cpp/memory/unique_ptr
        //They're safer than raw pointers and follow RAII so they delete when they leave scope
        //Have to use a pointer to prevent slicing and preserve polymorphism
        vector<pair<unique_ptr<Item>, int>> inventory; //Holds items and their quantities
        //Info on pair comes from https://en.cppreference.com/cpp/utility/pair
};
#endif