#include "gaddag.hpp"

Gaddag::Gaddag(){
    //read the file
    fileToRead.open("data/dico.txt");
    //check if we can open the file
    if (!fileToRead){
        std::cerr << "Unable to open file dico.txt";
        exit(1);
    }

    std::string word;
    int a = 0;
    do{
        std::cout << word << ": ";
        for (int i = 0; i < word.length(); i++)
            std::cout << word.at(i) << " (" << (int)word.at(i) - 65 << ") ";
        std::cout << std::endl;
        if (word.length() > 0)
            insertion(word);
        a++;
    } while ((fileToRead >> word) && (a < 10));

    //close the file
    fileToRead.close();
}

Gaddag::~Gaddag(){
    
}

void Gaddag::insertion(std::string word){
    Noeud *temp = fils;
    bool term = false;
    int index;
    for (int i = 0; i < word.length(); i++){
        index = (int)word.at(i) - 65;
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

bool Gaddag::recherche(std::string word){
    Noeud *temp = fils;
    int index;
    for (int i = 0; i < word.length(); i++){
        index = (int)word.at(i) - 65;
        if (temp->fils[index] == nullptr)
            return false;
        if (i == word.length() - 1){
                if (temp->fils[index]->terminal)
                    return true;
                else return false;
        }
        temp = temp->fils[index];
    }
    return false;
}
