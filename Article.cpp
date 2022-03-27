#include "Article.hpp"
using namespace std;
int i=0;
Article::Article(){
    numeroArticle=i++;
    etatArticle=false;
}
//On définit les prix des articles dans ce constructeur
Article::Article(std::string nNom,float nPrix){
    numeroArticle=i++;
    nomArticle=nNom;
    prixArticle=nPrix;
}
Article::~Article(){
}
//méthode qui renvoie le prix de l'article
float Article::getPrixArticle(){
    return prixArticle;
}
//méthode qui renvoie le numéro de l'article
int Article::getNumeroArticle(){
    return numeroArticle;
}
//méthode qui renvoie le nom d'un article
string Article::getNomArticle(){
    return nomArticle;
}
string Article::getInfoArticle(){
    string result("");
    result+="Nom de l'article:"+nomArticle;
    result+="\t\tprix:"+to_string(prixArticle)+"Ariary";
    result+="\t\tnumero d'enregistrement:"+to_string(numeroArticle)+"\n\n";
    return result;
}
bool Article::getEtatArticle(){
    return etatArticle;
}
void Article::setEtatArticle(){
    etatArticle=true;
}