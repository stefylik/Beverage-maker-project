#include "ResourceHandler.h"
#include "Expresso.h"
#include "RecipeRepo.h"
#include "Cappuccinno.h"
#include "LatteMacchiato.h"
#include "Ceai.h"
#include <thread>
#include <chrono>

ResourceHandler::ResourceHandler()
{
    ResourceContainer water(WATER);
    ResourceContainer milk(MILK);
    ResourceContainer coffee(COFFEE);
    ResourceContainer tea(TEA);
    containers.push_back(water);
    containers.push_back(milk);
    containers.push_back(coffee);
    containers.push_back(tea);
}

bool ResourceHandler:: boilWater(int quantity){
    for(ResourceContainer& r : containers){
        if(r.getResource() == WATER){
            int cantitate=r.getQuantity(quantity);
            if(cantitate==quantity)
                return true;
            else
                return false;
        }
    }
}

bool ResourceHandler::grindCoffee(int quantity){
    for(ResourceContainer& r : containers){
        if(r.getResource() == COFFEE){
            int cantitate=r.getQuantity(quantity);
            if(cantitate==quantity)
                return true;
            else
                return false;
        }
    }
}

bool ResourceHandler::heatMilk(int quantity){
    for(ResourceContainer& r : containers){
        if(r.getResource() == MILK){
            int cantitate=r.getQuantity(quantity);
            if(cantitate==quantity)
                return true;
            else
                return false;
        }
    }
}

bool ResourceHandler::teaQuantity(int quantity) {
    for(ResourceContainer& r :containers){
        if(r.getResource() == TEA){
            int cantitate = r.getQuantity(quantity);
            if(cantitate == quantity)
                return true;
            else
                return false;
        }
    }
}

bool ResourceHandler:: checkResources(){
    bool seeAll=false;
    for(ResourceContainer r : containers){
        if(r.verify()== true)
            seeAll = true;
    }
    return seeAll;
}

void ResourceHandler :: reloadResources(){
    cout<<"Bun venit admin! Acum poti reincarca containterele!\n";
    for(ResourceContainer& r : containers){
        if(r.getResource() == COFFEE){
            cout <<"cantitatea curenta:"<< r.getCurrentQ()<<"\n" ;
            cout<<"Introdu cantitatea de reincarcat containerul de CAFEA: ";
            int quantity;
            cin>>quantity;
            r.refill(quantity);
        }
        if(r.getResource() == WATER){
            cout <<"cantitatea curenta:"<< r.getCurrentQ()<<"\n" ;
            cout<<"Introdu cantitatea de reincarcat containerul de APA: ";
            int quantity;
            cin>>quantity;
            r.refill(quantity);
        }
        if(r.getResource() == MILK){
            cout <<"cantitatea curenta:"<< r.getCurrentQ()<<"\n" ;
            cout<<"Introdu cantitatea de reincarcat containerul de LAPTE: ";
            int quantity;
            cin>>quantity;
            r.refill(quantity);
        }
        if(r.getResource() == TEA){
            cout <<"cantitatea curenta:"<< r.getCurrentQ()<<"\n" ;
            cout << "Introdu cantitatea de reincarcat containerul de CEAI: ";
            int quantity;
            cin >> quantity;
            r.refill(quantity);
        }
    }
}

void ResourceHandler::meniu() {
    int opt;
    cout << "Meniu admin: \n";
    do {
        cout << "0.Reintoarceti-va la meniul pricipal:\n";
        cout << "1.Vizualizare cantitati curente:\n";
        cout << "2.Reincarcare containere de resurse: \n";
        cout << "3.Vizualizare cantitati reteta: \n";
        cin >> opt;
        switch (opt) {
            case 1: {
                for (ResourceContainer &r: containers) {
                    if (r.getResource() == COFFEE)
                        cout << "cantitatea curenta de cafea:" << r.getCurrentQ() << "\n";
                    if (r.getResource() == MILK)
                        cout << "cantitatea curenta de lapte:" << r.getCurrentQ() << "\n";
                    if (r.getResource() == WATER)
                        cout << "cantitatea curenta de apa:" << r.getCurrentQ() << "\n";
                    if (r.getResource() == TEA)
                        cout << "cantitatea curenta de ceai:" << r.getCurrentQ() << "\n";
                }
                break;
            }
            case 2: {
                reloadResources();
                this_thread::sleep_for(chrono::seconds (2));
                break;
            }
            case 3:{
               RecipeRepo repo=RecipeRepo("E:\\proiect cu fisiere\\proiect\\reteta.txt");
                Recipe *re;
                re = repo.getRecipe("Expresso");
                Expresso *ex = dynamic_cast<Expresso *>(re);
                ex->showInfo();
                cout<<endl;
                Recipe *rec;
                rec = repo.getRecipe("Cappuccinno");
                Cappuccinno *ca = dynamic_cast<Cappuccinno *>(rec);
                ca->showInfo();
                cout<<endl;
                Recipe *reci;
                reci = repo.getRecipe("LatteMacchiato");
                LatteMacchiato *la = dynamic_cast<LatteMacchiato *>(reci);
                la->showInfo();
                cout<<endl;
                Recipe *recip;
                recip = repo.getRecipe("Ceai");
                Ceai *ce = dynamic_cast<Ceai *>(recip);
                ce->showInfo();
                cout<<"--------------------------\n";
                this_thread::sleep_for(chrono::seconds (2));
                break;
            }
        }
    }while (opt != 0);
    }


ResourceHandler::~ResourceHandler()
{
    //dtor
}