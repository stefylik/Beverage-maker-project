#include "Cappuccinno.h"
#include <iostream>
using namespace std;

Cappuccinno::Cappuccinno(list<Resource> resources,int grindduration,int boilmilk,int coffeequantity,int milkquantity,int waterquantity) : Recipe(resources)
{
    grindDuration = grindduration;
    boilMilk = boilmilk;
    coffeeQuantity = coffeequantity;
    milkQuantity = milkquantity;
    waterQuantity = waterquantity;
}

int Cappuccinno ::getGrindDuration() {
    return grindDuration;
}

int Cappuccinno::getMilkQuantity() {
    return milkQuantity;
}

int Cappuccinno::getCoffeeQuantity() {
    return coffeeQuantity;
}

int Cappuccinno::getHeatMilkDuration() {
    return boilMilk;
}

int Cappuccinno::getWaterQunatity() {
    return waterQuantity;
}

void Cappuccinno::showInfo(){
    cout << "Cappuccinno:"<<"\n";
    cout << "Cantitate cafea: " << Cappuccinno::getCoffeeQuantity() <<"g" <<"\n";
    cout << "Cantitate lapte: " << Cappuccinno::getMilkQuantity() << "ml" <<"\n";
    cout << "Cantitate apa: " << Cappuccinno::getWaterQunatity() <<"ml" <<"\n";
    cout << "Durata de macinare a cafelei: " << Cappuccinno::getGrindDuration() <<"s" <<"\n";
    cout << "Durata de fierbere a laptelui: " << Cappuccinno::getHeatMilkDuration() <<"s" <<"\n";
}
Cappuccinno::~Cappuccinno()
{
    //dtor
}
