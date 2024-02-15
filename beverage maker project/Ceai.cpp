//
// Created by Robert on 1/4/2024.
//

#include "Ceai.h"
#include <iostream>

using namespace std;

Ceai::Ceai(list<Resource> resources, int boilwatertime, int waterquantity, int teaquantity) : Recipe(resources) {
    boilWatertime = boilwatertime;
    waterQuantity = waterquantity;
    teaQuantity = teaquantity;
}

int Ceai::getWaterQuantity() {
    return waterQuantity;
}

int Ceai::getBoilWaterTime() {
    return boilWatertime;
}

int Ceai::getTeaQuantity() {
    return teaQuantity;
}

void Ceai::showInfo() {
    cout << "Ceai: " <<"\n";
    cout << "Cantitatea de apa: " << Ceai::getWaterQuantity() << "ml" <<"\n";
    cout << "Cantitatea de ceai: " << Ceai::getTeaQuantity() <<"g" <<"\n";
    cout << "Timpul de fierbere al apei: " <<Ceai::getBoilWaterTime() <<"S" <<"\n";
}

Ceai::~Ceai(){
    //dst
}