#include <iostream>
#include <fstream>
#include<map>
#include<deque>
#include<vector>
#include<list>
#include<algorithm>
#include<istream>
#include <sstream>
#include "AlgorithmePrediction.h"

void SaisiePredictive1::ajoutMotsCorreles (map<string,deque<string> > &TabCorrel)
{
        ofstream fichier("MotsCorreles.txt", ios::out | ios::ate);  //déclaration du flux et ouverture du fichier
        if(fichier)  // si l'ouverture a réussi
        {
             deque<string> liste2;
             string a;
             for (map<string,deque<string> >::iterator d=TabCorrel.begin(); d!=TabCorrel.end(); ++d)
             {
             liste2=d->second;
             a=Rassembler(liste2);
             fichier<< a <<'\n'; }
            // instructions
                fichier.close();  // on referme le fichier
         }
        else  // sinon
                cerr << "Erreur à l'ouverture !" << endl;
                return;

}
