#ifndef CONSTANTS_HPP
#define CONSTANTS_HPP

using namespace std;
//enum class for the min and max values
enum class extremeValues{
    minItemQuantity = 0,
    maxItemQuantity = 10,
    minAge = 18,
    maxAge = 122,
    minValue = 1, //Don't want to cap item value
    defaultCurrency = 100,
    defaultHealth = 100,
    defaultAttack = 10,
    minAttackBoost = 10,
    minHealthIncrease = 1,
    minLuckIncrease = 1,
    minLuck = 1,
};

#endif