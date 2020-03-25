#include <iostream>
#include <vector>

struct Noeud{
    bool terminal;
    Noeud* fils[27];

    Noeud();

    Noeud(const bool &term);
    ~Noeud();
}; 