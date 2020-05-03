#pragma once

#include <iostream>
#include <vector>
#include <cstring>
#include <memory>

#include "Lettre.hpp"
#include "board.hpp"
#include "noeud.hpp"

struct Etat{

    Board b;
    Noeud *n[27];
    std::vector<Lettre> hand;

    Etat(Board b, Noeud n[27], std::vector<Lettre> l);
    ~Etat();

    std::string informations();

};