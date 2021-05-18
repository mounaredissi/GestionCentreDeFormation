#pragma once
#include "Adherant.h"
class Formateur :public Adherant
{
protected:
    string profession;
public:
    ~Formateur(void);
    Formateur(string = "", int = 0, int = 0, string = "", string = "");
    void operator=(const Formateur&);
    void saisirFormateur();
    void afficherFormateur();

};


