#include "Centre.h"

Centre::Centre()
{


	/*salles.push_back(Salle(1,1));
	salles.push_back(Salle(90,2));
	salles.push_back(Salle(80,3));
	salles.push_back(Salle(70,4));*/

	materiels.push_back(Materiels("ecran"));
	materiels.push_back(Materiels("retorprojecteur"));
	materiels.push_back(Materiels("Pc"));

	/*salles[0].setDisponibilite(Disponibilite(Date(12, 12, 12), Temps(10, 0), 2));

	salles[1].setDisponibilite(Disponibilite(Date(12, 12, 12), Temps(10, 0), 2));
	salles[2].setDisponibilite(Disponibilite(Date(12, 12, 12), Temps(10, 0), 2));


	salles[3].setDisponibilite(Disponibilite(Date(12, 12, 12), Temps(10, 0), 2));
	//salles[0].setDisponibilite(Disponibilite(Date(1, 1, 1), Temps(1, 1), 1));


	salles[1].setDisponibilite(Disponibilite(Date(1, 1, 1), Temps(1, 1), 1));
	salles[2].setDisponibilite(Disponibilite(Date(1, 1, 1), Temps(1, 1), 1));
	salles[3].setDisponibilite(Disponibilite(Date(1, 1, 1), Temps(1, 1), 1));
	//cout << salles[0].rechercheDisponibilite(Date(12, 12, 12), Temps(8, 0), 2)<< endl; */




}
Centre::~Centre()
{
}
void Centre::supprimerReservation()
{
	int i;
	cout << "Donnez le num de la reservation a supprimer " << endl;
	cin >> i;

	for (int j = 0; j < reservation[i].getIndiceSalles().size(); j++) {
		salles[reservation[i].getIndiceSalles()[j]].supprimerDisponibilite(reservation[i].getFormation().getTempsFormation(), reservation[i].getFormation().getDateFormation());
	}
	for (int j = 0; j < reservation[i].getIndiceMat().size(); j++) {
		materiels[reservation[i].getIndiceMat()[j]].supprimerDisponibilite(reservation[i].getFormation().getTempsFormation(), reservation[i].getFormation().getDateFormation());
	}

	reservation.erase(reservation.begin() + i);

}

void Centre::afficheSalleDisponibles(Date, Temps)
{

}

vector<Salle> Centre::getSalles()
{
	return salles;
}

vector<Materiels> Centre::getMateriels()
{
	return materiels;
}
int Centre::RechercheSalle(Date& d, Temps& t, int& duree)
{
	int i, j = -1;
	for (i = 0; i < salles.size(); i++)
	{
		if (salles[i].rechercheDisponibilite(d, t, duree) == true)
		{
			return i;
			break;
		}

	}
	return -1;
}




void Centre::updateDisponibiliteSalle(int indice, Date d, Temps t, int dure)
{
	Disponibilite dispo(d, t, dure);
	salles[indice].setDisponibilite(dispo);
}

void Centre::updateDisponibiliteMateriel(int indice, Date d, Temps t, int dure)
{
	Disponibilite dispo(d, t, dure);
	materiels[indice].setDisponibilite(dispo);
}

void Centre::afficherMateriels()
{
	for (int i = 0; i < materiels.size(); i++)
	{
		cout << i << "- ";
		materiels[i].afficherSansQuantite();

	}
	cout << " 3- Quitter" << endl;
}

void Centre::ajouterReservation(Reservation& r)
{
	reservation.push_back(r);
}

int Centre::getSizeReservation()
{
	return reservation.size();
}

void Centre::afficherReservation()
{
	for (int i = 0; i < reservation.size(); i++)
	{
		reservation[i].afficherReservation();
	}
}

void Centre::updateformations(Formation& f)
{

	formations.push_back(f);

}

void Centre::afficherFormations()
{
	for (int i = 0; i < formations.size(); i++)
	{
		if (!formations[i].rechercheComplet())
		{
			cout << "la formation d'indice " << i << " est : " << endl;
			formations[i].afficherFormation();
			cout << "    " << endl;
		}
		else
		{
			cout << "formation d'indice " << i << "est complet" << endl;
			cout << "    " << endl;
		}

	}
	cout << "   " << endl;
}

int Centre::getSizeFormation()
{
	return formations.size();
}

vector<Formation> Centre::getFormation()
{
	return formations;
}

void Centre::afficherFormation(int indice)
{
	cout << formations[indice].getClient().size() << endl;
}

void Centre::ajouterClients(int n, Client& cl)
{
	formations[n].updateClient(cl);
}

void Centre::updateClientReservation(Client c, int i)
{
	reservation[i].updateClient(c);

	cout << "Client Ajoutee " << endl;
}

void Centre::afficherSalles()
{
	cout << *this;
}

istream& operator>>(istream& in, Centre& c)
{
	in.seekg(0);
	Salle s;
	char rep;
	do
	{
		in >> s;

		c.salles.push_back(s);
		cout << "rajouter ?" << endl;
		cin >> rep;
	} while (rep == 'o');
	return in;
}

ostream& operator<<(ostream& out, Centre& c)
{
	for (int i = 0; i < c.salles.size(); i++)
	{
		out << c.salles[i] << endl;

	}
	return out;
}

void Centre::creer(fstream& f)
{
	f.open("C:\\Users\\mouna\\FichierSalle", ios::in | ios::out | ios::trunc);
	if (!f.is_open()) exit(-1);
}
