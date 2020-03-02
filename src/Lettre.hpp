#include <iostream>

struct Lettre{
    //variables
    char lettre;
    int points;

    Lettre(const char &lalettre, const int &lepoint);

    Lettre(const Lettre &temp);

    ~Lettre();

    void informations();
};
