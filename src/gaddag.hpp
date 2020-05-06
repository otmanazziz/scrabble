#pragma once

#include <iostream>
#include <string>
#include <vector>
#include <fstream>

#include "noeud.hpp"

struct Gaddag{
    
    Noeud fils[27];

    Gaddag();
    ~Gaddag();

    void insertion(std::string word);

    void classicInsertion(std::string word);

    void plusInsertion(std::string word);

    bool recherche(std::string word);
};