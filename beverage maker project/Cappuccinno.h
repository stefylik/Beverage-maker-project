#ifndef CAPPUCCINNO_H
#define CAPPUCCINNO_H
#include "Recipe.h"
#include "Resource.h"
#include <iostream>
#include <list>

class Cappuccinno: public Recipe
{
public:
    Cappuccinno();
    Cappuccinno(list<Resource>, int, int, int, int, int);
    int getGrindDuration();
    int getHeatMilkDuration();
    int getCoffeeQuantity();
    int getMilkQuantity();
    int getWaterQunatity();
    void showInfo() override;
    virtual ~Cappuccinno();
private:
    int grindDuration;
    int boilMilk;
    int coffeeQuantity;
    int milkQuantity;
    int waterQuantity;
};

#endif // CAPPUCCINNO_H
