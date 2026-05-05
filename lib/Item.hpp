#ifndef ITEM_HPP
#define ITEM_HPP

#include <string>

using namespace std;

class Item{
    public:
        Item(string itemName) : itemName(itemName){}

        Item(){
            itemName = "nothing";
        }

        string getItemName() const;
        void setItemName(string itemName);
    private:
        string itemName;
};

#endif