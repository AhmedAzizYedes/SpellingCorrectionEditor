#ifndef DICTIONNAIRE_H_INCLUDED
#define DICTIONNAIRE_H_INCLUDED

#include<string>
#include<vector>
#include<fstream>
#include <iostream>
#include <algorithm>
#include"mesureDeSimilarite.h"
#include"fonctions.h"
#include"motCandidat.h"
class dictionnaire
{
public:
    virtual bool chercherMotDictionnaire(std::string motCherchee) const=0;
    void ajouterMotAuDictionnaire(std::string motAjoutee);
    virtual std::vector<std::string> choixNMotsPlusSimilaires(std::string mot, mesureDeSimilarite &typeDeCalcul, int nombreMots) const=0;
    int calculeErrorDansUnePhrase(std::string phrase);
};


#endif // DICTIONNAIRE_H_INCLUDED
