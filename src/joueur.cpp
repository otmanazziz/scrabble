#include "joueur.hpp"

Joueur::Joueur(SacLettres *s){
    for (int i = 0; i < tailleMainJoueur; i++){
        if (!s->sacVide())
            mainJoueur.push_back(s->recupererLettre());
        else break;
    }
    informations();
}

void Joueur::recharger(SacLettres *s){
    while (mainJoueur.size() < tailleMainJoueur){
        if (!s->sacVide())
            mainJoueur.push_back(s->recupererLettre());
        else break;
    }
}

void Joueur::retirerLettre(int i){
    if (i >= 0 && mainJoueur.size() > 0){
        std::cout << "Retirer lettre " << i << std::endl;
        mainJoueur.erase(mainJoueur.begin() + i);
    }
}

void Joueur::informations(){
    if (mainJoueur.size() == 0)
        std::cout << "La main du joueur est vide.";
    else {
        std::cout << "La main du joueur : ";
        for (int i = 0; i < mainJoueur.size(); i++){
            mainJoueur[i].informations();
            std::cout << " ";
        }
    }
    std::cout << std::endl;
}