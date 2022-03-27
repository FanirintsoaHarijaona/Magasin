#include "SectionAliment.hpp"
#include <iostream>
using namespace std;
SectionAliment::SectionAliment(){
//On ajoute dans cette section tous les articles dans la section alimentaire
//On a détérminé les légumes dans un rayon légume avec les mêmes prix
    ArticleAlimentaire riz("    riz",1400),oeuf("   oeuf",1500),legumes("legumes",7000),viande("viandes",1800),poisson("poisson",2000);
    articlesAliments.push_back(riz);
    articlesAliments.push_back(oeuf);
    articlesAliments.push_back(legumes);
    articlesAliments.push_back(viande);
    articlesAliments.push_back(poisson);
}
void SectionAliment::enregistrerArticleAliment(){
    outfile.open("aliments.csv");
//D'abord on teste si l'ouverture du fichier en mode écriture s'est bien passé ou non
    if(outfile){
    outfile<<afficherArticleALiments();
    }
    else 
        cout<<"Erreur d'ouverture du fichier..."<<endl;;
    outfile.close();
}
void SectionAliment::voirSectionALiment(){
//On va récupérer ligne par ligne les données dans 
    string ligne;
//D'abord on teste si l'ouverture du fichier en mode lecture s'est bien passé ou non
    infile.open("aliments.csv");
    if(infile){
        while(getline(infile,ligne)){
                cout<<ligne<<endl;
        }
    }
    else
        cout<<"Ouverture du fichier impossible..."<<endl;
    infile.close();
}
void SectionAliment::acheterAliment(int num){
//On ajoute aux tableau achete chaque produit alimentaire acheté 
    cout<<articlesAliments[num].getNomArticle()+" achete"<<endl;
    achetes.push_back(articlesAliments[num]);
    cout<<endl<<endl;
}
void SectionAliment::enregistrerAlimentAchete(){
//cette méthode est utilisée afin d'enregistrer les aliments achetés dans le fichier csv ci-dessous
    outfile.open("aliments_achetés.csv",ios::app);
    for(int compteur=0,longueur=achetes.size();compteur<longueur;compteur++){
                if(outfile)
                    outfile<<achetes[compteur].getInfoArticle();
                else
                    cout<<"erreur d'ouverture du fichier"<<endl;
    }
    outfile.close();
}
float SectionAliment::calculerCoutAliments(){
//cette méthode sert à calculer le coût total des aliments achetés
    float total(0.0);
    for(int compteur=0,longueur=achetes.size();compteur<longueur;compteur++){
            total+=achetes[compteur].getPrixArticle();
    }
    return total;
}
string SectionAliment::afficherArticleALiments(){
//on se sert de cette méthode lorsque l'on veut afficher un aliment
string result("");
    for(int compteur=0,longueur=articlesAliments.size();compteur<longueur;compteur++){
        result+="Nom de l'article:"+articlesAliments[compteur].getNomArticle();
        result+="\t\tprix:"+to_string(articlesAliments[compteur].getPrixArticle())+" Ariary";
        result+="\t\tnumero d'enregistrement:"+to_string(articlesAliments[compteur].getNumeroArticle());
        result+='\n';
    }
    return result;
}
 