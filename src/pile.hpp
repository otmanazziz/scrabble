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

    void listerEtats(Board b, Noeud n[27], std::vector<Lettre> hand, int line, int col, bool vertical);

};