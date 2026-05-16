#ifndef LUCKUPITEM_HPP
#define LUCKUPITEM_HPP

#include "Item.hpp"
#include "Player.hpp"
#include "Constants.hpp"

class LuckUpItem : public Item{
    public:
        LuckUpItem(string itemName, int luckIncrease) : Item(itemName), luckIncrease(luckIncrease) {}
        LuckUpItem(string itemName, int value, int luckIncrease) : Item(itemName, value), luckIncrease(luckIncrease) {}
        LuckUpItem(){
            Item();
            luckIncrease = to_underlying(extremeValues::minLuckIncrease);
        }
        int getLuckIncrease() const;
        void setLuckIncrease(int luckIncrease);
        void useItem(Player &player) override;
    private:
        int luckIncrease;
};

#endif