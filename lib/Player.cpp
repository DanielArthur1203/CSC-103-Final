#include "Player.hpp"
#include <optional> 

string Player::getName() const{
    return name;
}

int Player::getAge() const{
    return age;
}

/*I know about optionals from documentation https://en.cppreference.com/cpp/utility/optional
To make it simple this method will return the quantity of an item given as an optional. If the item is not there
the returned optional will be nullopt. Better than return a garbage value like -1.*/
optional<int> Player::getItemQuantity(string itemName) const{
    for(auto it = inventory.begin(); it != inventory.end(); ++it){
        if(it->first.getItemName() == itemName){
            return it->second;
        }
    }
    return std::nullopt;
}


