#include "Lettre.hpp"

//constructor
Lettre::Lettre(const char &lalettre, const unsigned int &lepoint){
    lettre = lalettre;
    points = lepoint;
}

Lettre::Lettre(const Lettre &temp){
    lettre = temp.lettre;
    points = temp.points;
}

Lettre::~Lettre(){

}

std::string Lettre::informations(){
    std::string res;
    res.push_back(lettre);
    res += "(" + std::to_string(points) + ")";
    return res;
}