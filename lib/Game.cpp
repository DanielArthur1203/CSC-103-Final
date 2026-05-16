#include <iostream>
#include "Game.hpp"

using namespace std;

void Game::run()
{
    startRun();
    chooseStartingCharm();

    testDiceRoom();

    if (playerDead())
    {
        cout << "\nYou died.\n";
        return;
    }

    testBlackjackRoom();

    if (playerDead())
    {
        cout << "\nYou died.\n";
        return;
    }

    cout << "\nEnd of current test run.\n";
}

void Game::startRun()
{
    string name;
    int age;

    cout << "=== Fatebound Keep ===\n\n";

    cout << "\nWelcome, " << currentPlayer.getName() << ".\n";
    cout << "You wake in the deepest layer of Viridian Keep, the most secure dungeon in all of Viridian Kingdom.\n";
    cout << "Your execution approaches quicker with each passing day, but there is yet hope.\n";
    cout << "The Viridian Kingdom is infamous for one other reason... their greatest vice.\n";
    cout << "Prisoners and guards, peasants and royalty, they all love to gamble.\n";
    cout << "Viridian Keep is no different. Rumour has it that even the most vile of criminals can regain his freedom if he manages to sweep the Warden in a game of chance.\n";
    cout << "But rumours are just that, silly stories to distract the hopeless.\n";
    cout << "That is, until...\n";

    cout << "Enter your character's name: ";
    getline(cin, name);

    cout << "Enter your character's age: ";
    cin >> age;

    currentPlayer.setName(name);
    currentPlayer.setAge(age);
}

void Game::chooseStartingCharm()
{
    cout << "Choose your starting charm:\n";
    cout << "1. Rabbit's Foot: luck\n";
    cout << "2. Rusty Blade: deal more damage in combat\n";
    cout << "3. Measly Coin Purse: gain 30 currency\n";

    int choice = minigames.getChoice(1, 3);

    if (choice == 1)
    {
        cout << "You take the Loaded Die.\n";
        // Still need to add functionality that calculates player's luck based on item.
    }
    else if (choice == 2)
    {
        cout << "You take the Rusty Blade.\n";
        Item blade("Rusty Blade", 10);
        currentPlayer.addItem(blade);
    }
    else
    {
        cout << "You take the Coin Purse.\n";
        currentPlayer.setCurrency(currentPlayer.getCurrency() + 30);
    }
}

void Game::testDiceRoom()
{
    cout << "\n--- Sleeping Guard ---\n";
    cout << "A sleeping guard clutches a pouch of coins.\n";
    cout << "1. Sneak past him. Difficulty 8\n";
    cout << "2. Pickpocket him. Difficulty 16\n";
    cout << "3. Leave him alone.\n";

    int choice = minigames.getChoice(1, 3);

    if (choice == 1)
    {
        if (minigames.diceCheck(8, 0))
        {
            cout << "You sneak past safely.\n";
        }
        else
        {
            cout << "The guard wakes and hits you.\n";
            // currentPlayer.takeDamage(10);
        }
    }
    else if (choice == 2)
    {
        if (minigames.diceCheck(16, 0))
        {
            cout << "You steal 20 currency.\n";
            currentPlayer.setCurrency(currentPlayer.getCurrency() + 20);
        }
        else
        {
            cout << "The guard catches you.\n";
            // currentPlayer.takeDamage(20);
        }
    }
    else
    {
        cout << "You move on quietly.\n";
    }
}

void Game::testBlackjackRoom()
{
    cout << "\n--- Cell Block Duel ---\n";
    blackjackDuel("Prison Guard", 25, 12, 16);
}

void Game::blackjackDuel(string enemyName, int enemyHealth, int enemyDamage, int enemyStandThreshold)
{
    cout << "\n"
         << enemyName << " challenges you to a Fate Duel.\n";

    while (enemyHealth > 0 && !playerDead())
    {
        int result = minigames.playBlackjackHand(enemyStandThreshold, 0);

        if (result == 1)
        {
            int damage = 15;

            string rustyBlade = "Rusty Blade";
            if (currentPlayer.getItemFromInventory(rustyBlade).has_value())
            {
                damage += 3;
            }

            cout << "You deal " << damage << " damage.\n";
            enemyHealth -= damage;

            if (enemyHealth < 0)
            {
                enemyHealth = 0;
            }

            cout << enemyName << " health: " << enemyHealth << "\n";
        }
        else if (result == -1)
        {
            cout << enemyName << " would deal " << enemyDamage << " damage.\n";
            // currentPlayer.takeDamage(enemyDamage);
        }
        else
        {
            cout << "Tie. No damage dealt.\n";
        }
    }

    if (!playerDead())
    {
        cout << "You defeated " << enemyName << ".\n";
        currentPlayer.setCurrency(currentPlayer.getCurrency() + 15);
    }
}

bool Game::playerDead()
{
    // Temporary until Player has health.
    return false;
}