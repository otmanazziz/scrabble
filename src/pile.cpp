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

std::string Pile::informations(Etat e){

    std::string res = "********************************************************\n";
    res += "************************[ PILE ]************************\n";
    res += "********************************************************\n\n";

    res += e.informations() + " ";

    res += "********************************************************\n";
    res += "********************************************************\n";
    return res;
}

void Pile::listerEtats(){
    Etat temp = etats.top();

    /*std::cout << "\n\nEtats[" << etats.size() << "] Main actuelle du joueur: [";
    for (int i = 0; i < temp.hand.size(); i++){
        std::cout << temp.hand[i].informations() << " ";
    }
    //std::cout << "] aux coordonnées (" << temp.l << ", " << temp.c << ")\n";

    //std::cout << "Lettres [ ";
    for (int i = 0; i < 27; i++){
        if (temp.n->fils[i] != nullptr){
            std::cout << i << " ";
        }
    }
    //std::cout << "]\n";*/

    depiler();

    //this->empiler(Etat(temp.b, temp.n->fils[24], temp.hand, temp.l_initial, temp.c_initial, temp.l, temp.c, temp.horizontal, temp.arriere));

    if (temp.b(temp.l, temp.c).letter == 0){

        //std::cout << "--> (" << temp.l << ", " << temp.c << ") vide. ";

        //+ est dans le noeud
        if (temp.n->fils[26] != nullptr){

            //std::cout << "+ dispo. On va vers l'avant. ";

            if (temp.horizontal){
                if (temp.b(temp.l, temp.c - 1).letter == 0){
                    empiler(Etat(temp.b, temp.n->fils[26], temp.hand, temp.l_initial, temp.c_initial, temp.l, temp.c_initial + 1, temp.horizontal, false));
                }
            } else {
                if (temp.b(temp.l - 1, temp.c).letter == 0){
                    empiler(Etat(temp.b, temp.n->fils[26], temp.hand, temp.l_initial, temp.c_initial, temp.l_initial + 1, temp.c, temp.horizontal, false));
                }
            }
        }

        if (temp.hand.size() == 0){
            //std::cout << "Main vide. [FIN]\n";
            return;
        } else {

            int nbSolutions = 0;

            for (int i = 0; i < temp.hand.size(); i++){

                if (temp.n->fils[(int)temp.hand[i].lettre - 65] != nullptr){

                    nbSolutions ++;

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
            
            if (nbSolutions == 0)
                return;

        }

    } else { // lettre existante

        //std::cout << "--> (" << temp.l << ", " << temp.c << ") non vide. ";

        if (temp.n->fils[temp.b(temp.l, temp.c).letter - 65] != nullptr){

            //std::cout << temp.b(temp.l, temp.c) << " dispo. ";

            if (temp.horizontal){ //horizontal
                if (temp.arriere)
                    empiler(Etat(temp.b, temp.n->fils[temp.b(temp.l, temp.c).letter - 65], temp.hand, temp.l_initial, temp.c_initial, temp.l, temp.c - 1, temp.horizontal, temp.arriere));
                else empiler(Etat(temp.b, temp.n->fils[temp.b(temp.l, temp.c).letter - 65], temp.hand, temp.l_initial, temp.c_initial, temp.l, temp.c + 1, temp.horizontal, temp.arriere));
            } else { //vertical
                if (temp.arriere)
                    empiler(Etat(temp.b, temp.n->fils[temp.b(temp.l, temp.c).letter - 65], temp.hand, temp.l_initial, temp.c_initial, temp.l - 1, temp.c, temp.horizontal, temp.arriere));
                else empiler(Etat(temp.b, temp.n->fils[temp.b(temp.l, temp.c).letter - 65], temp.hand, temp.l_initial, temp.c_initial, temp.l + 1, temp.c, temp.horizontal, temp.arriere));
            }
        } else return;

    }

    if (temp.n->fils[temp.b(temp.l, temp.c).letter - 65]->terminal){
        //std::cout << "Nous avons une solution!\n";
        std::cout << informations(temp);
    }

    //std::cout << informations(temp);

    //this->listerEtats();

}

void Pile::consulterEtats(){
    while (etats.size() > 0){
        listerEtats();
    }
}