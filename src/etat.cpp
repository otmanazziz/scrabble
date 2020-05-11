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

Etat::Etat(Board b, Noeud *n, std::vector<Lettre> l, int lini, int cini, int ll, int cc, bool hori, bool arr, char lettre){
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
    res += "] pour ";
    res += std::to_string(nbPoints);
    res += " points.";

    res += "\n\n************-==========-************\n\n";
    return res;
}

void Etat::calculerPoints(){

    const int lettresPoints[26] = {1, 3, 3, 2, 1, 4, 2, 4, 1, 8, 10, 1, 2, 1, 1, 3, 2, 1, 1, 1, 1, 4, 10, 10, 10, 10};
    int points = 0;

    for (int i = 0; i < mot.length(); i++){

        points += lettresPoints[(int)mot.at(i) - 65];

    }

    this->nbPoints = points;
    std::cout << "POINTS[" << mot << "]: " << points << " points.";
}