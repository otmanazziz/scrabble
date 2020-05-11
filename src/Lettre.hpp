#pragma once

#include <iostream>

struct Lettre{
    //variables
    char lettre;
    unsigned int points;

    Lettre(const char &lalettre, const unsigned int &lepoint);

    Lettre(const Lettre &temp);

    ~Lettre();

    std::string informations();
};
