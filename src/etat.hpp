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
    unsigned int l_initial, c_initial, l, c;
    std::string mot;
    unsigned int nbPoints;
    //l and c initial are initial coordinates (where we launch the function)
    //l and c are the current coordinates

    Etat(Board b, Noeud *n, std::vector<Lettre> l, unsigned int lini, unsigned int cini, unsigned int ll, unsigned int cc, bool hori, bool arr);
    Etat(Board b, Noeud *n, std::vector<Lettre> l, unsigned int lini, unsigned int cini, unsigned int ll, unsigned int cc, bool hori, bool arr, char lettre);

    void calculerPoints();

    std::string informations();

};