#pragma once
#include "Formation.h"
#include "ServiceReservation.h"
#include "Salle.h"
class Reservation
{
protected: 
	int numRes; 
	vector <ServiceReservation *> service; 
	Formation formation;
	
public:
	
	Reservation(int=0);
	Reservation(int ,Formation); 
	~Reservation(); 
	 void ajoutService(vector<ServiceReservation*>);
	 void afficherService();
	 void ajouterFormation(Formation f , int  );
	 void updateClient(Client ); 
	 void afficherReservation();
};