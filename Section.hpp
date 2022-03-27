#ifndef SECTION_HPP
#define SECTION_HPP
#include "Article.hpp"
#include <vector>
//on a inclu Article.hpp car une section contient des articles
//Cette classe étant le modèle de toutes les classes de section d'articles,on l'a rendu abstraite
class Section{
    public:
        Section();
        ~Section();
        std::string afficherArticle();
    protected:
        std::vector<Article> articles;
};
#endif