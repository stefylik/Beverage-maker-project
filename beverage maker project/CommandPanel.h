#ifndef COMMANDPANEL_H
#define COMMANDPANEL_H

#include "CommandManager.h"


class CommandPanel
{
public:
    CommandPanel();
    virtual ~CommandPanel();
    void showMenu();
    bool takeCommand();

private:
    CommandManager manager;
};

#endif // COMMANDPANEL_H
