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


deque<string> SaisiePredictive1::Partitionner(string &chaine, char delimiteur)
{
    // cette fonction sépare les mots composant une phrase et les stocke dans un conteneur de type deque<string>
    deque<string> tab;
    stringstream ss(chaine);
    string sousChaine;
 while (getline(ss, sousChaine, delimiteur))
 {
 tab.push_back(sousChaine);
 }
 return(tab);
}

string SaisiePredictive1::Rassembler(deque<string> tab)
{
    // cette fonction fait la concaténation de plusieurs chaines de caracteres stockées dans un
    // tableau avec des espaces séparant les mots
    string a;
    for (int i=0; i<tab.size()-1;i++)
    {
        a=a+(tab[i])+" ";
    };
    a=a+(tab[tab.size()-1]);
    return(a);
}

