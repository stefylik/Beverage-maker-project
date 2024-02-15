#include "CommandPanel.h"
#include <iostream>

using namespace std;

CommandPanel::CommandPanel(){}

void CommandPanel::showMenu() {
    cout <<"--------------------------\n"
         << "0. Iesire\n"
         << "1. Cafea Espresso\n"
         << "2. Cafea Lunga (Espresso Dublu)\n"
         << "3. Cappuccino\n"
         << "4. Latte Macchiato\n"
         << "5. Apa\n"
         << "6. Ceai\n"
         << "7. Meniu admin \n" //parola admin 1234
         <<"--------------------------\n";
}

bool CommandPanel::takeCommand() {
    int comanda;
    bool command;
    cout << "Alege o optiune: ";
    cin >> comanda;

    if (comanda == 0) {
        cout << "La revedere!\n";
        return false;
    }
    command=manager.takeCommand(comanda);
    return command;
}


CommandPanel::~CommandPanel()
{
    //dtor
}
