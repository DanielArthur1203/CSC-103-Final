#ifndef GAME_HPP
#define GAME_HPP

#include "Player.hpp"
#include "Shop.hpp"
#include "Minigames.hpp"
#include <string>

using namespace std;

class Game
{
public:
    Game() = default;
    void run();

private:
    Player currentPlayer;
    Shop currentShop;
    Minigames minigames;

    void startRun();
    void chooseStartingCharm();

    void testDiceRoom();
    void testBlackjackRoom();

    void blackjackDuel(string enemyName, int enemyHealth, int enemyDamage, int enemyStandThreshold);

    bool playerDead();
};

#endif