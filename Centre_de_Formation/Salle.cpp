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

ostream& operator<<(ostream& out, Salle& s)
{
	out << "salle " << s.numSalle << " de capacite = " << s.capSalle << endl;

	return out;
}

istream& operator>>(istream& in, Salle& s)
{
	cout << "taper numero de la salle" << endl;
	in >> s.numSalle;
	cout << "taper la capacite de la salle" << endl;
	in >> s.capSalle;
	return in;
}