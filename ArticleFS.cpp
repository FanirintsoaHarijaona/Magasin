#include "ArticleFS.hpp"
using namespace std;
/*
    ***Cette classe a été créee dans le but de donner ***
    *** des numéros propres aux articles de fournitures scolaires ***
*/
ArticleFS::ArticleFS(string nNom,float nPrix){
    prixArticle=nPrix;
    nomArticle=nNom;
    etatArticle=false;
}