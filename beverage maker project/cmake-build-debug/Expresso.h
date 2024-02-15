#ifndef EXPRESSO_H
#define EXPRESSO_H

#include "Recipe.h"
#include "Resource.h"
#include <iostream>
#include <list>

using namespace std;


class Expresso: public Recipe
{
public:
    Expresso();
    virtual ~Expresso();
    Expresso(list<Resource>, int, int, int);
    void showInfo() override;
    int getGrindDuration();
    int getCoffeeQuantity();
    int getWaterQunatity();
private:
    int grindDuration;
    int coffeeQuantity;
    int waterQuantity;

};

#endif // EXPRESSO_H
