#ifndef ATTACKUPITEM_HPP
#define ATTACKUPITEM_HPP

#include "Item.hpp"
#include "Player.hpp"

//Inheritance for C++ from here https://www.w3schools.com/cpp/cpp_inheritance.asp
class AttackUpItem : public Item{
    public:
        AttackUpItem(string itemName, int boostValue) : Item(itemName), boostValue(boostValue) {}
        AttackUpItem(string itemName, int value, int boostValue) : Item(itemName, value), boostValue(boostValue){}
        AttackUpItem(){
            Item();
            boostValue = to_underlying(extremeValues::minAttackBoost);
        }
        int getBoostValue() const;
        void setBoostValue(int boostValue);
        //I know override allows for polymorphism
        void useItem(Player &player) override;
    private:
        int boostValue;
};


#endif