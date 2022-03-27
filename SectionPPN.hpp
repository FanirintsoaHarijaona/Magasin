//cette section contient tous les articles de première nécéssité
#ifndef SECTIONPPN_HPP
#define SECTIONPPN_HPP
#include "Section.hpp"
#include "ArticlePPN.hpp"
#include "Article.hpp"
#include <string>
#include <fstream>
#include <vector>
class SectionPPN:public Section{
    public:
        SectionPPN();
        void voirSectionPPN();
        void enregistrerArticlePPN();
        std::string afficherArticlePPN();
        void acheterPPN(int num);
        void enregistrerPPNAchete();
        float calculerCoutPPN();
    private:
//variable avec lesquels on va écrire et lire la liste des articles de PPN
        std::ofstream outfilePPN;
        std::ifstream infilePPN;
        std::vector<ArticlePPN> articlesppn;
        std::vector<ArticlePPN> achat;
};
#endif
