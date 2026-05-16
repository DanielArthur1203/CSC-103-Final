#include <gtest/gtest.h>
#include <optional>
#include "Game.hpp"
#include "Item.hpp"
#include "Shop.hpp"
#include "Event.hpp"
#include "Player.hpp"
#include "HealthUpItem.hpp"
#include "LuckUpItem.hpp"
#include "AttackUpItem.hpp"

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

TEST(PlayerClass, GetItemQuantityProperNullopt){
    Player test = Player();
    string name = "Water";
    EXPECT_EQ(test.getItemQuantity(name), nullopt);
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

//Need to debug this test to see the output
TEST(PlayerClass, PrintInventory){
    Player testP = Player("test", 35);
    string words[] = {"A", "b", "c", "d", "e", "f", "g"};
    for(int i = 0; i < size(words); i++){
        ASSERT_NO_THROW(testP.printInventory());
        Item item = Item(words[i]);
        testP.addItem(item);
    }
}

TEST(PlayerClass, IncreaseItemQuantity){
    Player testP = Player();
    Item testI = Item("Sword", 10);
    testP.addItem(testI, 5);
    testP.increaseItemQuantity(testP.getItemIndex(testI).value(), 4);
    EXPECT_EQ(testP.getItemQuantity(testI).value(), 9);
}

TEST(PlayerClass, InventoryCleanupWorks){
    Player testP = Player();
    ASSERT_EQ(testP.getInventorySize(), 0);
    Item testI = Item("Sword", 100);
    testP.addItem(testI, 0);
    ASSERT_EQ(testP.getInventorySize(), 1);
    testP.inventoryCleanup();
    EXPECT_EQ(testP.getInventorySize(), 0);
}

TEST(ItemSubclasses, HealthUpWorks){
    Player testP = Player();
    HealthUpItem potion("Potion", 250, 50);
    Item &test = potion;
    string name = "Potion";
    ASSERT_NO_THROW(testP.addItem(test, 1));
    ASSERT_EQ(testP.getInventorySize(), 1);

    EXPECT_NE(testP.getItemFromInventory(name), nullopt);
    ASSERT_NE(testP.getItemIndex(test), nullopt);

    testP.useAnItem(test);
    EXPECT_EQ(testP.getHealth(), 150);
}

TEST(ItemSubclasses, LuckUpWorks){
    Player testP = Player();
    LuckUpItem charm("Charm", 500, 30);
    Item &testItem = charm;

    testP.useAnItem(testItem);
    EXPECT_EQ(testP.getLuck(), 31);
}

TEST(ItemSubclasses, AttackUpWorks){
    Player testP = Player();
    AttackUpItem sword("Sword", 1000, 200);
    Item &testItem = sword;

    testP.useAnItem(testItem);
    EXPECT_EQ(testP.getAttack(), 210);
}

//Debug test to see output
TEST(ShopClass, PrintShopInventory){
    Shop shop = Shop();
    ASSERT_NO_THROW(shop.printShopInventory());
}

TEST(ShopClass, BuyItemWorks){
    Shop shop = Shop();
    Player testP = Player();
    string name = "Rusty Sword";
    testP.setCurrency(1000);

    shop.printShopInventory();
    ASSERT_NO_THROW(shop.buyItem(testP, name, 3));
    EXPECT_EQ(testP.getInventorySize(), 1);
    EXPECT_EQ(testP.getCurrency(), 400);
    EXPECT_EQ(testP.getItemQuantity(name), 3);
    EXPECT_NE(testP.getItemFromInventory(name), nullopt);
    shop.printShopInventory();
}