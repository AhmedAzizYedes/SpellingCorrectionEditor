#ifndef JACCARDI_H_INCLUDED
#define JACCARDI_H_INCLUDED
#include"mesureDeSimilarite.h"

class jaccardi : public mesureDeSimilarite
{
    virtual int calculSimilarite(const std::string& s1, const std::string& s2) const;
};

#endif // JACCARDI_H_INCLUDED
