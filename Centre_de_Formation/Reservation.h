#pragma once
#include "Formation.h"
#include "ServiceReservation.h"
#include "Salle.h"
class Reservation
{
protected:
	int numRes;
	vector <ServiceReservation*> service;
	Formation formation;
	vector <int> indiceSalles;
	vector <int> indiceMateriel;

public:

	Reservation(int = 0);
	Reservation(int, Formation);
	~Reservation();
	void ajoutService(vector<ServiceReservation*>);
	void afficherService();
	void ajouterFormation(Formation f, int);
	void updateClient(Client);
	void afficherReservation();
	void ajouterIndiceSalle(vector <int>);
	void ajouterIndiceMat(vector <int>);
	vector<int>getIndiceSalles();
	vector<int>getIndiceMat();
	Formation& getFormation();
	void setformation(Formation f)
	{
		formation = f;
	}

};