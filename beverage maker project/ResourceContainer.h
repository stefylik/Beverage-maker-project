#ifndef RESOURCECONTAINER_H
#define RESOURCECONTAINER_H

#include "Resource.h"


class ResourceContainer
{
public:
    ResourceContainer(Resource);
    void refill(int);
    int getQuantity(int quantity);
    bool verify();
    Resource getResource();
    int getCurrentQ();
    virtual ~ResourceContainer();

private:
    int lowQ=20;
    int maxQ=100;
    int currentQ;
    Resource resource;
};

#endif // RESOURCECONTAINER_H
