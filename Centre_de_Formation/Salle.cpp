#include "Salle.h"

Salle::Salle(int c, int num):capSalle(c),numSalle(num)
{
}

int Salle::getCapacite()
{
	return capSalle;
}

Salle::~Salle(void)
{
}

void Salle::afficher()
{
	cout << "salle " << numSalle << " de capacite = " << capSalle << endl; 
}
