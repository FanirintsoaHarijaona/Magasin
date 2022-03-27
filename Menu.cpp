#include "Menu.hpp"
#include <iostream>

using namespace std;
//définition du constructeur du menu
//déclaration des différentes séctions qui existe dans le magasin
Menu::Menu(){
//A chaque objet menu crée on affiche les articles dans le magasin
    section1=new SectionAliment();
    section1->enregistrerArticleAliment();
    section2=new SectionPPN();
    section2->enregistrerArticlePPN();
    section3=new SectionFS();
    section3->enregistrerArticleFS();
}
Menu::~Menu(){
    delete section1;
    delete section2;
    delete section3;
}
//méthode qui affiche le menu à l'écran
void Menu::afficherMenu(){
    cout<<"Bienvenue dans notre magasin"<<endl;
    cout<<"Que pouvons-nous faire pour vous?"<<endl;
    cout<<"Tapez 1 pour continuer et 0 pour quitter\n";
}
//méthode qui permet de saisir le choix du visiteur
void Menu::saisirChoix(){
    cout<<"Votre choix:";
    cin>>choix;
}
void Menu::gererChoix(bool &etat){
//méthode qui permet de gérer le choix insérer par l'utilisateur
    if(etat==true){
        switch(choix){
            case 0:
//On quitte le programme
                cout<<"A la prochaine alors...\nMerci de votre visite (._.)"<<endl;
                etat=false;
                break;
            case 1:
//on affiche à l'écran les différentes séctions
                afficherOption();
//On saisit le choix de l'utilisateur
                saisirChoix();
//On gère à nouveau le choix comme précedemment
                switch(choix){
                    case 0:
                        cout<<"A la prochaine alors...\nMerci de votre visite (._.)"<<endl;
                        etat=false;
                        break;
                    case 1:
//on affiche la section qui contient les articles alimentaires    
                        section1->voirSectionALiment();
                        afficherOptionRetour();
                        saisirChoix();
//traitement du choix du visiteur s'il veut ou non acheter des articles
                        if(choix==0){
                            cout<<"A la prochaine alors...\nMerci de votre visite (._.)"<<endl;
                            etat=false;
                        }
                        else if(choix>0&&choix<5){
//le client achète l'aliment
                            section1->acheterAliment(choix);
                            section1->enregistrerAlimentAchete();
                        }
                        else 
                            afficherOption();
                        break;
                    case 2:
//On affiche les articles ppn dans la section ppn
                        section2->voirSectionPPN();
                        afficherOptionRetour();
                        saisirChoix();
//traitement du choix du visiteur s'il veut ou non acheter des articles
                        if(choix==0){
                            cout<<"A la prochaine alors...\nMerci de votre visite (._.)"<<endl;
                            etat=false;
                        }
                        else if(choix>4&&choix<10){
//le client a acheté un des produits dans la section ppn
                            section2->acheterPPN(choix);
                            section2->enregistrerPPNAchete();
                        }
                        else 
                            afficherOption();
                        break;
                    case 3:
//on affiche les articles contenus dans la section fournitures scolaires
                        section3->voirSectionFS();
                        afficherOptionRetour();
                        saisirChoix();
//traitement du choix du visiteur s'il veut ou non acheter des articles
                        if(choix==0){
                            cout<<"A la prochaine alors...\nMerci de votre visite (._.)"<<endl;
                            etat=false;
                        }
                        else if(choix>9&&choix<15){
//le client a acheté un des produits dans la section fourniture scolaire
                            section3->acheterFS(choix);
                            section3->enregistrerFSAchete();
                        }
                        else 
                            afficherOption();
                        break;
                    default:
                        afficherOption();
                        saisirChoix();
                        break;
                }
                break;
//choix invalide et on demande au client de saisir un nouveau choix
            default:
                cout<<"Choix invalide,veuillez choisir 1 pour continuer et 0 pour quitter"<<endl;
                saisirChoix();
                break;
        }
    }
}
//afficher les options disponibles dans un magasin
void Menu::afficherOption(){
    cout<<"\nVoici les sections d'articles dans notre magasin"<<endl;
    cout<<"\n1-Section aliment\t\t2-Section PPN\t\t3-Section fourniture scolaire\n\n";
    cout<<"\t\tTapez 1 pour voir les articles alimentaires dans la section aliment\n"<<endl;
    cout<<"\t\tTapez 2 pour voir les articles de premiere necessite dans la section PPN\n"<<endl;
    cout<<"\t\tTapez 3 pour voir les articles scolaires dans la section fourniture scolaire\n"<<endl;
    cout<<"\t\tTapez 0 pour quitter"<<endl;
}
void Menu::afficherOptionRetour(){
    cout<<"\n\t\tTapez le numero d'enregistrement de l'article pour pouvoir l'acheter\n\n";
    cout<<"\t\tTapez 0 pour quitter\n"<<endl;
    cout<<"\t\tTapez autres touches pour revenir au menu principal\n"<<endl;
}
//On enregistre les dépenses du client
void Menu::stockerTotal(){
    float depense=section1->calculerCoutAliments();
    depense+=section2->calculerCoutPPN();
    depense+=section3->calculerCoutFS();
    file.open("total.csv");
        if(file){
            file<<"Total:\t\t\t\t\t";
            file<<depense;
            file<<" Ariary";
        }
        else
            cout<<"Facture impossible"<<endl;
    file.close();
}