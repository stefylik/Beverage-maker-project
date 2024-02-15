// CommandManager.h

#ifndef COMMANDMANAGER_H
#define COMMANDMANAGER_H
#include <iostream>
#include "RecipeRepo.h"
#include "ResourceHandler.h"

class CommandManager
{
public:
    CommandManager();
    void reload();
    bool takeCommand(int);
    virtual ~CommandManager();
private:
    RecipeRepo repo;
    ResourceHandler handler;
    bool canWork;
};

#endif // COMMANDMANAGER_H
