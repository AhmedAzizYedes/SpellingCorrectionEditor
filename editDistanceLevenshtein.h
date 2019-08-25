#ifndef EDITDISTANCELEVENSHTEIN_H_INCLUDED
#define EDITDISTANCELEVENSHTEIN_H_INCLUDED
#include"mesureDeSimilarite.h"

class editDistanceLevenshtein : public mesureDeSimilarite
{
public:
    virtual int calculSimilarite(const std::string& s1, const std::string& s2) const;
};

#endif // EDITDISTANCELEVENSHTEIN_H_INCLUDED
