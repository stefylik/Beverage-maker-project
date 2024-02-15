#include "CommandManager.h"
#include "Expresso.h"
#include "LatteMacchiato.h"
#include "Cappuccinno.h"
#include "Ceai.h"
#include <iostream>
#include <string.h>
#include <typeinfo>
#include <thread>
#include <chrono>

using namespace std;

CommandManager :: CommandManager()
{
    this->repo=RecipeRepo("E:\\proiect cu fisiere\\proiect\\reteta.txt");
    canWork=true;
}

void CommandManager :: reload(){
    cout<<"Doriti sa accesati meniul adminului? (y/n)\n";
    string resp;
    cin>>resp;
    if(resp=="y"){
        int parola;
        cout << "introduceti parola: ";
        cin >> parola;
        if (parola == 1234) {
            handler.meniu();
            canWork = true;
        }else {
            cout << "parola introdusa gresit\n"
                << "Intoarcere la meniul principal...\n";
            this_thread::sleep_for(chrono::seconds (2));
        return ;
        }
    }
    else if(resp=="n"){
        cout<<"Inapoi la meniul principal...";
        this_thread::sleep_for(chrono::seconds (2));
        return;
    }


}

bool CommandManager::takeCommand(int order) {
    canWork = true;
    if (!handler.checkResources()&&order!=7) {
        cout << "Resurse insuficiente. Trebuie efectuata reincarcarea containerelor..." << endl;
        reload();
        canWork = false;
    }
    if (canWork) {
        switch (order) {
            case 1: {
                Recipe *re;
                re = repo.getRecipe("Expresso");
                Expresso *ex = dynamic_cast<Expresso *>(re);
                int coffee = ex->getCoffeeQuantity();
                int water = ex->getWaterQuantity();
                int grind = ex->getGrindDuration();
                int boil = ex->getBoilTime();
                if (handler.grindCoffee(coffee) == true && handler.boilWater(water) == true) {
                    chrono::seconds duration(boil+grind);
                    cout << "Reteta se va finaliza in cateva momente... \n";
                    this_thread::sleep_for(duration);
                    cout << "Expresso finalizat cu succes!\n";
                    this_thread::sleep_for(chrono::seconds (2));
                } else {
                    if (handler.grindCoffee(coffee) == false)
                        cout << "Cafea insuficienta!\n";
                    if (handler.boilWater(water) == false)
                        cout << "Apa insuficienta!\n";
                    reload();
                }

                break;
            }

            case 2: {
                Recipe *re;
                re = repo.getRecipe("Expresso");
                Expresso *ex = dynamic_cast<Expresso *>(re);
                int coffee = 2 * ex->getCoffeeQuantity();
                int water = 2 * ex->getWaterQuantity();
                int grind = ex->getGrindDuration();
                int boil = ex->getBoilTime();
                if (handler.grindCoffee(coffee) == true && handler.boilWater(water) == true) {
                    chrono::seconds duration(boil+grind);
                    cout << "Reteta se va finaliza in cateva momente... \n";
                    this_thread::sleep_for(duration);
                    cout << "Expresso dublu finalizat cu succes!\n";
                    this_thread::sleep_for(chrono::seconds (2));
                } else {
                    if (handler.grindCoffee(coffee) == false)
                        cout << "Cafea insuficienta!\n";
                    if (handler.boilWater(water) == false)
                        cout << "Apa insuficienta!\n";
                    reload();
                }
                break;
            }
            case 3: {
                Recipe *re;
                re = repo.getRecipe("Cappuccinno");
                Cappuccinno *ca = dynamic_cast<Cappuccinno *>(re);
                int coffee = ca->getCoffeeQuantity();
                int water = ca->getWaterQunatity();
                int milk = ca->getMilkQuantity();
                int grind = ca->getGrindDuration();
                int boil = ca->getHeatMilkDuration();
                if (handler.grindCoffee(coffee) == true && handler.boilWater(water) == true &&
                    handler.heatMilk(milk) == true) {
                    chrono::seconds duration(boil+grind);
                    cout << "Reteta se va finaliza in cateva momente... \n";
                    this_thread::sleep_for(duration);
                    cout << "Cappuccinno finalizat cu succes!\n";
                    this_thread::sleep_for(chrono::seconds (2));
                } else {
                    if (handler.grindCoffee(coffee) == false)
                        cout << "Cafea insuficienta!\n";
                    if (handler.boilWater(water) == false)
                        cout << "Apa insuficienta!\n";
                    if (handler.heatMilk(milk) == false)
                        cout << "Lapte insuficient\n";
                    reload();
                }
                break;
            }
            case 4: {
                Recipe *re;
                re = repo.getRecipe("LatteMacchiato");
                LatteMacchiato *la = dynamic_cast<LatteMacchiato *>(re);
                int coffee = la->getCoffeeQuantity();
                int water = la->getWaterQunatity();
                int milk = la->getMilkQuantity();
                int grind = la->getGrindDuration();
                int boil = la->getHeatMilkDuration();
                if (handler.grindCoffee(coffee) == true && handler.boilWater(water) == true &&
                    handler.heatMilk(milk) == true) {
                    chrono::seconds duration(boil+grind);
                    cout << "Reteta se va finaliza in cateva momente... \n";
                    this_thread::sleep_for(duration);
                    cout << "Latte Machiatto finalizat cu succes!\n";
                    this_thread::sleep_for(chrono::seconds (2));
                } else {
                    if (handler.grindCoffee(coffee) == false)
                        cout << "Cafea insuficienta!\n";
                    if (handler.boilWater(water) == false)
                        cout << "Apa insuficienta!\n";
                    if (handler.heatMilk(milk) == false)
                        cout << "Lapte insuficient\n";
                    reload();
                }
                break;
            }
            case 5: {
                Recipe *re;
                re = repo.getRecipe("Ceai");
                Ceai *ce = dynamic_cast<Ceai *>(re);
                int water = ce->getWaterQuantity();
                int boil = ce->getBoilWaterTime();
                if (handler.boilWater(water) == true) {
                    chrono::seconds duration(boil);
                    cout << "Reteta se va finaliza in cateva momente... \n";
                    this_thread::sleep_for(duration);
                    cout << "Apa finalizata cu succes!\n";
                    this_thread::sleep_for(chrono::seconds (2));
                } else {
                    if (handler.boilWater(water) == false)
                        cout << "Apa insuficienta!\n";
                    reload();
                }
                break;
            }
            case 6: {
                Recipe *re;
                re = repo.getRecipe("Ceai");
                Ceai *ce = dynamic_cast <Ceai *>(re);
                int water = ce->getWaterQuantity();
                int tea = ce->getTeaQuantity();
                int boil = ce->getBoilWaterTime();
                if (handler.boilWater(water) == true && handler.teaQuantity(tea) == true)
                {
                    chrono::seconds duration(boil);
                    cout << "Reteta se va finaliza in cateva momente... \n";
                    this_thread::sleep_for(duration);
                    cout << "Ceai finalizat cu succes!\n";
                    this_thread::sleep_for(chrono::seconds (2));
                }
                else {
                    if (handler.teaQuantity(tea) == false)
                        cout << "Ceai insuficient!\n";
                    if (handler.boilWater(water) == false)
                        cout << "Apa insuficienta!\n";
                    reload();
                }
                break;
            }
            case 7:
            {
                reload();
                break;
            }
            default:
                //cout << "Comanda invalida!" << endl;
                return true;
        }
        return true;
    }
    return true;
}
CommandManager::~CommandManager()
{
    //dtor
}