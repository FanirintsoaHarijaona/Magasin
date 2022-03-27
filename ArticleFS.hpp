//ici on créer les articles de classes fournitures scolaires
//Fs est l'acronyme de Fournitures scolaires
#ifndef ARTICLEFS_HPP
#define ARTICLEFS_HPP
#include <fstream>
#include <string>
#include "Article.hpp"
//les articles de fournitures scolaires héritent de la classe article
class ArticleFS:public Article{
    public:
        ArticleFS(std::string nNom,float nPrix);
    
};
#endif