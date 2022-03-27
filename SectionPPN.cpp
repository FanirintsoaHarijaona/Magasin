#include "SectionPPN.hpp"
#include <iostream>
using namespace std;
SectionPPN::SectionPPN(){
//On ajoute dans cette section tous les articles dans la section PPN
    ArticlePPN bougie("    bougie",1000),huile("1L d'huile",1500),sel("sachet sel",2000),sucre("1kg sucre",1800),charbon("1kg charbon",2000);
    articlesppn.push_back(bougie);
    articlesppn.push_back(huile);
    articlesppn.push_back(sel);
    articlesppn.push_back(sucre);
    articlesppn.push_back(charbon);
}
void SectionPPN::enregistrerArticlePPN(){
    outfilePPN.open("PPN.csv");
//D'abord on teste si l'ouverture du fichier en mode écriture s'est bien passé ou non
    if(outfilePPN){
    outfilePPN<<afficherArticlePPN();
    outfilePPN<<"\n\n";
    }
    else 
        cout<<"Erreur d'ouverture du fichier..."<<endl;
    outfilePPN.close();
}
void SectionPPN::voirSectionPPN(){
//On va récupérer ligne par ligne les données dans le fichier qui contient les articles ppn
    string ligne;
//D'abord on teste si l'ouverture du fichier en mode lecture s'est bien passé ou non
    infilePPN.open("PPN.csv");
    if(infilePPN){
        while(getline(infilePPN,ligne)){
                cout<<ligne<<endl;
        }
    }
    else
        cout<<"Ouverture du fichier impossible..."<<endl;
    infilePPN.close();
}
void SectionPPN::acheterPPN(int num){
/*  **On diminue de 5 car on a crée un nouvel tableau ici pour contenir les articles PPN
    **Or à chaque fois qu'un article est crée,pour éviter le conflit de numéro,le numero d'article 
    **augmente aussitôt ainsi on a mis les articles PPN dans un nouveau tableau
*/
    articlesppn[num-5].setEtatArticle();
    cout<<articlesppn[num-5].getNomArticle()+" achete";
    achat.push_back(articlesppn[num-5]);
    cout<<endl<<endl;
}
void SectionPPN::enregistrerPPNAchete(){
/* 
    **On écrit dans un fichier le nom des articles avec état true car 
    **c'est la marque que l'article a été acheté**
*/
    outfilePPN.open("PPN_achetés.csv",ios::app);
    for(int compteur=0,longueur=achat.size();compteur<longueur;compteur++){
                if(outfilePPN){
                    outfilePPN<<achat[compteur].getInfoArticle();
                }
                else
                    cout<<"erreur d'ouverture du fichier"<<endl;
        }
        outfilePPN.close();
    }
    
string SectionPPN::afficherArticlePPN(){
//cette méthode est utiliséé afin d'afficher les caractéristiques d'un article PPN
    string result("");
    for(int compteur=0,longueur=articlesppn.size();compteur<longueur;compteur++){
        result+="Nom de l'article:"+articlesppn[compteur].getNomArticle();
        result+="\t\tprix:"+to_string(articlesppn[compteur].getPrixArticle())+" Ariary";
        result+="\t\tnumero d'enregistrement:"+to_string(articlesppn[compteur].getNumeroArticle());
        result+='\n';
    }
    return result;
}
float SectionPPN::calculerCoutPPN(){
//cette méthode calcule le coût total des articles PPN que le client a acheté
    float total(0.0);
    for(int compteur=0,longueur=achat.size();compteur<longueur;compteur++){
            total+=achat[compteur].getPrixArticle();
    }
    return total;
}
