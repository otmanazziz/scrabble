#include <iostream>
#include <string>
#include <vector>
#include <fstream>

#include "noeud.hpp"

struct Gaddag{
    std::ifstream fileToRead;
    Noeud fils[26];

    Gaddag();
    ~Gaddag();

    void insertion(std::string word);

    bool recherche(std::string word);
};