#include "ArticlePPN.hpp"
using namespace std;
/*
    ***Cette classe a été créee dans le but de donner ***
    *** des numéros propres aux produits de première nécéssité ***
*/
ArticlePPN::ArticlePPN(string nNom,float nPrix){
    prixArticle=nPrix;
    nomArticle=nNom;
    etatArticle=false;
}
