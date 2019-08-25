#include"fonctions.h"

void correctionMot(std::string &motEronne, std::vector<std::string> const &tableProposition,int indiceMot)
{
    motEronne=tableProposition[indiceMot];
}

std::vector<std::string> decomposerPhrase (std::string phrase)
{
    std::vector<std::string> T;
    T.push_back("");
    int n=0;
    for(int j=0;j<phrase.size();j++)
    {
        if(phrase[j]==' ' || phrase[j]==',' || phrase[j]=='.' || phrase[j]=='\x27' || phrase[j]==':' || phrase[j]==';' || phrase[j]=='?' || phrase[j]=='!')
        {
            if((phrase[j]==' '))
            {
                T.push_back("");
                n++;
            }
            else if(phrase[j]==',')
            {
                T.push_back(",");
                n++;
            }
            else if (phrase[j]=='.')
            {
                T.push_back(".");
                n++;
            }
            else if (phrase[j]=='\'')
            {
                T.push_back("'");
                n++;
            }
            else if(phrase[j]==':')
            {
                T.push_back(":");
                n++;
            }
            else if(phrase[j]==';')
            {
                T.push_back(";");
                n++;
            }
            else if(phrase[j]=='?')
            {
                T.push_back("?");
                n++;
            }
            else if (phrase[j]=='!')
            {
                T.push_back("!");
                n++;
            }
        }
        else
        {

            if(phrase[j-1]==',' || phrase[j-1]=='.' || phrase[j-1]==':' || phrase[j-1]==';' || phrase[j-1]=='!' || phrase[j-1]=='\'')
            {
                T.push_back("");
                n++;
            }
            T[n]+=phrase[j];
        }
    }
    return T;
}

std::string changerMotEnMiniscule(std::string mot)
{
    std::string motMiniscule=mot;
    for (int i=0;i<mot.size();i++)
    {
        motMiniscule[i]=tolower(mot[i]);
    }
    return motMiniscule;
}


