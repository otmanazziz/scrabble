#include "etat.hpp"

Etat::Etat(Board b, Noeud *n, std::vector<Lettre> l, unsigned int lini, unsigned int cini, unsigned int ll, unsigned int cc, bool hori, bool arr){
    this->b = b;
    
    this->n = n;

    this->hand = l;

    this->l_initial = lini;
    this->c_initial = cini;
    this->l = ll;
    this->c = cc;
    this->horizontal = hori;
    this->arriere = arr;

    this->nbPoints = 0;
}

Etat::Etat(Board b, Noeud *n, std::vector<Lettre> l, unsigned int lini, unsigned int cini, unsigned int ll, unsigned int cc, bool hori, bool arr, unsigned int nbPoints){
    this->b = b;
    
    this->n = n;

    this->hand = l;

    this->l_initial = lini;
    this->c_initial = cini;
    this->l = ll;
    this->c = cc;
    this->horizontal = hori;
    this->arriere = arr;

    this->nbPoints = nbPoints;
}

std::string Etat::informations(){
    std::string res;

    for (unsigned int i = 0; i < 15; i++){
        for (unsigned int j = 0; j < 15; j++){
            res += " ";
            if (b(i, j).letter == 0)
                res += ".";
            else res.push_back(b(i, j).letter);
            res += " ";
        }
        res += "\n";
    }

    res += "\nHand [ ";
    for (unsigned int i = 0; i < hand.size(); i++){
        res += hand[i].informations() + " ";
    }
    res += "] pour ";
    res += std::to_string(nbPoints);
    res += " points.\n";

    return res;
}