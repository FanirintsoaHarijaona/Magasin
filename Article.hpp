/*
    ***cette classe spécifie les caractéristiques d'un article***
*/
#ifndef ARTICLE_HPP
#define ARTICLE_HPP
#include <string>
class Article{
    public:
        Article();
        Article(std::string nNom,float nPrix);
        ~Article();
        std::string getNomArticle();
        float getPrixArticle();
        std::string getInfoArticle();
        int getNumeroArticle();
        bool getEtatArticle();
        void setEtatArticle();
    protected:
        std::string nomArticle;
        float prixArticle;
        int numeroArticle;
        bool etatArticle;
};
#endif