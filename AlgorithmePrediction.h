#ifndef ALGORITHMEPREDICTION_H_INCLUDED
#define ALGORITHMEPREDICTION_H_INCLUDED

#include <fstream>
#include<vector>
#include<deque>
#include<map>
#include<list>
#include<algorithm>

using namespace std;

class AlgorithmePrediction
{
    public:
        virtual void SaisiePredictive() =0;
        void loadMotsCorreles(vector<string> &tableau);
        virtual string ListeProposition(string mot, map<string,deque<string> > &tab)=0;
        virtual void ajoutMotsCorreles(map<string,deque<string> > &TabCorrel)=0;

};

class SaisiePredictive1: public AlgorithmePrediction
{
    public:

    deque<string> Partitionner(string &chaine, char delimiteur);
    string Rassembler(deque<string> tab);
    void SaisiePredictive();
    void loadMotsCorreles(vector<string> &tableau);
    map<string,deque<string> > TabCorrelation(vector<string> &tableau);
    string ListeProposition(string mot, map<string,deque<string> > &tab);
    void ajoutMotsCorreles(map<string,deque<string> > &TabCorrel);


};

class SaisiePredictive2 : public AlgorithmePrediction
{

};


#endif // ALGORITHMEPREDICTION_H_INCLUDED
