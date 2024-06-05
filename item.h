#include <bits/stdc++.h>
#pragma once
using namespace std;

class Item {
protected:
    string name;
    string emoji;
    int damage;
    int heal;
    double hitRate;
    int quantity;
    bool unlocked;
public:
    Item();
    Item(string, int, double, bool);
    Item(string, int, double, int);
    virtual int getDamage();
    virtual double getHitRate();
    virtual string getName();
    virtual string getEmoji();
    virtual bool getUnlocked();
    virtual int getQuantity();
    virtual int getHeal();
    virtual void setDamage(int);
    virtual void setHitRate(double);
    virtual void setName(string);
    virtual void setEmoji(string);
    virtual void setUnlocked(bool);
    virtual void setQuantity(int);
    virtual void setHeal(int);
};
