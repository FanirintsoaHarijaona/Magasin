#include "Caisse.hpp"
#include <iostream>
using namespace std;
Caisse::Caisse(){

}
Caisse::~Caisse(){

}
/* 
    **lorsque l'utilisateur a fini ces achats,**
    **il passe à la caisse pour recevoir la   **
    **facture**
*/
void Caisse::afficherFacture(){
    string result("");
    string line,nom;
    cout<<"Indiquez votre nom s'il vous plait:";
    cin>>nom;
    cout<<"\n\n\n*********************************************************************************************************************************"<<endl;
    cout<<"\t\t\t\t\t\tMAGASIN AOMIN "<<endl;
    cout<<"*********************************************************************************************************************************"<<endl;
    cout<<"\n\nClient:"+nom+"\n\n"<<endl;
    cout<<"\t\t\t\tArticles achetes"<<endl;
//On ouvre le fichier qui contient les aliments achetés 
    infileCaisse.open("aliments_achetés.csv");
    if(infileCaisse){
//si le client a achete des aliments,on enregistre les données dans une chaîne
        while(getline(infileCaisse,line)){
            result+=line;
            result+='\n';
        }
    }
//sinon on affiche la phrase ci-dessous
    else 
        cout<<"Vous n'avez achete aucun aliment"<<endl;
    infileCaisse.close();
//si le client a achete des produits de première nécéssité,on enregistre les données dans une chaîne
    infileCaisse.open("fournitures_achetés.csv");
    if(infileCaisse){
        while(getline(infileCaisse,line)){
            result+=line;
            result+'\n';
            result+="\n";
            }
        }
//sinon on affiche la phrase ci-dessous
    else 
        cout<<"Vous n'avez achete aucune fourniture"<<endl;
    infileCaisse.close();
///On ouvre le fichier qui contient les aliments achetés 
    infileCaisse.open("PPN_achetés.csv");
//si le client a achete des fournitures scolaires,on enregistre les données dans une chaîne
    if(infileCaisse){
        while(getline(infileCaisse,line)){
            result+=line;
            result+='\n';
        }
    }
//sinon on affiche la phrase ci-dessous
    else 
        cout<<"Vous n'avez acheté aucun PPN"<<endl;
    infileCaisse.close();
    result+='\n';
    result+="_____________________________________________________________________________________________________________________\n";
    infileCaisse.open("total.csv");
//On ouvre le fichier qui contient le total des achats que le client a effectue
    if(infileCaisse){
        while(getline(infileCaisse,line)){
            result+=line;
            result+='\n';
        }
    }
    else
        cout<<"Total nul"<<endl;
    result+="\nMerci beaucoup de votre visite.\n\n";
    result+="Au revoir et bonne journee\n";
    infileCaisse.close();
    cout<<result;
}