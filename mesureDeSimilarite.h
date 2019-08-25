#ifndef MESUREDESIMILARITE_H_INCLUDED
#define MESUREDESIMILARITE_H_INCLUDED

#include<string>
#include<vector>
class mesureDeSimilarite
{
public:
    virtual int calculSimilarite(const std::string& s1, const std::string& s2) const=0 ;
};

#endif // MESUREDESIMILARITE_H_INCLUDED
