#ifndef RECIPE_H
#define RECIPE_H

#include <list>
#include "Resource.h"

using namespace std;


class Recipe
{
public:
    Recipe();
    Recipe(list<Resource>);
    virtual void showInfo();
    virtual ~Recipe();

private:
    list<Resource> resources;
};

#endif // RECIPE_H
