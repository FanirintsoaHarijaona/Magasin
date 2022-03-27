//cette section contient tous les articles de type fourniture scolaire
//FS est l'acronyme de fournitures scolaires
#ifndef SECTIONFS_HPP
#define SECTIONFS_HPP
#include <string>
#include <fstream>
#include "Section.hpp"
#include "ArticleFS.hpp"
#include "Article.hpp"
class SectionFS:public Section{
    public:
        SectionFS();
        void voirSectionFS();
        void enregistrerArticleFS();
        std::string afficherArticleFS();
        void acheterFS(int num);
        void enregistrerFSAchete();
        float calculerCoutFS();
    private:
//variable avec lesquels on va écrire et lire la liste des fournitures scolaires
        std::ofstream outfileFS;
        std::ifstream infileFS;
        std::vector <ArticleFS> articlesfournitures;
        std::vector <ArticleFS> achats;
};
#endif
