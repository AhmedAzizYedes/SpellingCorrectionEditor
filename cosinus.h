#ifndef COSINUS_H_INCLUDED
#define COSINUS_H_INCLUDED
#include"mesureDeSimilarite.h"


class cosinus : public mesureDeSimilarite
{
    virtual int calculSimilarite(const std::string& s1, const std::string& s2) const;
};


#endif // COSINUS_H_INCLUDED
