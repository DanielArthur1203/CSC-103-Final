#ifndef HEALTHUPITEM_HPP
#define HEALTHUPITEM_HPP

#include "Item.hpp"
#include "Constants.hpp"
#include "Player.hpp"

class HealthUpItem : public Item{
    public:
        HealthUpItem(string itemName, int healthIncrease) : Item(itemName), healthIncrease(healthIncrease) {}
        HealthUpItem(string itemName, int value, int healthIncrease): Item(itemName, value), healthIncrease(healthIncrease) {}
        HealthUpItem(){
            Item();
            healthIncrease = to_underlying(extremeValues::minHealthIncrease);
        }
        int getHealthIncrease() const;
        void setHealthIncrease(int healthIncrease);
        void useItem(Player &player) override;
    private:
        int healthIncrease;
};

#endif