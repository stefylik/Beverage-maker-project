#ifndef PROIECT_CEAI_H
#define PROIECT_CEAI_H
#include "Recipe.h"
#include <list>
#include "Resource.h"

using namespace std;

class Ceai : public Recipe {
private:
    int boilWatertime;
    int waterQuantity;
    int teaQuantity;
public:
    Ceai(list<Resource>,int,int,int);
    int getBoilWaterTime();
    int getWaterQuantity();
    int getTeaQuantity();
    void showInfo() override;
    virtual ~Ceai();
};


#endif //PROIECT_CEAI_H
