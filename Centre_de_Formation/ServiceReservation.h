#pragma once
#include<string>
#include<iostream>
#include "Date.h"
#include "Temps.h"
#include "Disponibilite.h"
#include<vector>
using namespace std;
class ServiceReservation
{
protected:
    vector <Disponibilite> dispo;

public:
    ServiceReservation(void);
    ~ServiceReservation(void);
    vector<Disponibilite> getDisponibilite();
    bool rechercheDisponibilite(Date&, Temps&, int&);
    virtual void afficher() = 0;

    void setDisponibilite(Disponibilite d)
    {
        dispo.push_back(d);
    }

    void afficherDisponibilite();


    void supprimerDisponibilite(vector <Temps>, vector <Date>);


};

