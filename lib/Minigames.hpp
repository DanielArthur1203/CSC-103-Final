#ifndef MINIGAMES_HPP
#define MINIGAMES_HPP

class Minigames
{
public:
    Minigames();

    int randomInt(int min, int max);

    int rollD20();
    bool diceCheck(int difficulty, int luck);

    bool luckSave(int luck);

    int drawCard();
    int getChoice(int min, int max);
    int playBlackjackHand(int enemyStandThreshold, int luck);
};

#endif