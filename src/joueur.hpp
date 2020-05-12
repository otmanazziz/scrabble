#pragma once

#include <iostream>
#include <vector>

#include "sac_lettres.hpp"
#include "pile.hpp"

struct Joueur{
    //variables
    std::vector<Lettre> mainJoueur;
    Pile *p;
    unsigned int nbPoints;

    //static
    static const unsigned int tailleMainJoueur = 7;

    Joueur(SacLettres *s);

    void recharger(SacLettres *s);
    void retirerLettre(unsigned int i);

    Board lister_coups(Board b, Gaddag g);

    std::string informations();

};