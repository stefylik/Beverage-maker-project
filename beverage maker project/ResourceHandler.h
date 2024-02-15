#ifndef RESOURCEHANDLER_H
#define RESOURCEHANDLER_H
#include <iostream>
#include <list>
#include "ResourceContainer.h"

using namespace std;

class ResourceHandler
{
public:
    ResourceHandler();
    bool boilWater(int quantity);
    bool grindCoffee(int quantity);
    bool heatMilk(int quantity);
    bool teaQuantity(int quantity);
    void reloadResources();
    bool checkResources();

    void meniu();
    virtual ~ResourceHandler();

private:
    list<ResourceContainer> containers;
};

#endif // RESOURCEHANDLER_H
