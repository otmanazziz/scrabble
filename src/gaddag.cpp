#include "gaddag.hpp"

Gaddag::Gaddag(){

    std::ifstream fileToRead;
    //read the file
    std::cout << "Ouverture du dictionnaire en cours...";
    fileToRead.open("data/dico.txt");

    //check if we can open the file
    if (!fileToRead){
        std::cerr << "Unable to open file dico.txt";
        exit(1);
    }
    std::cout << " OK." << std::endl;

    std::cout << "Création du GADDAG en cours...";
    //put words into gaddag
    std::string word;
    while (fileToRead >> word){
        insertion(word);
    }
        
    //close the file
    fileToRead.close();
    std::cout << " OK." << std::endl;
}

Gaddag::~Gaddag(){
    //delete(fils);
}

void Gaddag::insertion(std::string word){

    //classic implementation of the word
    classicInsertion(word);

    //implementation of the word with "+" letter
    plusInsertion(word);
}

void Gaddag::classicInsertion(std::string word){
    Noeud *temp = fils;
    bool term = false;
    int index;
    for (int i = 0; i < word.length(); i++){
        //check if the "+" is the current letter
        if (word.at(i) == '+')
            index = 26;
        else index = (int)word.at(i) - 65;

        //check if this is the last word
        if (i == word.length() - 1)
            term = true;

        //check if the letter already exists on tree
        if (temp->fils[index] == nullptr)
            temp->fils[index] = new Noeud(term);
        else {
            //check if the word is terminal
            if (term && !temp->fils[index]->terminal)
                temp->fils[index]->terminal = true;
        }
        temp = temp->fils[index];
    }
}

void Gaddag::plusInsertion(std::string word){
    std::string temp(word.length() + 1, '_');
    //std::cout << temp << std::endl;

    for (int i = 1; i < word.length() + 1; i++){
        temp[i] = '+';
        
        for (int j = 0; j < word.length(); j++){
            if (j < i)
                temp[j] = word[i-j-1];
            else
                temp[j + 1] = word[j];
        }

        //std::cout << temp << std::endl;

        classicInsertion(temp);

    }


}

bool Gaddag::recherche(std::string word){
    std::cout << "Search for the letter " << word << "...";
    Noeud *temp = fils;
    int index;
    for (int i = 0; i < word.length(); i++){
        if (word.at(i) == '+')
            index = 26;
        else index = (int)word.at(i) - 65;
        
        if (temp->fils[index] == nullptr){
            std::cout << "Not matching (letter " << word.at(i) << " not exists)." << std::endl;
            return false;
        }
        if (i == word.length() - 1){
                if (temp->fils[index]->terminal){
                    std::cout << "Matching!" << std::endl;
                    return true;
                }
                else {
                    std::cout << "Not matching (letter " << word.at(i) << " is not a final letter)." << std::endl;
                    return false;
                }
        }
        std::cout << ".";
        temp = temp->fils[index];
    }
    std::cout << "Not matching (unknown error).";
    return false;
}
