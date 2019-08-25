#ifndef MOTCANDIDAT_H_INCLUDED
#define MOTCANDIDAT_H_INCLUDED
#include<iostream>
#include<string>
class MotCandidat
{
public:
    MotCandidat(int distance,std::string mot);
    void setDistance(int distance);
    void setMot(std::string mot);
    int getDistance();
    std::string getMot();
    bool estPlusPetitQue(MotCandidat &b);
private:
    std::string m_motCandidat;
    int m_distanceMot;
};

bool operator <(MotCandidat m1, MotCandidat m2);
#endif // MOTCANDIDAT_H_INCLUDED
