#pragma once

#include <iostream>
#include <vector>

#include "sac_lettres.hpp"
#include "pile.hpp"

struct Joueur{
    //variables
    std::vector<Lettre> mainJoueur;
    Pile *p;

    //static
    static const int tailleMainJoueur = 7;

    Joueur(SacLettres *s);

    void recharger(SacLettres *s);
    void retirerLettre(int i);

    void lister_coups(Board b, Noeud n[27]);

    std::string informations();

};