#ifndef LATTEMACCHIATO_H
#define LATTEMACCHIATO_H

#include "Recipe.h"
#include "Resource.h"
#include <iostream>
#include <list>


class LatteMacchiato: public Recipe
{
public:
    LatteMacchiato();
    LatteMacchiato(list<Resource>, int, int, int, int, int);
    int getGrindDuration();
    int getHeatMilkDuration();
    int getCoffeeQuantity();
    int getMilkQuantity();
    int getWaterQunatity();
    void showInfo() override;
    virtual ~LatteMacchiato();
private:
    int grindDuration;
    int boilMilk;
    int coffeeQuantity;
    int milkQuantity;
    int waterQuantity;
};

#endif // LATTEMACCHIATO_H
