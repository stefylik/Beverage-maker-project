cmake_minimum_required(VERSION 3.26)
project(proiect)

set(CMAKE_CXX_STANDARD 17)

add_executable(proiect main.cpp
        Cappuccinno.cpp
        CommandManager.cpp
        CommandPanel.cpp
        RecipeRepo.cpp
        Expresso.cpp
        LatteMacchiato.cpp
        Recipe.cpp
        ResourceContainer.cpp
        ResourceHandler.cpp
        Ceai.cpp)
