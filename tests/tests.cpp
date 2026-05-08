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
