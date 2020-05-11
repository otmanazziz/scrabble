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

  Board b ;

  std::stringstream ss ;
  ss << "..............." << std::endl ;
  ss << "..............." << std::endl ;
  ss << "..............." << std::endl ;
  ss << "..............." << std::endl ;
  ss << "..............." << std::endl ;
  ss << "..............." << std::endl ;
  ss << "..............." << std::endl ;
  ss << ".......B......." << std::endl ;
  ss << "..............." << std::endl ;
  ss << "..............." << std::endl ;
  ss << "..............." << std::endl ;
  ss << "..............." << std::endl ;
  ss << "..............." << std::endl ;
  ss << "..............." << std::endl ;
  ss << "..............." << std::endl ;
  
  b.save(ss);

  b.load(ss);

  //std::cout << b(7, 8).letter << std::endl;
  //Noeud *temp = g.fils;
  
  j1.lister_coups(b, g);

  //std::cout << b << std::endl ;

  //faire un test aux coordonnées 9/6 */

  while (true){
    std::string word;
    std::cout << "Veuillez entrer un mot: ";
    std::cin >> word;
    g.recherche(word);
  }

  return 0 ;
}
