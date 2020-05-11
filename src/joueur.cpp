#include "joueur.hpp"

Joueur::Joueur(SacLettres *s){
    for (unsigned int i = 0; i < tailleMainJoueur; i++){
        if (!s->sacVide())
            mainJoueur.push_back(s->recupererLettre());
        else break;
    }
}

void Joueur::recharger(SacLettres *s){
    while (mainJoueur.size() < tailleMainJoueur){
        if (!s->sacVide())
            mainJoueur.push_back(s->recupererLettre());
        else break;
    }
}

void Joueur::retirerLettre(unsigned int i){
    if (mainJoueur.size() > 0){
        std::cout << "Retirer lettre " << i << std::endl;
        mainJoueur.erase(mainJoueur.begin() + i);
    }
}

std::string Joueur::informations(){
    if (mainJoueur.size() == 0)
        return "La main du joueur est vide.";
    else {
        std::string res;
        res += "La main du joueur : ";
        for (unsigned int i = 0; i < mainJoueur.size(); i++){
            res += mainJoueur[i].informations() + " ";
        }
        return res + "\n";
    }
}

void Joueur::lister_coups(Board b, Gaddag g){
    std::cout << "Préparation de la liste des coups.. Mais avant regardez le plateau initial avec la main du Joueur.\n";
    p = new Pile();
    Noeud *racine = g.fils;

    if (b(7, 7).letter == 0){
        p->empiler(Etat(b, racine, mainJoueur, 7, 7, 7, 7, false, true));
        p->empiler(Etat(b, racine, mainJoueur, 7, 7, 7, 7, true, true));
    } else {
        for (unsigned int i = 0; i < 15; i++){
            for (unsigned int j = 0; j < 15; j++){

                unsigned int line, col;

                if (b(i, j).letter == 0){
                    if (i > 0 && i < 14 && j > 0 && j < 14){
                        if (b(i+1, j).letter != 0 || b(i-1, j).letter != 0 || b(i, j+1).letter != 0 || b(i, j-1).letter != 0){
                            line = i;
                            col = j;
                        }
                    } else {
                        if (i == 0){
                            if (j == 0){
                                if (b(i+1, j).letter != 0 || b(i, j+1).letter != 0){
                                    line = i;
                                    col = j;
                                }
                            }
                            
                            else if (j == 14){
                                if (b(i+1, j).letter != 0 || b(i, j-1).letter != 0){
                                    line = i;
                                    col = j;
                                }
                            }
                            
                            else {
                                if (b(i+1, j).letter != 0 || b(i, j+1).letter != 0 || b(i, j-1).letter != 0){
                                    line = i;
                                    col = j;
                                }
                            }
                        } 
                        
                        else if (i == 14){
                            if (j == 0){
                                if (b(i-1, j).letter != 0 || b(i, j+1).letter != 0){
                                    line = i;
                                    col = j;
                                }
                            }
                            
                            else if (j == 14){
                                if (b(i-1, j).letter != 0 || b(i, j-1).letter != 0){
                                    line = i;
                                    col = j;
                                }
                            }
                            
                            else {
                                if (b(i-1, j).letter != 0 || b(i, j+1).letter != 0 || b(i, j-1).letter != 0){
                                    line = i;
                                    col = j;
                                }
                            }
                        }

                        else if (j == 0){
                            if (i == 14){
                                if (b(i-1, j).letter != 0 || b(i, j+1).letter != 0){
                                    line = i;
                                    col = j;
                                }
                            }
                            
                            else {
                                if (b(i-1, j).letter != 0 || b(i+1, j).letter != 0 || b(i, j+1).letter != 0){
                                    line = i;
                                    col = j;
                                }
                            }
                        }
                        
                        
                        else if (j == 14){
                            if (i == 0){
                                if (b(i+1, j).letter != 0 || b(i, j-1).letter != 0){
                                    line = i;
                                    col = j;
                                }
                            } else {
                                if (b(i-1, j).letter != 0 || b(i+1, j).letter != 0 || b(i, j-1).letter != 0){
                                    line = i;
                                    col = j;
                                }
                            }
                        }
                    }
                }


                if (line == i && col == j){
                    std::cout << "Letter[" << line << ", " << col << "]\n";
                    p->empiler(Etat(b, racine, mainJoueur, line, col, line, col, true, true));
                    p->empiler(Etat(b, racine, mainJoueur, line, col, line, col, false, true));
                }

            }
        }
    }
    p->consulterEtats();
    
}