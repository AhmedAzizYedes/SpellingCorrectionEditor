#include <fstream>
#include<vector>
#include<deque>
#include<map>
#include<algorithm>
#include<iostream>
#include "AlgorithmePrediction.h"


void SaisiePredictive1::SaisiePredictive()
{

    vector<string> liste;
    string mot;
    cout << "Commencez la saisie ( Lorsque vous terminez la saisie tapez * ) : " << endl;
    cin >> mot ;
    while (mot!="*") {
    liste.push_back(mot);
    vector<string> tableau;
    map<string,deque<string> > tab;
    loadMotsCorreles(tableau);
    tab=TabCorrelation(tableau);
    mot=ListeProposition(mot,tab);
    }
    for (int i=0; i<liste.size(); i++)
    {
        cout << liste[i] << " ";
    }
    return;


}
