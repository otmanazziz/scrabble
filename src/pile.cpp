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
        //std::cout << "Etat dépilé.";
        etats.pop();
    } //else std::cout << "[ERREUR] Pile vide.";
        
}

Etat Pile::getEtat(){
    if (!etats.empty()){
        return etats.top();
    }    
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

    depiler();

    if (temp.c <= 14 && temp.l <= 14){

        //Letter is not placed at the position
        if (temp.b(temp.l, temp.c).letter == 0){

            //+ exists on the node
            if (temp.n->fils[26] != nullptr){
                //std::cout << "+ dispo. On va vers l'avant. ";
                if (temp.horizontal){
                    if (temp.b(temp.l, temp.c - 1).letter == 0)
                        empiler(Etat(temp.b, temp.n->fils[26], temp.hand, temp.l_initial, temp.c_initial, temp.l, temp.c_initial + 1, temp.horizontal, false));
                }
                else 
                {
                    if (temp.b(temp.l - 1, temp.c).letter == 0)
                        empiler(Etat(temp.b, temp.n->fils[26], temp.hand, temp.l_initial, temp.c_initial, temp.l_initial + 1, temp.c, temp.horizontal, false));
                }
                
            }

            if (temp.hand.size() == 0){
                return;
            } else {

                for (unsigned int i = 0; i < temp.hand.size(); i++){

                    if (temp.n->fils[(int)temp.hand[i].lettre - 65] != nullptr){

                        //std::cout << temp.hand[i].lettre << " dispo. ";

                            temp.b(temp.l, temp.c).letter = temp.hand[i].lettre;
                            std::vector<Lettre> hand = temp.hand;
                            hand.erase(hand.begin() + i);

                            if (temp.horizontal){ //horizontal
                                //if (temp.b(temp.l + 1, temp.c).letter != 0 || temp.b(temp.l - 1, temp.c).letter != 0){
                                    //if (wordIsGreat(g, temp)){
                                if (temp.arriere){
                                    empiler(Etat(temp.b, temp.n->fils[(int)temp.hand[i].lettre - 65], hand, temp.l_initial, temp.c_initial, temp.l, temp.c - 1, temp.horizontal, temp.arriere, temp.b(temp.l, temp.c).letter));
                                }else if(!temp.arriere){
                                    empiler(Etat(temp.b, temp.n->fils[(int)temp.hand[i].lettre - 65], hand, temp.l_initial, temp.c_initial, temp.l, temp.c + 1, temp.horizontal, temp.arriere, temp.b(temp.l, temp.c).letter));
                                     }
                                //}
                                    
                            } else if(!temp.horizontal){ //vertical
                                    //if (temp.b(temp.l, temp.c + 1).letter != 0 || temp.b(temp.l, temp.c - 1).letter != 0){
                                            //if (wordIsGreat(g, temp)){
                                if (temp.arriere)
                                    empiler(Etat(temp.b, temp.n->fils[(int)temp.hand[i].lettre - 65], hand, temp.l_initial, temp.c_initial, temp.l - 1, temp.c, temp.horizontal, temp.arriere, temp.b(temp.l, temp.c).letter));
                                else if(!temp.arriere)
                                    empiler(Etat(temp.b, temp.n->fils[(int)temp.hand[i].lettre - 65], hand, temp.l_initial, temp.c_initial, temp.l + 1, temp.c, temp.horizontal, temp.arriere, temp.b(temp.l, temp.c).letter));
                                            //}
                                    //}
                                //}
                            }       
                        } else return;

                        //std::cout << temp.informations();
                    }
                    
                    //if (nbSolutions == 0)
                        //return;
                }

                


        } else { // lettre existante

            //std::cout << "--> (" << temp.l << ", " << temp.c << ") non vide. ";

            if (temp.n->fils[temp.b(temp.l, temp.c).letter - 65] != nullptr){

                //std::cout << temp.b(temp.l, temp.c) << " dispo. ";

                if (temp.horizontal){ //horizontal
                    if (temp.arriere)
                        empiler(Etat(temp.b, temp.n->fils[temp.b(temp.l, temp.c).letter - 65], temp.hand, temp.l_initial, temp.c_initial, temp.l, temp.c - 1, temp.horizontal, temp.arriere, temp.b(temp.l, temp.c).letter));
                    else
                        empiler(Etat(temp.b, temp.n->fils[temp.b(temp.l, temp.c).letter - 65], temp.hand, temp.l_initial, temp.c_initial, temp.l, temp.c + 1, temp.horizontal, temp.arriere, temp.b(temp.l, temp.c).letter));
                } else { //vertical
                    if (temp.arriere)
                        empiler(Etat(temp.b, temp.n->fils[temp.b(temp.l, temp.c).letter - 65], temp.hand, temp.l_initial, temp.c_initial, temp.l - 1, temp.c, temp.horizontal, temp.arriere, temp.b(temp.l, temp.c).letter));
                    else
                        empiler(Etat(temp.b, temp.n->fils[temp.b(temp.l, temp.c).letter - 65], temp.hand, temp.l_initial, temp.c_initial, temp.l + 1, temp.c, temp.horizontal, temp.arriere, temp.b(temp.l, temp.c).letter));
                }
            } else return;

        }

        if (temp.n->fils[temp.b(temp.l, temp.c).letter - 65]->terminal){
            //std::cout << "Nous avons une solution!\n";
            std::cout << informations(temp);
            //temp.calculerPoints();
        }
    }
    //std::cout << informations(temp);

    //this->listerEtats();

}

void Pile::consulterEtats(){
    while (etats.size() > 0){
        listerEtats();
    }
}

bool Pile::wordIsGreat(Gaddag g, Etat e){
    std::string word = "";

    unsigned int line = e.l;
    unsigned int col = e.c;

    if (e.horizontal){
        while (e.b(line - 1, col).letter != 0){
            line --;
        }
        while(e.b(line, col).letter != 0 && line <= 14){
            word.push_back(e.b(line, col).letter);
        }
    } else {
        while (e.b(line, col - 1).letter != 0){
            col --;
        }
        while(e.b(line, col).letter != 0 && col <= 14){
            word.push_back(e.b(line, col).letter);
        }
    }

    return g.recherche(word);

}