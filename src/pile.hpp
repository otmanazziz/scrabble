#pragma once

#include <iostream>
#include <stack>

#include "etat.hpp"
#include "gaddag.hpp"

struct Pile{

    std::stack<Etat> etats;

    Pile();
    ~Pile();

    void empiler(Etat e);
    void depiler();

    Etat getEtat();

    std::string informations(Etat e);

    void listerEtats(Gaddag g);

    void consulterEtats(Gaddag g);

    bool wordIsGreat(Gaddag g, Etat e);

};