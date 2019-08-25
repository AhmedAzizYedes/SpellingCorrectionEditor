#include <iostream>
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
#include<deque>
#include<map>
#include <sstream>
#include "AlgorithmePrediction.h"
#include"mesureDeSimilarite.h"
#include"dictionnaire.h"
#include"fonctions.h"
#include"dicoVector.h"
#include"editDistanceLevenshtein.h"
#include"dicoSet.h"
using namespace std;

int main()
{
    dicoSet dico;
    //dicoVector dico;
    editDistanceLevenshtein distance;

    cout<<"================================================================================================"<<endl;
    cout<<"       ********     *****      *******    ********    ********    *       *    ********         "<<endl;
    cout<<"       *            *     *       *          *        *           *       *    *       *        "<<endl;
    cout<<"       *            *      *      *          *        *           *       *    *       *        "<<endl;
    cout<<"       ********     *      *      *          *        ********    *       *    ********         "<<endl;
    cout<<"       *            *      *      *          *        *           *       *    *   *            "<<endl;
    cout<<"       *            *     *       *          *        *            *     *     *     *          "<<endl;
    cout<<"       ********     *****      *******       *        ********       ***       *       *        "<<endl;
    cout<<"================================================================================================"<<endl;
    cout<<endl;
    cout<<"================================================================================================"<<endl;
    cout<<"================================Bienvenu dans l'editeur de texte================================"<<endl;
    cout<<"================================================================================================"<<endl;
    cout<<"=========================================== MENU ==============================================="<<endl;
    cout<<"Choisissez le type d'edition: "<<endl;
    cout<<"1) Correcteur d'orthographe"<<endl;
    cout<<"2) Saisie predictive"<<endl;
    cout<<"3) Quitter"<<endl;
    cout<<"================================================================================================"<<endl;
    int mode;
    cin>>mode;
    cin.ignore();
    cout<<endl;
    cout<<endl;
    cout<<endl;
    cout<<endl;
    cout<<endl;
    cout<<endl;
    cout<<endl;
    while(mode != 1 && mode!=2 && mode!=3)
    {
        cout<<"Veuillez entrer un choix valide s'il vous plait"<<endl;
        cout<<"=========================================== MENU ==============================================="<<endl;
        cout<<"Choisissez le type d'edition: "<<endl;
        cout<<"1) Correcteur d'orthographe"<<endl;
        cout<<"2) Saisie predictive"<<endl;
        cout<<"3) Quitter"<<endl;
        cout<<"================================================================================================"<<endl;
        cin>> mode;
        cin.ignore();
        cout<<endl;
        cout<<endl;
        cout<<endl;
        cout<<endl;
        cout<<endl;
        cout<<endl;
        cout<<endl;
   }

    if(mode ==1)
    {
        int modeSaisie;
        cout<<"================================================================================================"<<endl;
        cout<<"=========================Bienvenu dans le menu correcteur d'orthographe========================="<<endl;
        cout<<"================================================================================================"<<endl;
        cout<<"=========================================== MODE ==============================================="<<endl;
        cout<<"Choisissez le mode de Saisie: "<<endl;
        cout<<"1) Saisie manuelle"<<endl;
        cout<<"2) Depuis un fichier texte"<<endl;
        cout<<"================================================================================================"<<endl;
        cin>>modeSaisie;
        cin.ignore();
        cout<<endl;
        cout<<endl;
        cout<<endl;
        cout<<endl;
        cout<<endl;
        cout<<endl;
        cout<<endl;
        while(modeSaisie !=1 && modeSaisie!=2)
        {
            cout<<"Veuillez entrer un choix valide s'il vous plait"<<endl;
            cout<<"=========================================== MODE ==============================================="<<endl;
            cout<<"Choisissez le mode de Saisie: "<<endl;
            cout<<"1) Saisie manuelle"<<endl;
            cout<<"2) Depuis un fichier texte"<<endl;
            cout<<"================================================================================================"<<endl;
            cin>>modeSaisie;
            cin.ignore();
            cout<<endl;
            cout<<endl;
            cout<<endl;
            cout<<endl;
            cout<<endl;
            cout<<endl;
            cout<<endl;
        }
        string phraseEntree;
        string pathFichier;
        if(modeSaisie == 1)
        {
            cout<< "Donner une phrase"<<endl;
            getline(cin,phraseEntree);
            cout<<endl;
            cout<<endl;
            cout<<endl;

        }
        else
        {
            cout<<"Donnez le path du fichier texte que vous souhaitez ouvir"<<endl;

            getline(cin,pathFichier);
            fstream fichier(pathFichier.c_str());
            cout<<endl;
            cout<<endl;
            cout<<endl;
            cout<<endl;
            if(fichier)
            {
                string ligne;
                while(getline(fichier,ligne))
                {
                    phraseEntree+=ligne+" ";
                }
                cout<<phraseEntree<<endl;
                cout<<endl;
                cout<<endl;
                cout<<endl;
                cout<<endl;
                cout<<endl;
                cout<<endl;
                cout<<endl;
            }
            else
            {
                cout<<"ERREUR: Fichier introuvable"<<endl;
                exit (EXIT_FAILURE);

            }
            fichier.close();
        }
        vector<string> phraseDecomposee = decomposerPhrase(phraseEntree);
        for(int i=0;i<phraseDecomposee.size();i++)
        {
            if(!dico.chercherMotDictionnaire(phraseDecomposee[i]))
            {
                cout << "le mot \" "<<phraseDecomposee[i]<<" \" n'existe pas dans le dictionnaire francais "<<endl;
                cout<<"Donner le nombre de propositions que vous souhaitez afficher : ";
                int nombre;
                cin>>nombre;
                cin.ignore();
                cout<<endl;
                cout << "Choisissez le mot correcte ou ajouter un nouveau mot au dictionnaire "<<endl;
                vector<string> tabPropositions=dico.choixNMotsPlusSimilaires(phraseDecomposee[i],distance,nombre);
                for(int i=0;i<nombre;i++)
                {
                    cout<<i+1<<") "<<tabPropositions[i]<<endl;
                }
                cout <<nombre+1<<") Ajouter le mot au dictionnaire | ";
                cout <<nombre+2<<")Ignorer"<<endl;
                cout<<"Donnez votre choix : "<<endl;
                int indice;
                cin>>indice;
                cin.ignore();
                if(indice==nombre+1)
                {
                    dico.ajouterMotAuDictionnaire(phraseDecomposee[i]);
                }
                else if (indice==nombre+2)
                {
                    true;
                }
                else
                {
                    correctionMot(phraseDecomposee[i],tabPropositions,indice-1);
                }
            }
            cout<<endl;
            cout<<endl;
            cout<<endl;
        }
        phraseEntree="";

        for (int i=0;i<phraseDecomposee.size();i++)
        {
            if(i==(phraseDecomposee.size()-1))
            {
                phraseEntree+=phraseDecomposee[i];
            }
            else
            {
                if(phraseDecomposee[i]=="'")
                {
                    phraseEntree+=phraseDecomposee[i];
                }
                else if (phraseDecomposee[i+1]=="'" || phraseDecomposee[i+1]=="," || phraseDecomposee[i+1]=="." || phraseDecomposee[i+1]==":" || phraseDecomposee[i+1]=="?" || phraseDecomposee[i+1]=="!" || phraseDecomposee[i+1]==";")
                {
                    phraseEntree+=phraseDecomposee[i];
                }
                else
                {
                    phraseEntree+=phraseDecomposee[i] + " ";
                }
            }
        }
        cout<<"Le texte corrige est : "<<endl;
        cout << phraseEntree;
        cout<<endl;
        cout<<endl;
        cout<<endl;
        cout<<endl;
        int enregistrer;
        cout<<"Voulez-vous enregistrer le texte ?"<<endl;
        cout<<"1) Oui"<<endl;
        cout<<"2) Non"<<endl;
        cin>>enregistrer;
        cin.ignore();
        while(enregistrer !=1 && enregistrer!=2)
        {
            cout<<"Veuillez entrer un choix valide"<<endl;
            cout<<"Voulez-vous enregistrer le texte ?"<<endl;
            cout<<"1) Oui"<<endl;
            cout<<"2) Non"<<endl;
            cin>>enregistrer;
            cin.ignore();
        }
        if(enregistrer==1)
        {
            if(modeSaisie==1)//saisie manuelle
            {
                string nom;
                cout<<"Choisissez le nom de fichier"<<endl;
                getline(cin,nom);
                ofstream file(nom.c_str());
                if(file)
                {
                    file<< phraseEntree;
                }
                else
                {
                    cout<<"Impossible d'ouvrir le fichier"<<endl;
                    exit(EXIT_FAILURE);
                }
                file.close();
            }
            else
            {
                ofstream file(pathFichier.c_str());
                if(file)
                {
                    file<< phraseEntree;
                }
                else
                {
                    cout<<"Impossible d'ouvrir le fichier"<<endl;
                    exit(EXIT_FAILURE);
                }
                file.close();

            }
        }
    }
    else if (mode==2)
    {
        SaisiePredictive1 Saisie;
        Saisie.SaisiePredictive();
    }

/*
    //calcule d erreur
    fstream fichier("test.txt");
    cout<<endl;
    string texte;
    if(fichier)
    {
        string ligne;
        while(getline(fichier,ligne))
        {
            texte+=ligne+" ";
        }
        cout<<texte<<endl;
        cout<<endl;
        cout<<endl;

    }
    else
    {
        cout<<"ERREUR: Fichier introuvable"<<endl;
        exit (EXIT_FAILURE);
    }

    cout<<endl;
    cout<<dico.calculeErrorDansUnePhrase(texte);

*/
    return 0;
}
