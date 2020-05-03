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

  SacLettres *s = new SacLettres();

  Joueur j1(s);

  Board b ;

  std::stringstream ss ;
  ss << "K.............." << std::endl ;
  ss << "..............." << std::endl ;
  ss << "..............." << std::endl ;
  ss << "..............." << std::endl ;
  ss << ".......B......." << std::endl ;
  ss << ".......L......." << std::endl ;
  ss << ".......A......." << std::endl ;
  ss << ".......T.A....." << std::endl ;
  ss << ".......T.R....." << std::endl ;
  ss << "......TEST....." << std::endl ;
  ss << "..............." << std::endl ;
  ss << "..............." << std::endl ;
  ss << "..............." << std::endl ;
  ss << "..............." << std::endl ;
  ss << "..............." << std::endl ;
  
  b.save(ss);

  b.load(ss);

  //std::cout << b(7, 8).letter << std::endl;

  j1.lister_coups(b, g.fils);

  //std::cout << b << std::endl ;

  //faire un test aux coordonnées 9/6 */

  return 0 ;
}
