#include"dicoSet.h"
#include"mesureDeSimilarite.h"

dicoSet::dicoSet()
{

    std::string const nomFichier("dictionnaire.txt");
    std::ifstream m_fluxDico(nomFichier.c_str());
    m_setDico =dictionnaireToSet(m_fluxDico);

}

bool dicoSet::chercherMotDictionnaire(std::string motCherchee) const
{

    std::string mot=changerMotEnMiniscule(motCherchee);
    bool existe=false;
    std::set<std::string>::iterator it;
    it=m_setDico.begin();
    while(it !=m_setDico.end() && existe==false)
    {
        if (mot == *it)
        {
            existe=true;
        }
        it++;
    }
    return existe;
}

std::set<std::string> dicoSet::dictionnaireToSet(std::ifstream &dico) const
{
    std::set<std::string> T;
    std::string ligne;

    while(getline(dico,ligne))
    {
        T.insert(ligne);
    }
    return T;
}


std::vector<std::string> dicoSet::choixNMotsPlusSimilaires(std::string mot, mesureDeSimilarite &typeDeCalcul, int nombreMots) const
{
    std::set< std::pair<int,std::string> > vp;
    std::set<std::string>::iterator it;

    for (it=m_setDico.begin();it !=m_setDico.end();it++)
    {
        vp.insert(make_pair(typeDeCalcul.calculSimilarite(mot,*it),*it));
    }

    std::vector<std::string> T;

    std::set< std::pair<int,std::string> >::iterator it1;
    it1=vp.begin();
    it=m_setDico.begin();
    for(int i=0;i<nombreMots;i++)
    {
        T.push_back(it1->second);
        it1++;
    }
    return T;
}

