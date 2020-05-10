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
    Noeud *n;
    std::vector<Lettre> hand;
    bool horizontal, arriere;
    int l_initial, c_initial, l, c;
    //l and c initial are initial coordinates (where we launch the function)
    //l and c are the current coordinates

    Etat(Board b, Noeud *n, std::vector<Lettre> l, int lini, int cini, int ll, int cc, bool hori, bool arr);
    ~Etat();

    std::string informations();

};