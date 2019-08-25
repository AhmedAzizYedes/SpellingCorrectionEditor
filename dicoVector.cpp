#include"dicoVector.h"
#include"mesureDeSimilarite.h"

dicoVector::dicoVector()
{

    std::string const nomFichier("dictionnaire.txt");
    std::ifstream m_fluxDico(nomFichier.c_str());
    m_vectDico=dictionnaireToVector(m_fluxDico);

}

bool dicoVector::chercherMotDictionnaire(std::string motCherchee) const
{

    std::string mot=changerMotEnMiniscule(motCherchee);
    bool existe=false;
    int i=0,n=m_vectDico.size();
    while(i<n && existe==false)
    {
        if (mot == m_vectDico[i])
        {
            existe=true;
        }
        i++;
    }
    return existe;
}

std::vector<std::string> dicoVector::dictionnaireToVector(std::ifstream &dico) const
{
    std::vector<std::string> T;
    std::string ligne;

    while(getline(dico,ligne))
    {
        T.push_back(ligne);
    }
    return T;
}

std::vector<int> dicoVector::calculDistanceMotDictionnaire(std::string mot, mesureDeSimilarite &typeDeCalcul) const
{
    std::vector<int> T;
    for (int i=0;i<m_vectDico.size();i++)
    {
        T.push_back(typeDeCalcul.calculSimilarite(mot,m_vectDico[i]));
    }
    return T;
}


std::vector<std::string> dicoVector::choixNMotsPlusSimilaires(std::string mot, mesureDeSimilarite &typeDeCalcul, int nombreMots) const
{
    //std::vector< std::pair<int,std::string> > vp;
    std::vector<MotCandidat> vectMotCandidat;
    std::vector<int> tableauDistance;
    tableauDistance = this->calculDistanceMotDictionnaire(mot,typeDeCalcul);
    for (int i=0;i<m_vectDico.size();i++)
    {
        //vp.push_back(make_pair(tableauDistance[i],m_vectDico[i]));
        vectMotCandidat.push_back(MotCandidat(tableauDistance[i],m_vectDico[i]));
    }

    //sort(vp.begin(),vp.end());
    sort(vectMotCandidat.begin(),vectMotCandidat.end());
    std::vector<std::string> T;
    for(int i=0;i<nombreMots;i++)
    {
        //T.push_back(vp[i].second);
        T.push_back(vectMotCandidat[i].getMot());
    }
    return T;
}

