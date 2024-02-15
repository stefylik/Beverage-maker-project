#include "Expresso.h"

Expresso::Expresso(list<Resource> resources, int grindduration,int coffeequantity,int waterquantity,int boilwater) : Recipe(resources){
    grindDuration = grindduration;
    coffeeQuantity = coffeequantity;
    waterQuantity = waterquantity;
    boilwaterTime = boilwater;
}

int Expresso::getGrindDuration() {
    return grindDuration;
}

int Expresso::getCoffeeQuantity() {
    return coffeeQuantity;
}

int Expresso::getWaterQuantity() {
    return waterQuantity;
}

int Expresso::getBoilTime() {
    return boilwaterTime;
}

void Expresso::showInfo(){
    cout << "Expresso: " << "\n";
    cout << "Cantitatea de cafea: " << Expresso::getCoffeeQuantity() <<" g" <<"\n";
    cout << "Cantitatea de apa: " << Expresso::getWaterQuantity() <<"ml" <<"\n";
    cout << "Durata de macinare a cafelei: " << Expresso::getGrindDuration() <<" s" <<"\n";
    cout << "Durata de fierbere a apei:" << Expresso::getBoilTime() <<" s" <<"\n";
}

Expresso::~Expresso()
{
    //dtor
}