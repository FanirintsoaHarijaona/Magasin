//cette classe définit les actions effectuées par la caisse du magasin
#ifndef CAISSE_HPP
#define CAISSE_HPP
#include <fstream>
#include <iostream>
#include "Menu.hpp"
class Caisse{
    public:
        Caisse();
        ~Caisse();
        void afficherFacture();
    private:
        std::ifstream infileCaisse;
};
#endif