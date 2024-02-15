#include "LatteMacchiato.h"
#include <iostream>
using namespace std;

LatteMacchiato::LatteMacchiato(list<Resource> resources,int grindduration,int boilmilk,int coffeequantity,int milkquantity,int waterquantity) : Recipe(resources)
{
    grindDuration = grindduration;
    boilMilk = boilmilk;
    coffeeQuantity = coffeequantity;
    milkQuantity = milkquantity;
    waterQuantity = waterquantity;
}

int LatteMacchiato ::getGrindDuration() {
    return grindDuration;
}

int LatteMacchiato::getMilkQuantity() {
    return milkQuantity;
}

int LatteMacchiato::getCoffeeQuantity() {
    return coffeeQuantity;
}

int LatteMacchiato::getHeatMilkDuration() {
    return boilMilk;
}

int LatteMacchiato::getWaterQunatity() {
    return waterQuantity;
}

void LatteMacchiato::showInfo(){
    cout << "Latte Macchiato:"<<"\n";
    cout << "Cantitate cafea: " << LatteMacchiato::getCoffeeQuantity() <<"g" <<"\n";
    cout << "Cantitate lapte: " << LatteMacchiato::getMilkQuantity() << "ml" <<"\n";
    cout << "Cantitate apa: " << LatteMacchiato::getWaterQunatity() <<"ml" <<"\n";
    cout << "Durata de macinare a cafelei: " << LatteMacchiato::getGrindDuration() <<"s" <<"\n";
    cout << "Durata de fierbere a laptelui: " << LatteMacchiato::getHeatMilkDuration() <<"s" <<"\n";
}

LatteMacchiato::~LatteMacchiato()
{
    //dtor
}
