#include <iostream>
#include <sstream>
#include <stdlib.h>     /* srand, rand */
#include <time.h>       /* time */
#include <string>
#include <ctype.h> //char is empty or not

#include "board.hpp"
#include "joueur.hpp"
#include "gaddag.hpp"


int main() {

  srand(time(NULL));

  Gaddag g;
  g.recherche("TEST");
  g.recherche("B+ATEAU");

  SacLettres *s = new SacLettres();

  Joueur j1(s);

  Board b;

  std::stringstream ss ;
  ss << "..............." << std::endl ;
  ss << "..............." << std::endl ;
  ss << "..............." << std::endl ;
  ss << "..............." << std::endl ;
  ss << "..............." << std::endl ;
  ss << "..............." << std::endl ;
  ss << "..............." << std::endl ;
  ss << "..............." << std::endl ;
  ss << "..............." << std::endl ;
  ss << "..............." << std::endl ;
  ss << "..............." << std::endl ;
  ss << "..............." << std::endl ;
  ss << "..............." << std::endl ;
  ss << "..............." << std::endl ;
  ss << "..............." << std::endl ;
  
  b.save(ss);
  b.load(ss);

  //std::cout << b;

  while (!s->sacVide()){
    b = j1.lister_coups(b, g);
    std::cout << b;
    std::cout << j1.informations();

    
    do{
      std::cout << "Please press any key to continue...";
    }
    while (std::cin.get() != '\n');

    j1.recharger(s);
  }

  return 0 ;
}
