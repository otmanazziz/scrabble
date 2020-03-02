#include <iostream>
#include <vector>

#include "sac_lettres.hpp"

struct Joueur{
    //variables
    std::vector<Lettre> mainJoueur;

    //static
    static const int tailleMainJoueur = 7;

    Joueur(SacLettres *s);

    void recharger(SacLettres *s);
    void retirerLettre(int i);

    void informations();

};