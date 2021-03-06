#include "Reservation.h"

Reservation::Reservation(int num) :numRes(num)
{

}

Reservation::Reservation(int num, Formation f) : numRes(num)
{
	formation = f;
}

Reservation::~Reservation()
{

	//for (int i =0; i<service.size();i++) { delete service[i]; }

}

void Reservation::ajoutService(vector<ServiceReservation*>aux)
{
	for (int i = 0; i < aux.size(); i++)
	{
		service.push_back(aux[i]);
	}
}

void Reservation::afficherService()
{
	for (int i = 0; i < service.size(); i++)
	{
		service[i]->afficher();
	}
}

void Reservation::ajouterFormation(Formation f, int i)
{
	formation = f;
	numRes = i;
}
void Reservation::updateClient(Client c)
{
	formation.updateClient(c);
}
void Reservation::afficherReservation()
{
	cout << "Information sur la reservation" << endl;
	cout << "le numero de la reservation est: " << numRes << endl;
	cout << "les services reserver:" << endl;
	afficherService();
	cout << "information sur la formation: " << endl;
	formation.afficherFormation();
}

void Reservation::ajouterIndiceSalle(vector<int> tab)
{
	for (int i = 0; i < tab.size(); i++) {
		indiceSalles.push_back(tab[i]);
	}
}

void Reservation::ajouterIndiceMat(vector<int> tab)
{
	for (int i = 0; i < tab.size(); i++) {
		indiceMateriel.push_back(tab[i]);
	}
}

vector<int> Reservation::getIndiceSalles()
{
	return indiceSalles;
}

vector<int> Reservation::getIndiceMat()
{
	return indiceMateriel;
}

Formation& Reservation::getFormation()
{
	return formation;
}

