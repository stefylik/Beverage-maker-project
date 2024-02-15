#include <iostream>
#include "CommandPanel.h"

using namespace std;

int main()
{
    CommandPanel pannel;
    bool comanda;
    do{
        pannel.showMenu();
        comanda=pannel.takeCommand();

    }while(comanda!=false);
    return 0;
}