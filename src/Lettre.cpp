#include "Lettre.hpp"

//constructor
Lettre::Lettre(const char &lalettre, const int &lepoint){
    lettre = lalettre;
    points = lepoint;
}

Lettre::Lettre(const Lettre &temp){
    lettre = temp.lettre;
    points = temp.points;
}

Lettre::~Lettre(){
    lettre = NULL;
    points = NULL;
}

void Lettre::informations(){
    std::cout << lettre << "(" << points << " points)";
}