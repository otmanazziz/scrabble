#include "etat.hpp"

Etat::Etat(Board b, Noeud *n, std::vector<Lettre> l, int lini, int cini, int ll, int cc, bool hori, bool arr){
    this->b = b;
    
    this->n = n;

    this->hand = l;

    this->l_initial = lini;
    this->c_initial = cini;
    this->l = ll;
    this->c = cc;
    this->horizontal = hori;
    this->arriere = arr;
}

Etat::~Etat(){

}

std::string Etat::informations(){
    std::string res = "************-== BOARD ==-************\n\n";

    //b(7, 8).letter = 'K';

    for (int i = 0; i < 15; i++){
        for (int j = 0; j < 15; j++){
            res += " ";
            if (b(i, j).letter == NULL)
                res += "_";
            else res.push_back(b(i, j).letter);
            res += " ";
        }
        res += "\n";
    }

    res += "\n\n************-== HAND PLAYER ==-************\n\n";
    res += "Hand [ ";
    for (int i = 0; i < hand.size(); i++){
        res += hand[i].informations() + " ";
    }
    res += "]";

    res += "\n\n************-==========-************\n\n";
    return res;
}