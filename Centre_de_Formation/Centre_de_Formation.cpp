#include <iostream>
#include <vector>
#include "Centre.h"
using namespace std; 
void afficherChoixAdherent() {
	cout << "entrer votre choix" << endl;
	cout << "1- Formateur" << endl;
	cout << "2- Client" << endl;
	cout << "3- Afficher Reservation" << endl;
	cout << "4- Quitter" << endl;
	cout << "              " << endl;
}
void afficherChoixFormateur() {
	cout << "entrer votre choix" << endl;
	cout << "1- Reserver " << endl;
	cout << "2- Modifier la reservation" << endl;
	cout << "3- Annuler la reservation" << endl;
	cout << "              " << endl;
}
void saisirFormateurReservation(Date& d , Temps &t , int& duree)
{
	int a, m, j; 
	int h, min,d1;
	cout << "entrer la date de reservation" << endl; 
	cin >> j;
	cin >> m;
	cin >> a;
	cout << "entrer l'heure de la formation" << endl;
	cin >> h; 
	cin >> min; 
	cout << "entrer la duree" << endl;
	cin >> d1; 
	d = Date(j,m,a); 
	t = Temps(h,min);
	duree = d1;
}
void ReAffiche( int &rep) {
	cout << "veuillez vous entrez une autre date " << endl;
	cout << "1- OUI" << endl; 
	cout << "2- NON" << endl;
	cin >> rep; 
}



int main()
{
	int choixAdherant;
	Centre C;
	do {

		int  choixFormateur, du, choixMateriel, nombreJour, reponse, j, choixM, quantiteDemandee, choixClient,nbre;
		Reservation reservation;
		vector <Date> auxDateDebut;
		vector <Temps> auxTempsDebut;
		vector <Temps> auxTempsFin;
		vector<ServiceReservation*> auxService;
		vector <int> auxDuree;
		vector <int> auxCapacite;
		Formation f;
		Date d;
		Temps t;
		Client cl;
		bool test = true;

		afficherChoixAdherent();

		cout << "    " << endl; 
		cin >> choixAdherant;
		cout << " " << endl;
		switch (choixAdherant)
		{
		case 1:
			afficherChoixFormateur();
			cout << "     " << endl;
			cin >> choixFormateur;
			cout << " " << endl;
			switch (choixFormateur)
			{
			case 1:
				cout << "Taper le nombre de jour de la formation" << endl;
				cin >> nombreJour;

				for (int i = 0; i < nombreJour; i++)
				{
					
					saisirFormateurReservation(d, t, du);
					j = C.RechercheSalle(d, t, du);



					if (C.RechercheSalle(d, t, du) == -1)
					{
						ReAffiche(reponse);
						if (reponse == 1)
						{

							while (j == -1)
							{
								
								saisirFormateurReservation(d, t, du);
								j = C.RechercheSalle(d, t, du);
							}
						}
						else
						{
							test = false;
							break;
						}
					}


					C.updateDisponibiliteSalle(j, d, t, du);
					auxService.push_back(new Salle(C.getSalles()[j]));

					C.afficherMateriels();

					do {
						cout << "entrer votre choix de materiels" << endl;
						cin >> choixM;

						while (C.getMateriels().size() < choixM)
						{
							cout << "choix invalide retaper votre choix" << endl;
							cin >> choixM;
						}

						if (choixM == 3) {
							break;
						}

						cout << "entrer quantite" << endl;
						cin >> quantiteDemandee;


						Materiels* m = new Materiels(C.getMateriels()[choixM].getNom(), quantiteDemandee);

						auxService.push_back(m);
						C.updateDisponibiliteMateriel(choixM, d, t, du);


					} while (choixM != 3);

					auxDateDebut.push_back(d);
					auxTempsDebut.push_back(t);
					auxTempsFin.push_back(t + du);
					auxDuree.push_back(du);
					auxCapacite.push_back(C.getSalles()[j].getCapacite());

				}


				if (test == false) { break; }
				f.saisirFormation();
				f.updateDate(auxDateDebut, auxTempsDebut, auxTempsFin,auxCapacite);
				reservation.ajoutService(auxService);
				reservation.ajouterFormation(f, C.getSizeReservation());
				C.ajouterReservation(reservation);
				C.updateformations(f);

				cout << "     " << endl; 
				break;


			case 2:
				


				break;
			case 3:


				break;


			default:
				break;
			}

		case 9: 
			break; 
		
		case 2:
			
			if (C.getSizeReservation() != 0) {
				cl.saisirClient();
				//cl.afficherClient();
				cout << "les formations sont" << endl;
				C.afficherFormations();


				cout << C.getSizeFormation() << "- quitter " << endl;

				cout << "Entrer le nombre de formation desiree " << endl;
				cin >> nbre;
				for (int i = 0; i < nbre; i++)
				{

					cout << "entrer votre choix de formation" << endl;
					cin >> choixClient;
					if (choixClient == C.getSizeFormation())
					{
						break;
					}
					while (C.getSizeFormation() < choixClient)
					{
						cout << "choix invalide retaper votre choix" << endl;
						cin >> choixClient;
					}


					if (choixClient == C.getSizeFormation())
					{
						break;
					}
					C.ajouterClients(choixClient, cl);
					C.updateClientReservation(cl, choixClient);

					cout << "     " << endl;
					//C.getFormation()[choixClient].updateClient(cl);
					//cout << C.getFormation().size();
					//C.getFormation()[choixClient].afficherClients();
					//C.afficherFormation(choixClient);


				}
			}
			else {
				cout << "aucune reservation disponible" << endl;
				cout << " " << endl;
			}

			break;
	
		case 3:
			if (C.getSizeReservation() != 0)
			{
				cout << "Les reservations :" << endl;
				C.afficherReservation();
				cout << " " << endl;
			}
			else {
				cout << "aucune reservation disponible" << endl; 
				cout << " " << endl;
			}
			
			break;
		default:
			break;
		}


	} while (choixAdherant != 4);
		return 0;
	


}