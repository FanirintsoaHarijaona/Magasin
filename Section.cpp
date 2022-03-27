#include "Section.hpp"
//***bibliothèque permettant de convertir un entier en string***
#include <sstream>
using namespace std;
//***Constructeur de la section***
Section::Section(){

}
Section::~Section(){
    
}
string Section::afficherArticle(){
/* ***On crée deux chaînes de caractères pour y stocker l'affichage ***
   ***et la version chaîne du prix des articles*** */
    string result;
   for(int compteurVector=0,longueur=articles.size();compteurVector<longueur;compteurVector++)
        result+=articles[compteurVector].getInfoArticle();
    return result;
}