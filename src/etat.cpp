#include "etat.hpp"

Etat::Etat(Board b, Noeud n[27], std::vector<Lettre> l){
    this->b = b;
    
    for (int i = 0; i < 27; i++)
        this->n[i] = new Noeud(n[i]);

    this->hand = l;
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