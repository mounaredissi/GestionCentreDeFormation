#include "Disponibilite.h"

Disponibilite::Disponibilite(Date d , Temps t,int c)
{
	date = d; 
	temps = t; 
	duree = c;

}

Disponibilite::~Disponibilite(void)
{
}

Date Disponibilite::getDate()
{
	return date;
}

Temps Disponibilite::getTemps()
{
	return temps;
}

int Disponibilite::getDuree()
{
	return (duree);
}

void Disponibilite::afficherDispo()
{
	date.afficher();
	temps.afficheTemps();
	cout << "    " << endl;
	cout << "___________________La duree est : " << duree << endl;
	cout << "    " << endl;
}
