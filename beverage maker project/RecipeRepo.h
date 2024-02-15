#ifndef RECIPEREPO_H
#define RECIPEREPO_H
#include <iostream>
#include <string>
#include <list>
#include "Recipe.h"

using namespace std;

class RecipeRepo
{
public:
    RecipeRepo();
    RecipeRepo(string filePath);
    Recipe * getRecipe(string name);
    virtual ~RecipeRepo();

private:
    string filePath;
    list<Recipe*> recipes;
};

#endif // RECIPEREPO_H
