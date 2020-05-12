#include "pile.hpp"
    
Pile::Pile(){
    std::cout << "Pile initialisée.\n";
}

Pile::~Pile(){
    while (!etats.empty())
        etats.pop();
    while (!greatWords.empty())
        greatWords.pop();
}

void Pile::empiler(Etat e){
    etats.push(e);
}

void Pile::depiler(){
    if (etats.size() > 0){
        etats.pop();
    }   
}

Etat Pile::getEtat(){
    return etats.top();
}

std::string Pile::informations(Etat e){

    std::string res = "************************[ PILE ]************************\n";

    res += e.informations();

    res += "********************************************************\n\n";
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
                        empiler(Etat(temp.b, temp.n->fils[26], temp.hand, temp.l_initial, temp.c_initial, temp.l, temp.c_initial + 1, temp.horizontal, false, temp.nbPoints));
                }
                else 
                {
                    if (temp.b(temp.l - 1, temp.c).letter == 0)
                        empiler(Etat(temp.b, temp.n->fils[26], temp.hand, temp.l_initial, temp.c_initial, temp.l_initial + 1, temp.c, temp.horizontal, false, temp.nbPoints));
                }
            }

            if (temp.hand.size() == 0){
                return;
            } else {

                for (unsigned int i = 0; i < temp.hand.size(); i++){

                    if (temp.n->fils[(int)temp.hand[i].lettre - 65] != nullptr){

                        //std::cout << temp.hand[i].lettre << " dispo. ";

                            std::vector<Lettre> hand = temp.hand;
                            temp.b(temp.l, temp.c).letter = hand[i].lettre;
                            temp.b(temp.l, temp.c).points = hand[i].points;
                            unsigned int points = temp.nbPoints + temp.b(temp.l, temp.c).points;
                            hand.erase(hand.begin() + i);

                            if (temp.horizontal){ //horizontal
                                //if (temp.b(temp.l + 1, temp.c).letter != 0 || temp.b(temp.l - 1, temp.c).letter != 0){
                                    //if (wordIsGreat(g, temp)){
                                if (temp.arriere){
                                    empiler(Etat(temp.b, temp.n->fils[(int)temp.hand[i].lettre - 65], hand, temp.l_initial, temp.c_initial, temp.l, temp.c - 1, temp.horizontal, temp.arriere, points));
                                }else if(!temp.arriere){
                                    empiler(Etat(temp.b, temp.n->fils[(int)temp.hand[i].lettre - 65], hand, temp.l_initial, temp.c_initial, temp.l, temp.c + 1, temp.horizontal, temp.arriere, points));
                                     }
                                //}
                                    
                            } else if(!temp.horizontal){ //vertical
                                    //if (temp.b(temp.l, temp.c + 1).letter != 0 || temp.b(temp.l, temp.c - 1).letter != 0){
                                            //if (wordIsGreat(g, temp)){
                                if (temp.arriere)
                                    empiler(Etat(temp.b, temp.n->fils[(int)temp.hand[i].lettre - 65], hand, temp.l_initial, temp.c_initial, temp.l - 1, temp.c, temp.horizontal, temp.arriere, points));
                                else if(!temp.arriere)
                                    empiler(Etat(temp.b, temp.n->fils[(int)temp.hand[i].lettre - 65], hand, temp.l_initial, temp.c_initial, temp.l + 1, temp.c, temp.horizontal, temp.arriere, points));
                                            //}
                                    //}
                                //}
                            }       
                    }

                        //std::cout << temp.informations();
                }
                    
                    //if (nbSolutions == 0)
                        //return;
            }

                


        } else { // lettre existante

            //std::cout << "--> (" << temp.l << ", " << temp.c << ") non vide. ";

            if (temp.n->fils[temp.b(temp.l, temp.c).letter - 65] != nullptr){

                //std::cout << temp.b(temp.l, temp.c) << " dispo. ";
                unsigned int points = temp.nbPoints + temp.b(temp.l, temp.c).points;

                if (temp.horizontal){ //horizontal
                    if (temp.arriere)
                        empiler(Etat(temp.b, temp.n->fils[temp.b(temp.l, temp.c).letter - 65], temp.hand, temp.l_initial, temp.c_initial, temp.l, temp.c - 1, temp.horizontal, temp.arriere, points));
                    else
                        empiler(Etat(temp.b, temp.n->fils[temp.b(temp.l, temp.c).letter - 65], temp.hand, temp.l_initial, temp.c_initial, temp.l, temp.c + 1, temp.horizontal, temp.arriere, points));
                } else { //vertical
                    if (temp.arriere)
                        empiler(Etat(temp.b, temp.n->fils[temp.b(temp.l, temp.c).letter - 65], temp.hand, temp.l_initial, temp.c_initial, temp.l - 1, temp.c, temp.horizontal, temp.arriere, points));
                    else
                        empiler(Etat(temp.b, temp.n->fils[temp.b(temp.l, temp.c).letter - 65], temp.hand, temp.l_initial, temp.c_initial, temp.l + 1, temp.c, temp.horizontal, temp.arriere, points));
                }
            } else return;

        }

        if (temp.n->terminal == true && temp.arriere == false){
            //std::cout << informations(temp);
            greatWords.push(temp);
        }
    }
    //std::cout << informations(temp);

    //this->listerEtats();

}

void Pile::consulterEtats(){
    while (etats.size() > 0){
        listerEtats();
    }
    meilleurCoup();
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

void Pile::meilleurCoup(){
    Etat temp = greatWords.top();

    greatWords.pop();

    while(!greatWords.empty()){
        Etat temporary = greatWords.top();
        greatWords.pop();

        if (temporary.nbPoints > temp.nbPoints)
            temp = temporary;

    }
    greatWords.push(temp);
}