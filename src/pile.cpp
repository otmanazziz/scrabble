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

void Pile::listerEtats(Board b, Noeud n[27], std::vector<Lettre> hand, int line, int col, bool vertical){
    
}