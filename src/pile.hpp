#pragma once

#include <iostream>
#include <stack>

#include "etat.hpp"

struct Pile{

    std::stack<Etat> etats;

    Pile();
    ~Pile();

    void empiler(Etat e);
    void depiler();

    Etat getEtat();

    std::string informations();

};