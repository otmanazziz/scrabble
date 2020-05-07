#include "pile.hpp"
    
Pile::Pile(){
    std::cout << "Pile initialisée.\n";
}

Pile::~Pile(){
    while (!etats.empty())
        etats.pop();
}

void Pile::empiler(Etat e){
    etats.push(e);
}

void Pile::depiler(){
    
    if (etats.size() > 0){
        std::cout << "Etat dépilé.";
        etats.pop();
    } else std::cout << "[ERREUR] Pile vide.";
        
}

Etat Pile::getEtat(){
    if (!etats.empty())
        return etats.top();
}

std::string Pile::informations(){
    std::stack<Etat> temp = etats;

    std::string res = "********************************************************\n";
    res += "************************[ PILE ]************************\n";
    res += "********************************************************\n\n";

    while (!temp.empty()){
        res += temp.top().informations() + " ";
        temp.pop();
    }

    res += "********************************************************\n";
    res += "********************************************************\n";
    return res;
}

void Pile::listerEtats(){

    Etat temp = etats.top();

    std::cout << "\n\nMain actuelle du joueur: [";
    for (int i = 0; i < temp.hand.size(); i++){
        std::cout << temp.hand[i].informations() << " ";
    }
    std::cout << "] aux coordonnées (" << temp.l << ", " << temp.c << ")\n";

    depiler();

    //this->empiler(Etat(temp.b, temp.n->fils[24], temp.hand, temp.l_initial, temp.c_initial, temp.l, temp.c, temp.horizontal, temp.arriere));

    if (temp.b(temp.l, temp.c).letter == NULL){

        std::cout << "--> (" << temp.l << ", " << temp.c << ") vide. ";

        if (temp.hand.size() == 0){
            std::cout << "Main vide. [FIN]\n";
        } else {

            for (int i = 0; i < temp.hand.size(); i++){

                if (temp.n->fils[(int)temp.hand[i].lettre - 65] != nullptr){

                    std::cout << temp.hand[i].lettre << " dispo. ";
                    
                    temp.b(temp.l, temp.c).letter = temp.hand[i].lettre;
                    std::vector<Lettre> hand = temp.hand;
                    hand.erase(hand.begin() + i);

                    if (temp.horizontal){ //horizontal
                        if (temp.arriere)
                            empiler(Etat(temp.b, temp.n->fils[(int)temp.hand[i].lettre - 65], hand, temp.l_initial, temp.c_initial, temp.l, temp.c - 1, temp.horizontal, temp.arriere));
                        else empiler(Etat(temp.b, temp.n->fils[(int)temp.hand[i].lettre - 65], hand, temp.l_initial, temp.c_initial, temp.l, temp.c + 1, temp.horizontal, temp.arriere));
                    } else { //vertical
                        if (temp.arriere)
                            empiler(Etat(temp.b, temp.n->fils[(int)temp.hand[i].lettre - 65], hand, temp.l_initial, temp.c_initial, temp.l - 1, temp.c, temp.horizontal, temp.arriere));
                        else empiler(Etat(temp.b, temp.n->fils[(int)temp.hand[i].lettre - 65], hand, temp.l_initial, temp.c_initial, temp.l + 1, temp.c, temp.horizontal, temp.arriere));
                    }
                    
                }

                //std::cout << temp.informations();

            }
            

        }

    } else { // lettre existante

        std::cout << "--> (" << temp.l << ", " << temp.c << ") vide. ";

        if (temp.n->fils[temp.b(temp.l, temp.c).letter - 65] != nullptr){

            std::cout << temp.b(temp.l, temp.c) << " dispo. ";

            if (temp.horizontal){ //horizontal
                if (temp.arriere)
                    empiler(Etat(temp.b, temp.n->fils[temp.b(temp.l, temp.c).letter - 65], temp.hand, temp.l_initial, temp.c_initial, temp.l, temp.c - 1, temp.horizontal, temp.arriere));
                else empiler(Etat(temp.b, temp.n->fils[temp.b(temp.l, temp.c).letter - 65], temp.hand, temp.l_initial, temp.c_initial, temp.l, temp.c + 1, temp.horizontal, temp.arriere));
            } else { //vertical
                if (temp.arriere)
                    empiler(Etat(temp.b, temp.n->fils[temp.b(temp.l, temp.c).letter - 65], temp.hand, temp.l_initial, temp.c_initial, temp.l - 1, temp.c, temp.horizontal, temp.arriere));
                else empiler(Etat(temp.b, temp.n->fils[temp.b(temp.l, temp.c).letter - 65], temp.hand, temp.l_initial, temp.c_initial, temp.l + 1, temp.c, temp.horizontal, temp.arriere));
            }
        }

    }

    //+ est dans le noeud
    if (temp.n->fils[26] != nullptr){

        std::cout << "+ dispo. On va vers l'avant. ";

        if (temp.horizontal){
            if (temp.b(temp.l, temp.c - 1).letter == NULL){
                temp.arriere = false;
                temp.c = temp.c_initial + 1;
            }
        } else {
            if (temp.b(temp.l - 1, temp.c).letter == NULL){
                temp.arriere = false;
                temp.l = temp.l_initial + 1;
            }
        }
    }

    if (temp.n->fils[temp.b(temp.l, temp.c).letter - 65]->terminal){
        std::cout << "Nous avons une solution!\n";
        std::cout << temp.informations();
    }

    this->listerEtats();

}