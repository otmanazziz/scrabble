#include "board.hpp"
#include "joueur.hpp"
#include "gaddag.hpp"

#include <iostream>
#include <sstream>
#include <stdlib.h>     /* srand, rand */
#include <time.h>       /* time */

int main() {

  srand(time(NULL));

  Gaddag g;

  if (g.recherche("AA"))
    std::cout << "AA vrai" << std::endl;
  else std::cout << "AA faux" << std::endl;

  if (g.recherche("AALENIEN"))
    std::cout << "AALENIEN vrai" << std::endl;
  else std::cout << "AALENIEN faux" << std::endl;

  //SacLettres *s = new SacLettres();

  //Joueur j1(s);
  

  //std::cout << s.nbLettres;

  //Board b ;

  //std::cout << b << std::endl;
/*
  std::stringstream ss ;
  ss << "..............." << std::endl ;
  ss << "..............." << std::endl ;
  ss << "..............." << std::endl ;
  ss << "..............." << std::endl ;
  ss << "..............." << std::endl ;
  ss << "..............." << std::endl ;
  ss << "..............." << std::endl ;
  ss << "....PROJET....." << std::endl ;
  ss << ".......O......." << std::endl ;
  ss << ".......U......." << std::endl ;
  ss << ".......E......." << std::endl ;
  ss << ".......U......." << std::endl ;
  ss << ".....SCRABBLE.." << std::endl ;
  ss << "..............." << std::endl ;
  ss << "..............." << std::endl ;

  b.load(ss) ;

  std::cout << b << std::endl ;*/

  return 0 ;
}
