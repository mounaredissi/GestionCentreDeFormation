#include "Materiels.h"

Materiels::Materiels(string nom,int qt):nom_mat(nom),quantite(qt)
{

}

Materiels::~Materiels(void)
{
}

void Materiels::afficher()
{
	cout<<quantite<<"* " << nom_mat <<  endl; 
}

void Materiels::afficherSansQuantite()
{
	cout <<nom_mat<< endl;
}

string Materiels::getNom()
{
	return nom_mat;
}
