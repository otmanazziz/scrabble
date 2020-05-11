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
}

Etat::Etat(Board b, Noeud *n, std::vector<Lettre> l, unsigned int lini, unsigned int cini, unsigned int ll, unsigned int cc, bool hori, bool arr, char lettre){
    this->b = b;
    
    this->n = n;

    this->hand = l;

    this->l_initial = lini;
    this->c_initial = cini;
    this->l = ll;
    this->c = cc;
    this->horizontal = hori;
    this->arriere = arr;

    mot += lettre;
}

std::string Etat::informations(){
    std::string res = "************-== BOARD ==-************\n\n";

    //b(7, 8).letter = 'K';

    for (unsigned int i = 0; i < 15; i++){
        for (unsigned int j = 0; j < 15; j++){
            res += " ";
            if (b(i, j).letter == 0)
                res += "_";
            else res.push_back(b(i, j).letter);
            res += " ";
        }
        res += "\n";
    }

    res += "\n\n************-== HAND PLAYER ==-************\n\n";
    res += "Hand [ ";
    for (unsigned int i = 0; i < hand.size(); i++){
        res += hand[i].informations() + " ";
    }

    res += "\n\n************-==========-************\n\n";
    return res;
}

void Etat::calculerPoints(){

    const unsigned int lettresPoints[26] = {1, 3, 3, 2, 1, 4, 2, 4, 1, 8, 10, 1, 2, 1, 1, 3, 2, 1, 1, 1, 1, 4, 10, 10, 10, 10};
    unsigned int points = 0;

    for (unsigned int i = 0; i < mot.length(); i++){

        points += lettresPoints[(int)mot.at(i) - 65];

    }

    this->nbPoints = points;
    std::cout << "POINTS[" << mot << "]: " << points << " points.";
}