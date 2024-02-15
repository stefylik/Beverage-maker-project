#include "RecipeRepo.h"
#include "Expresso.h"
#include "Cappuccinno.h"
#include "LatteMacchiato.h"
#include "Resource.h"
#include "Ceai.h"
#include <fstream>
#include <sstream>

using namespace std;

RecipeRepo::RecipeRepo()
{

}

RecipeRepo::RecipeRepo(string filePath) {
    ifstream file(filePath);

    if (!file.is_open()) {
        cerr << "Error opening file: " << filePath << endl;
        return;
    }

    string line;
    while (getline(file, line)) {
        istringstream iss(line);
        string name;
        int grindDuration, boilwaterTime, coffeeQuantity, waterQuantity, milkQuantity, boilMilk, teaQuantity;

        if (iss >> name) {
            if (name == "Expresso" && iss >> grindDuration >> coffeeQuantity >> waterQuantity >> boilwaterTime) {
                list<Resource> res;
                res.push_back(COFFEE);
                res.push_back(WATER);
                Expresso *e = new Expresso(res, grindDuration, coffeeQuantity, waterQuantity, boilwaterTime);
                recipes.push_back(e);
            } else if (name == "LatteMacchiato" && iss >> grindDuration >> boilMilk >> coffeeQuantity >> milkQuantity >> waterQuantity) {
                list<Resource> res;
                res.push_back(COFFEE);
                res.push_back(WATER);
                res.push_back(MILK);
                LatteMacchiato *latte = new LatteMacchiato(res, grindDuration, boilMilk, coffeeQuantity, milkQuantity, waterQuantity);
                recipes.push_back(latte);
            } else if (name == "Cappuccinno" && iss >> grindDuration >> boilMilk >> coffeeQuantity >> milkQuantity >> waterQuantity) {
                list<Resource> res;
                res.push_back(COFFEE);
                res.push_back(WATER);
                res.push_back(MILK);
                Cappuccinno *capp = new Cappuccinno(res, grindDuration, boilMilk, coffeeQuantity, milkQuantity, waterQuantity);
                recipes.push_back(capp);
            } else if (name == "Ceai" && iss >> boilwaterTime >> waterQuantity >> teaQuantity) {
                list<Resource> res;
                res.push_back(WATER);
                res.push_back(TEA);
                Ceai *cea = new Ceai(res, boilwaterTime, waterQuantity, teaQuantity);
                recipes.push_back(cea);
            } else {
                cerr << "Error parsing line: " << line << endl;
            }
        } else {
            cerr << "Error parsing line: " << line << endl;
        }
    }

    file.close();
}


Recipe * RecipeRepo :: getRecipe(string name)
{

    for(Recipe* rec: recipes)
    {

        if(name=="Expresso" && typeid(Expresso) == typeid(*rec))
        {
            return rec;
        }
        if(name=="LatteMacchiato" && typeid(LatteMacchiato) == typeid(*rec))
        {
            return rec;
        }
        if(name=="Cappuccinno" && typeid(Cappuccinno)== typeid(*rec))
        {
            return rec;
        }
        if(name=="Apa" && typeid(Ceai) == typeid(*rec))
        {
            return rec;
        }
        if(name=="Ceai" && typeid(Ceai) == typeid(*rec))
        {
            return rec;
        }
    }
}

RecipeRepo::~RecipeRepo()
{

}