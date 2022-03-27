//cette section contient tous les articles de type nourriture
#ifndef SECTIONALIMENT_HPP
#define SECTIONALIMENT_HPP
#include "Section.hpp"
#include "ArticleAlimentaire.hpp"
#include "Article.hpp"
#include <string>
#include <fstream>
class SectionAliment:public Section{
    public:
        SectionAliment();
        void voirSectionALiment();
        void enregistrerArticleAliment();
        void acheterAliment(int num);
        void enregistrerAlimentAchete();
        float calculerCoutAliments();
        std::string afficherArticleALiments();
    private:
//variable avec lesquels on va écrire et lire la liste des aliments
        std::ofstream outfile;
        std::ifstream infile;
        std::vector<ArticleAlimentaire> achetes;
        std::vector<ArticleAlimentaire> articlesAliments;
};
#endif
