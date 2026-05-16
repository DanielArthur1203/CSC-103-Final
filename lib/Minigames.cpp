#include "Minigames.hpp"
#include <iostream>
#include <cstdlib>

using namespace std;

Minigames::Minigames()
{
    // Nothing needed here for now
}

int Minigames::randomInt(int min, int max)
{ // Standard random function that makes setting a min/max easier
    return rand() % (max - min + 1) + min;
}

int Minigames::rollD20()
{ // Rolls a dice with 20 sides
    return randomInt(1, 20);
}

bool Minigames::diceCheck(int difficulty, int luck) // Rolling dice but factors in enemy and player stats to affect the odds
{
    int roll = rollD20();
    int total = roll + luck;

    cout << "Rolling d20...\n";
    cout << "Roll: " << roll << "\n";

    if (luck > 0)
    {
        cout << "Luck bonus: +" << luck << "\n";
    }

    cout << "Total: " << total << "\n";
    cout << "Difficulty: " << difficulty << "\n";

    if (total >= difficulty)
    {
        cout << "Success!\n";
        return true;
    }

    cout << "Failure.\n";
    return false;
}

bool Minigames::luckSave(int luck) // Saves the player from a negative encounter depending on their luck stat.
{
    if (luck <= 0)
    {
        return false;
    }

    int chance = luck * 3; // Each point in their luck stat increases the chance they are saved by 3%

    if (chance > 25) // The max % chance is capped at 25%
    {
        chance = 25;
    }

    int roll = randomInt(1, 100);

    if (roll <= chance)
    {
        cout << "Lady luck smiles upon you." << endl;
        return true;
    }

    return false;
}

int Minigames::drawCard() // "Draws a card" from a deck (gets a number from 2-11 for blackjack or higher-lower)
{
    return randomInt(2, 11);
}

int Minigames::getChoice(int min, int max)
{
    int choice;

    cout << "> ";
    cin >> choice;

    while (choice < min || choice > max)
    {
        cout << "Enter a number from " << min << " to " << max << ".\n";
        cout << "> ";
        cin >> choice;
    }

    return choice;
}

int Minigames::playBlackjackHand(int enemyStandThreshold, int luck)
{
    int playerTotal = 0;
    int enemyTotal = 0;
    bool playerBust = false;
    bool enemyBust = false;
    bool usedLuckSave = false;

    cout << "\n--- Fate Duel Hand ---\n";

    int card1 = drawCard();
    int card2 = drawCard();
    playerTotal = card1 + card2;

    cout << "You draw: " << card1 << " and " << card2 << "\n";
    cout << "Your total: " << playerTotal << "\n";

    while (!playerBust)
    {
        cout << "\n1. Hit\n";
        cout << "2. Stand\n";

        int choice = getChoice(1, 2);

        if (choice == 1)
        {
            int newCard = drawCard();
            playerTotal += newCard;

            cout << "You draw: " << newCard << "\n";
            cout << "Your total: " << playerTotal << "\n";

            if (playerTotal > 21)
            {
                cout << "You went over 21.\n";

                if (!usedLuckSave && luckSave(luck))
                {
                    usedLuckSave = true;
                    playerTotal -= newCard;

                    cout << "Luck lets you redraw the bust card.\n";

                    newCard = drawCard();
                    playerTotal += newCard;

                    cout << "You redraw: " << newCard << "\n";
                    cout << "Your new total: " << playerTotal << "\n";

                    if (playerTotal > 21)
                    {
                        cout << "You bust.\n";
                        playerBust = true;
                    }
                }
                else
                {
                    cout << "You bust.\n";
                    playerBust = true;
                }
            }
        }
        else
        {
            break;
        }
    }

    if (playerBust)
    {
        return -1;
    }

    cout << "\nEnemy's turn.\n";

    while (enemyTotal < enemyStandThreshold)
    {
        int enemyCard = drawCard();
        enemyTotal += enemyCard;

        cout << "Enemy draws: " << enemyCard << "\n";
        cout << "Enemy total: " << enemyTotal << "\n";

        if (enemyTotal > 21)
        {
            enemyBust = true;
            break;
        }
    }

    if (enemyBust)
    {
        cout << "Enemy busts.\n";
        return 1;
    }

    cout << "\nFinal totals:\n";
    cout << "Your total: " << playerTotal << "\n";
    cout << "Enemy total: " << enemyTotal << "\n";

    if (playerTotal > enemyTotal)
    {
        return 1;
    }
    else if (playerTotal < enemyTotal)
    {
        return -1;
    }

    return 0;
}