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
    etats.pop();
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
    depiler();

    if (temp.b(temp.l, temp.c).letter == NULL){

        if (temp.hand.size() > 0){
            //plus r a faire
        } else {

            for (int i = 0; i < temp.hand.size(); i++){

                if (temp.n[(int)temp.hand[i].lettre - 65].fils != nullptr){
                    
                    temp.b(temp.l, temp.c).letter = temp.hand[i].lettre;

                    if (temp.horizontal){ //horizontal
                        if (temp.arriere)
                            this->empiler(Etat(temp.b, temp.n[(int)temp.hand[i].lettre - 65], temp.hand.erase(temp.hand.begin() + i), temp.l_initial, temp.c_initial, temp.l, temp.c - 1, temp.horizontal, temp.arriere));
                        else return;//empiler(Etat(temp->b, temp->n[(int)temp->hand[i].lettre - 65]->fils, temp->hand.erase(temp->hand.begin() + i), temp->l_initial, temp->c_initial, temp->l, temp->c + 1, temp->horizontal, temp->arriere));
                    } else { //vertical
                        if (temp.arriere)
                            return;//this->empiler(Etat(temp.b, temp.n[(int)temp.hand[i].lettre - 65], temp.hand.erase(temp.hand.begin() + i), temp.l_initial, temp.c_initial, temp.l - 1, temp.c, temp.horizontal, temp.arriere));
                        else return;//empiler(Etat(temp->b, temp->n[(int)temp->hand[i].lettre - 65]->fils, temp->hand.erase(temp->hand.begin() + i), temp->l_initial, temp->c_initial, temp->l + 1, temp->c, temp->horizontal, temp->arriere));
                    }
                    
                }

            }
            

        }

    }/* else { // lettre existante

        if (temp.n[temp.b(temp.l, temp.c).letter - 65] != nullptr){
            if (temp.horizontal){ //horizontal
                if (temp.arriere)
                    empiler(Etat(temp.b, temp.n[temp.b(temp.l, temp.c).letter - 65], temp.hand, temp.l_initial, temp.c_initial, temp.l, temp.c - 1, temp.horizontal, temp.arriere));
                else empiler(Etat(temp.b, temp.n[temp.b(temp.l, temp.c).letter - 65], temp.hand, temp.l_initial, temp.c_initial, temp.l, temp.c + 1, temp.horizontal, temp.arriere));
            } else { //vertical
                if (temp.arriere)
                    empiler(Etat(temp.b, temp.n[temp.b(temp.l, temp.c).letter - 65], temp.hand, temp.l_initial, temp.c_initial, temp.l - 1, temp.c, temp.horizontal, temp.arriere));
                else empiler(Etat(temp.b, temp.n[temp.b(temp.l, temp.c).letter - 65], temp.hand, temp.l_initial, temp.c_initial, temp.l + 1, temp.c, temp.horizontal, temp.arriere));
            }
        }

    }

    //+ est dans le noeud
    if (temp.n[26] != nullptr){
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

    if (temp.n[temp.b(temp.l, temp.c).letter - 65]->terminal){
        std::cout << temp.informations();
    }
    */

}