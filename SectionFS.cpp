#include "SectionFS.hpp"
#include <iostream>
using namespace std;
SectionFS::SectionFS(){
//On ajoute dans cette section tous les articles dans la section fournitures scolaires
    ArticleFS regle("  regle",900),protege("protege",500),compas("  compas",700),gomme("  gomme",200),crayon("  crayon",200);
    articlesfournitures.push_back(regle);
    articlesfournitures.push_back(protege);
    articlesfournitures.push_back(compas);
    articlesfournitures.push_back(gomme);
    articlesfournitures.push_back(crayon);
}
void SectionFS::enregistrerArticleFS(){
    outfileFS.open("fournitures.csv");
//D'abord on teste si l'ouverture du fichier en mode écriture s'est bien passé ou non
    if(outfileFS){
    outfileFS<<afficherArticleFS();
    }
    else 
        cout<<"Erreur d'ouverture du fichier..."<<endl;;
    outfileFS.close();
}
void SectionFS::voirSectionFS(){
//On va récupérer ligne par ligne les données dans la section fourniture scolaire
    string ligne;
//D'abord on teste si l'ouverture du fichier en mode lecture s'est bien passé ou non
    infileFS.open("fournitures.csv");
    if(infileFS){
        while(getline(infileFS,ligne)){
                cout<<ligne<<endl;
                cout<<endl;
        }
    }
    else
        cout<<"Ouverture du fichier impossible..."<<endl;
    infileFS.close();
}
void SectionFS::acheterFS(int num){
/*
    **On a diminué de 10 l'indice car ce tableau est un nouveau tableau**
    **qui vient d'être créer pour seulement y stocker les articles     **
    **fournitures scolaires**
*/
    cout<<articlesfournitures[num-10].getNomArticle()+" achete";
    achats.push_back(articlesfournitures[num-10]);
    cout<<endl<<endl;
}
void SectionFS::enregistrerFSAchete(){
//On ouvre en écriture un fichier dans lequel on va stocker les fournitures achetés
    outfileFS.open("fournitures_achetés.csv",ios::app);
    for(int compteur=0,longueur=achats.size();compteur<longueur;compteur++){
                if(outfileFS){
                    outfileFS<<achats[compteur].getInfoArticle();
                }
                else
                    cout<<"erreur d'ouverture du fichier"<<endl;
        }
    outfileFS.close();
}
string SectionFS::afficherArticleFS(){
//on se sert de cette méthode lorsque l'on veut afficher un article de type fourniture scolaire
string result("");
    for(int compteur=0,longueur=articlesfournitures.size();compteur<longueur;compteur++){
        result+="Nom de l'article:"+articlesfournitures[compteur].getNomArticle();
        result+="\t\tprix:"+to_string(articlesfournitures[compteur].getPrixArticle())+" Ariary";
        result+="\t\tnumero d'enregistrement:"+to_string(articlesfournitures[compteur].getNumeroArticle());
        result+='\n';
    }
    return result;
}
float SectionFS::calculerCoutFS(){
//Ici on calcule le total des dépenses des fournitures scolaires que le client a acheté
    float total(0.0);
    for(int compteur=0,longueur=achats.size();compteur<longueur;compteur++){
            total+=achats[compteur].getPrixArticle();
    }
    return total;
}