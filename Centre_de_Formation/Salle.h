#pragma once
#include "ServiceReservation.h"
class Salle :public ServiceReservation
{
protected:
    int capSalle;
    int numSalle; 
    
public:
    Salle(int = 0,int=0);
    
    int getCapacite(); 
    ~Salle(void);
    friend ostream& operator<<(ostream&, Salle&);
    friend istream& operator>>(istream&, Salle&);
    void afficher(); 
};

