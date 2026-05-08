#include <gtest/gtest.h>
#include "Game.hpp"
#include "Item.hpp"
#include "Shop.hpp"
#include "Event.hpp"
#include "Player.hpp"

using namespace std;

/*All knowledge of GoogleTest syntax comes from the documentation
https://google.github.io/googletest/reference/testing.html*/

TEST(PlayerClass, GetItemQuantityNoCrash){
    Player test = Player("test", 18);
    Item testI = Item("Water");
    Item testJ = Item("Thing");
    string name = "Water";
    ASSERT_NO_THROW(test.addItem(testI, 1));
    ASSERT_NO_THROW(test.addItem(testJ));
    EXPECT_EQ(test.getItemQuantity(name), 1);
}

TEST(PlayerClass, GetItemFromInventory){
    Player testP = Player("test", 29);
    Item testI = Item("Sword", 100);
    Item testI2 = Item("Food", 200);
    string name = "Sword";
    ASSERT_NO_THROW(testP.addItem(testI, 10));
    ASSERT_NO_THROW(testP.addItem(testI2, 10));
    EXPECT_EQ(testP.getItemFromInventory(name), testI);
    EXPECT_NE(testP.getItemFromInventory(name), testI2);
}

TEST(PlayerClass, PrintInventory){
    Player testP = Player("test", 35);
    string words[] = {"A", "b", "c", "d", "e", "f", "g"};
    for(int i = 0; i < size(words); i++){
        ASSERT_NO_THROW(testP.printInventory());
        Item item = Item(words[i]);
        testP.addItem(item);
        cout << "\n\n\n";
    }
}

TEST(PlayerClass, IncreaseItemQuantity){
    Player testP = Player();
    Item testI = Item("Sword", 10);
    testP.addItem(testI, 5);
    testP.increaseItemQuantity(testP.getItemIndex(testI).value(), 4);
    EXPECT_EQ(testP.getItemQuantity(testI).value(), 9);
}