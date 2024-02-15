#include "ResourceContainer.h"
#include <iostream>

using namespace std;

ResourceContainer::ResourceContainer(Resource r)
{
    resource = r;
    currentQ = 100;
}

void ResourceContainer :: refill(int refillAmount)
{
    if (currentQ + refillAmount <= maxQ)
    {
        currentQ += refillAmount;
    }
    else
    {
        currentQ = maxQ;
    }
    cout<<"Reincarcarea a fost efectuata cu succes! Acum containerul este umplut la capacitatea: "<< currentQ<< endl;
}


int ResourceContainer :: getQuantity(int requestedQuantity)
{
    if (requestedQuantity <= currentQ && currentQ >= lowQ)
    {
        this->currentQ -= requestedQuantity;
        return requestedQuantity;
    }
    else
    {
        return -1;
    }
}

bool ResourceContainer::verify(){
    if(currentQ < lowQ){
        return false;
    }
    return true;
}

Resource ResourceContainer :: getResource(){
    return resource;
}
int ResourceContainer::getCurrentQ() {
    return currentQ;
}

ResourceContainer::~ResourceContainer()
{
    //dtor
}
