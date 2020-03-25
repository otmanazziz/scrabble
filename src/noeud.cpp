#include "noeud.hpp"


Noeud::Noeud(){
    terminal = false;
}
Noeud::Noeud(const bool &term){
    terminal = term;
}

Noeud::~Noeud(){
    for (int i =0; i < 27; i++){
        if (fils[i] != nullptr)
            delete(fils[i]);
    }
}
