#pragma once

#include <iostream>
#include <vector>
#include <stdlib.h>     /* srand, rand */
#include <time.h>       /* time */

#include "Lettre.hpp"

struct SacLettres{

    std::vector<Lettre> sacLettres;


    //static (sert pour le constructeur)
    const unsigned int lettresOccurences[26] = {9, 2, 2, 3, 15, 2, 2, 2, 8, 1, 1, 5, 3, 6, 6, 2, 3, 6, 6, 6, 6, 2, 1, 1, 1, 1};
    const unsigned int lettresPoints[26] = {1, 3, 3, 2, 1, 4, 2, 4, 1, 8, 10, 1, 2, 1, 1, 3, 2, 1, 1, 1, 1, 4, 10, 10, 10, 10};

    //constructor, destructor
    SacLettres();
    ~SacLettres();

    //return a random letter
    Lettre recupererLettre();

    //check if the bag is empty
    bool sacVide();

    void lettresRestantes();
};