#ifndef DICOSET_H_INCLUDED
#define DICOSET_H_INCLUDED

#include"dictionnaire.h"
#include<set>

class dicoSet : public dictionnaire
{
public:
    dicoSet();
    virtual bool chercherMotDictionnaire(std::string motCherchee) const;
    std::set<std::string> dictionnaireToSet(std::ifstream &dico) const;
    virtual std::vector<std::string> choixNMotsPlusSimilaires(std::string mot, mesureDeSimilarite &typeDeCalcul, int nombreMots) const;

private:

    std::set<std::string> m_setDico;
};
#endif // DICOSET_H_INCLUDED
