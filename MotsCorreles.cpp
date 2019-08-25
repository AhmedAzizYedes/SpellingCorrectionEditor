#include <iostream>
#include <fstream>
#include<map>
#include<deque>
#include<vector>
#include<list>
#include<algorithm>
#include<istream>
#include <sstream>
#include"AlgorithmePrediction.h"


using namespace std;


void SaisiePredictive1::loadMotsCorreles(vector<string> &tableau)
{
     string mon_fichier = "MotsCorreles.txt";  // je stocke dans la chaîne mon_fichier le nom du fichier à ouvrir
     ifstream fichier(mon_fichier.c_str(), ios::in);
     if(fichier)  // si l'ouverture a réussi
     {
          // instructions
          //cout <<"Bébut chargement du dictionnaire" <<endl;
        string ligne;
        while(getline(fichier, ligne))  // tant que l'on peut mettre la ligne dans "contenu"
        {
                tableau.push_back(ligne);  // on l'affiche
        }
        fichier.close();
     }
     else
            {cerr << "Erreur à l'ouverture !" << endl;}
    return;

}

map<string,deque<string> > SaisiePredictive1::TabCorrelation(vector<string> &tableau)
{
    loadMotsCorreles(tableau);
    map<string, deque<string> > tab;
    deque<string> l;
    string n;
    int p=tableau.size();
    p=p-1;
    for (int i=0;i<p;i++)
    {
        l=Partitionner(tableau[i],' ');
        n=l[0];
        //l.pop_front();
        tab[n]=l;
    }
    return(tab);
}

string SaisiePredictive1::ListeProposition(string mot, map<string,deque<string> > &tab)
{

    map<string,deque<string> >::iterator it;
    it=tab.find(mot);
    deque<string> p;
    if (it==tab.end() || (it!=tab.end() && (it->second).size()==1)) { //cas ou le mot n'existe pas dans la base de donnée des mots correlés

            cout <<"Nous nous excusons de ne pas pouvoir prévoir le mot suivant" << '\n' <<
        "Le mot que vous allez taper va être ajouté à notre base de donnée"<<endl;
    string mot2;
    cin >> mot2;
        if (mot2!="*")
            {
    deque<string> liste(1,mot);
    liste.push_back(mot2);
    tab[mot]=liste;
    ajoutMotsCorreles(tab);

            }
            return(mot2);
        }

    else {      //cas ou il y a des propositions pour le mot qui suit dans la BD
    p=it->second;

    cout << "Nous avons" << p.size() << " propositions pour le mot suivant" <<endl;
    for (int m=1; m<p.size();m++) { cout << m << " : " << p[m] << "  **  " ;}
    cout << "Taper le numéro du mot correct s'il existe sinon taper -1" << endl;
    int q;
    cin >> q;
    if (q==-1) { // cas ou le mot en tete ne figure pas parmi les propositions
        cout << "Reprenez la saisie" <<endl;
            string mot2;
    cin >> mot2;
        if (mot2!="*")
            {
    p.push_back(mot2);
    tab[mot]=p;
    ajoutMotsCorreles(tab);
    //cout << mot << " " << mot2 <<endl;
    cout <<"Ce mot a été ajouté à notre base de donnée" << endl;
                }
                 return(mot2);
              }
    else {      //cas ou le mot en tete est dans la liste des propositions
            //cout << mot << " " << p[q] <<endl;
            return(p[q]); }
    }
}

