#include "Recipe.h"
#include "Expresso.h"
#include "Cappuccinno.h"
#include "LatteMacchiato.h"
#include "Ceai.h"

using namespace std;

Recipe::Recipe()
{
    //ctor
}

Recipe::Recipe(list<Resource> resource)
{
    resources = resource;
}

void Recipe :: showInfo(){

}

Recipe::~Recipe()
{
    //dtor
}
