#ifndef GAME_HPP
#define GAME_HPP

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
    
    private:
};

#endif