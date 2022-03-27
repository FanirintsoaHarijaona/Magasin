//On a construit les articles en 3 catégories pour mieux les différencier
#ifndef ARTICLEPPN_HPP
#define ARTICLEPPN_HPP
#include <fstream>
#include <string>
#include "Article.hpp"
//cette classe d'article de ppn héritre de la classe article
class ArticlePPN:public Article{
    public:
        ArticlePPN(std::string nNom,float nPrix);
        std::string getInfoArticlePPN();
    
};
#endif