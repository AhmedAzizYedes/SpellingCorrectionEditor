#ifndef DICOVECTOR_H_INCLUDED
#define DICOVECTOR_H_INCLUDED

#include"dictionnaire.h"

class dicoVector : public dictionnaire
{
public:
    dicoVector();
    virtual bool chercherMotDictionnaire(std::string motCherchee) const;
    std::vector<std::string> dictionnaireToVector(std::ifstream &dico) const;
    virtual std::vector<int> calculDistanceMotDictionnaire(std::string mot, mesureDeSimilarite &typeDeCalcul) const;
    virtual std::vector<std::string> choixNMotsPlusSimilaires(std::string mot, mesureDeSimilarite &typeDeCalcul, int nombreMots) const;

private:

    std::vector<std::string> m_vectDico;

};


#endif // DICOVECTOR_H_INCLUDED
