#ifndef ITEM_HPP
#define ITEM_HPP

#include "Constants.hpp"
#include <string>
#include <utility>

using namespace std;

//Forward declaration to prevent circular linking
class Player;

class Item{
    public:
        Item(string itemName) : itemName(itemName){}

        Item(string itemName, int value) : itemName(itemName), value(value){}

        Item(){
            itemName = "nothing";
            //value = 100;
            value = to_underlying(extremeValues::minValue);
        }

        //Operator overloading learned from reading this 
        //https://www.codecademy.com/learn/learn-advanced-c-plus-plus/modules/operator-overloading-in-c-plus-plus/cheatsheet
        //Allows for comparison between two Item objects
        bool operator== (const Item &otherItem) const{
            return (this->itemName == otherItem.itemName) && (this->value == otherItem.value);
        }
        string getItemName() const;
        int getValue() const;
        void setItemName(string &itemName);
        void setValue(int value);
        //Learned about virtual from here https://www.w3schools.com/cpp/cpp_virtual_functions.asp
        //Need it so the subclasses override properly
        virtual void useItem(Player &player);
        virtual ~Item() = default;
    private:
        string itemName;
        int value;
};

#endif