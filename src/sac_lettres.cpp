#include "sac_lettres.hpp"

//constructor
SacLettres::SacLettres(){
    for (int i = 0; i < 26; i++){
        for (int k = 0; k < lettresOccurences[i]; k++){
            sacLettres.push_back(Lettre((char)(i + 'A'), lettresPoints[i]));
        }
    }
}

SacLettres::~SacLettres(){
    sacLettres.clear();
}

Lettre SacLettres::recupererLettre(){
    if (!sacVide()){
        int random = rand() % sacLettres.size();
        std::cout << "[" << random << "] for max case " << sacLettres.size() << std::endl;
        Lettre temp(sacLettres[random].lettre, sacLettres[random].points);

        sacLettres[random].lettre = sacLettres[sacLettres.size() -1].lettre;
        sacLettres[random].points = sacLettres[sacLettres.size() -1].points;
        sacLettres.pop_back();
        return temp;
    } else {
        std::cout << "Le sac est vide.";
    }
}

bool SacLettres::sacVide(){
    return sacLettres.size() == 0;
}

void SacLettres::lettresRestantes(){
    std::cout << "Il reste " << sacLettres.size() << " lettres dans ce putain de sac à lettres." << std::endl;
    for (int i = 0; i < sacLettres.size(); i++){
        std::cout << sacLettres[i].lettre << " -> " << sacLettres[i].points << std::endl;
    }
}