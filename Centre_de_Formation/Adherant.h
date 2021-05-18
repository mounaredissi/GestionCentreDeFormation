#pragma once
#include<string>
#include<iostream>
#include "Date.h"
using namespace std;


class Adherant
{

protected:
    string nom;
    int cinn;
    int numTel;
    string email;
public:
    Adherant(string = "", int = 0, int = 0, string = "");
      ~Adherant(void);


    void operator=(const Adherant&);
    virtual void saisirAdherant();
    virtual void afficherAdherant();


};

