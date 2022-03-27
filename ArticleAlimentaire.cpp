#include "ArticleAlimentaire.hpp"
using namespace std;
/*
    ***Cette classe a été créee dans le but de donner ***
    *** des numéros propres aux aliments ***
*/
ArticleAlimentaire::ArticleAlimentaire(string nNom,float nPrix){
    prixArticle=nPrix;
    etatArticle=false;
    nomArticle=nNom;
}

