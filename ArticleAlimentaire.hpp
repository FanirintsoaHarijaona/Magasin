//ici on créer les articles de classes alimentaires
#ifndef ARTICLE_ALIMENTAIRE_HPP
#define ARTICLE_ALIMENTAIRE_HPP
#include <fstream>
#include <string>
#include "Article.hpp"
//article alimentaire hérite de article
class ArticleAlimentaire:public Article{
    public:
        ArticleAlimentaire(std::string nNom,float nPrix);
};
#endif