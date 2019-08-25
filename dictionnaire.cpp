#include"dictionnaire.h"
#include"mesureDeSimilarite.h"

void dictionnaire::ajouterMotAuDictionnaire(std::string motAjoutee)
{
    std::ofstream monFlux;
    monFlux.open("dictionnaire.txt",std::ios::app);
    monFlux << motAjoutee<<std::endl;
    monFlux.close();
}

int dictionnaire::calculeErrorDansUnePhrase(std::string phrase)
{
    std::vector<std::string> Tab_phrase=decomposerPhrase(phrase);
    int nb_erreur=0;
    for (int i=0;i<Tab_phrase.size();i++)
    {
        if(!this->chercherMotDictionnaire(Tab_phrase[i]))
        {
            nb_erreur++;
        }
    }
    return nb_erreur;
}




