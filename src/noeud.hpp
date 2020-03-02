#include <iostream>
#include <vector>

struct Noeud{
    bool terminal;
    Noeud* fils[26];

    Noeud();

    Noeud(const bool &term);
    ~Noeud();
}; 