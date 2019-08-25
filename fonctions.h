#ifndef FONCTIONS_H_INCLUDED
#define FONCTIONS_H_INCLUDED

#include"dictionnaire.h"
#include"mesureDeSimilarite.h"

void correctionMot(std::string &motEronne, std::vector<std::string> const &tableProposition,int indiceMot);
std::vector<std::string> decomposerPhrase (std::string phrase);
std::string changerMotEnMiniscule(std::string mot);

#endif // FONCTIONS_H_INCLUDED
