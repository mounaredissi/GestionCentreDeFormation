#pragma once
#include "Reservation.h"
#include<vector>
#include "Salle.h"
#include "Materiels.h"
#include <string>
using namespace std; 
class Centre
{
private:
	vector<Reservation> reservation;
	vector<Salle> salles;
	vector<Materiels> materiels;
	vector <Formation> formations;



public:
	
	Centre();
	~Centre();
	void afficheSalleDisponibles(Date, Temps);

	vector<Salle> getSalles(); 
	vector<Materiels> getMateriels();

	int RechercheSalle(Date& d, Temps& t, int &duree ); 
	
	void updateDisponibiliteSalle(int, Date, Temps, int);

	void updateDisponibiliteMateriel(int, Date, Temps, int);

	void afficherMateriels();

	void ajouterReservation(Reservation& r );

	int getSizeReservation();


	void afficherReservation();

	void updateformations(Formation& f );

	void afficherFormations();
	int getSizeFormation();
	vector<Formation> getFormation();
	void afficherFormation(int );
	void ajouterClients(int, Client&);

	void updateClientReservation(Client , int); 

};
