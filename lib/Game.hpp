#ifndef GAME_HPP
#define GAME_HPP

#include "Player.hpp"
#include "Shop.hpp"
#include <memory>

using namespace std;
//enum class for the min and max values
enum class extremeValues{
    minItemQuantity = 0,
    maxItemQuantity = 10,
    minAge = 18,
    maxAge = 122,
    minValue = 1, //Don't want to cap item value
    defaultCurrency = 100,
};

//Info on enum classes came from here https://en.cppreference.com/cpp/language/enum
class Game{
    public:
        Game() = default;
    private:
        Player currentPlayer;
        Shop currentShop; 
        //essentially a "save" system for this game where the user can "reload"
        unique_ptr<Game[]> saveArray = make_unique<Game[]>(3);
};

#endif