#include "ServiceReservation.h"




ServiceReservation::ServiceReservation(void)
{
}

ServiceReservation::~ServiceReservation(void)
{
}
vector<Disponibilite> ServiceReservation::getDisponibilite()
{
	return dispo;
}



bool ServiceReservation::rechercheDisponibilite(Date& d, Temps& t,int &c)
{


	bool test = true; 
	for (int i = 0; i < dispo.size(); i++)
	{
		if (dispo[i].getDate() == d)
		{
			if (!(dispo[i].getTemps() + dispo[i].getDuree() <= t) && !(dispo[i].getTemps() >= t + c))
			{

				test = false;
				break;

			}

		}
		else { test = true; }
		
	}


	if (dispo.size() == 0) {
		test = true; 
	}

	return test; 

}

void ServiceReservation::afficherDisponibilite()
{
	for (int i = 0; i < dispo.size(); i++)
	{
		dispo[i].afficherDispo();
	}
}

int ServiceReservation::rechercheDispoDate(Date d)
{
	return 0;
}
