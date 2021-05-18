#pragma once
#include "ServiceReservation.h"
#include<string>
class Materiels :public ServiceReservation
{
protected:
    string nom_mat;
    int quantite; 
public:
    Materiels(string = "",int=0);
    ~Materiels(void);
    void afficher(); 
    void afficherSansQuantite();
    string getNom(); 
};

