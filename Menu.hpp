//Ce fichier affichera ce que l'on peut trouver dans un magasin 
//inclusion de ce fichier s'il n'est pas encore inclu
#ifndef MENU_HPP
#define MENU_HPP
#include <vector>
#include <fstream>
#include <string>
#include "SectionAliment.hpp"
#include "SectionPPN.hpp"
#include "SectionFS.hpp"
 class Menu{
     public:
        Menu();
        ~Menu();
        void afficherMenu();
        void saisirChoix();
        void gererChoix(bool &etat);
        void afficherOption();
        void afficherOptionRetour();
        void stockerTotal();
//cette dépense sera affichée par la caisse
    private:
//variable qui permet de stocker le choix de l'utilisateur
        int choix;
        SectionAliment *section1;
        SectionPPN *section2;
        SectionFS *section3;
        std::ofstream file;
 };
 #endif