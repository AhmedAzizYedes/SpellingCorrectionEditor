#include"motCandidat.h"

MotCandidat::MotCandidat(int distance,std::string mot)
{
    m_motCandidat=mot;
    m_distanceMot=distance;
}

int MotCandidat::getDistance()
{
    return m_distanceMot;
}

std::string MotCandidat::getMot()
{
    return m_motCandidat;
}

void MotCandidat::setDistance(int distance)
{
    m_distanceMot=distance;
}

void MotCandidat::setMot(std::string mot)
{
    m_motCandidat=mot;
}

bool MotCandidat::estPlusPetitQue(MotCandidat &b)
{
    return(this->getDistance() < b.getDistance());
}

bool operator <(MotCandidat m1, MotCandidat m2)
{
    return m1.estPlusPetitQue(m2);
}
