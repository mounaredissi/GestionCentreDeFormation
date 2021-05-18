#pragma once
#include<iostream>
using namespace std; 


class Date
{
protected:
    int jour;
    int mois;
    int annee;
public:
    Date(int = 0, int = 0, int = 0);
    ~Date(void);
    void afficher();
    void saisirdate();
    void operator=(const Date&);
    bool operator== (const Date&);
};



