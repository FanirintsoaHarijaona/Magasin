#include "Caisse.hpp"
#include <vector>
int main(){
//on affiche le menu jusqu'à ce que le client ait terminé ces achats
    bool Etat(true);
    Menu menu;
    while(Etat){
    menu.afficherMenu();
    menu.saisirChoix();
    menu.gererChoix(Etat);
    menu.stockerTotal();
    }
//Après les achats du client la caisse affiche le total des articles qu'il a acheté
    Caisse caisse;
    caisse.afficherFacture();
    return 0;
}