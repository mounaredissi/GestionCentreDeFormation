#include <iostream>
#include <vector>
#include<map>
#include "Centre.h"
#include "tableau.h"
using namespace std;
void afficherChoixAdherent() {
	cout << "entrer votre choix" << endl;
	cout << "1- Formateur" << endl;
	cout << "2- Client" << endl;
	cout << "3- Afficher Reservation" << endl;
	cout << "4-Afficher depenses" << endl;
	cout << "5- Quitter" << endl;
	cout << "              " << endl;
}
void afficherChoixFormateur() {
	cout << "entrer votre choix" << endl;
	cout << "1- Reserver " << endl;
	cout << "2- Modifier la reservation" << endl;
	cout << "3- Annuler la reservation" << endl;
	cout << "              " << endl;
}
void saisirFormateurReservation(Date& d, Temps& t, int& duree)
{
	int a, m, j;
	int h, min, d1;
	cout << "entrer la date de reservation" << endl;
	cin >> j;
	cin >> m;
	cin >> a;
	cout << "entrer l'heure de la formation" << endl;
	cin >> h;
	cin >> min;
	cout << "entrer la duree" << endl;
	cin >> d1;
	d = Date(j, m, a);
	t = Temps(h, min);
	duree = d1;
}
void ReAffiche(int& rep) {
	cout << "veuillez vous entrez une autre date " << endl;
	cout << "1- OUI" << endl;
	cout << "2- NON" << endl;
	cin >> rep;
}



int main()
{
	int choixAdherant, nb;
	Centre C;
	Salle s;
	fstream fiche;
	string pseudo, mot_de_passe;
	map<string, string>m;
	map<string, string>::iterator it;
	bool trouv;
	m["Nesrine"] = "n1920";
	m["Ezer"] = "e1999";
	m["Mouna"] = "m1999";


	while (1)
	{
		trouv = false;
		cout << "entrez votre pseudo" << endl;
		cin >> pseudo;
		cout << "entrez votre mot de passe" << endl;
		cin >> mot_de_passe;

		for (it = m.begin(); it != m.end(); it++)
		{
			if ((it->first == pseudo) && (it->second == mot_de_passe))
			{
				trouv = true;

			}

		}
		if (trouv == true) break;
		cout << "verifier le pseudo et le mot de passe" << endl;

	}
	cout << "BIENVENUE" << endl;
	C.creer(fiche);

	cout << "Donnez les informations de la salle " << endl;
	cin >> C;
	fiche << C;

	cout << "Les Salles sont :" << endl;
	C.afficherSalles();
	cout << " " << endl;




	do {

		int  choixFormateur, du, choixMateriel, nombreJour, reponse, j, choixM, quantiteDemandee, choixClient, nbre;
		Reservation reservation;
		vector <Date> auxDateDebut;
		vector <Temps> auxTempsDebut;
		vector <Temps> auxTempsFin;
		vector<ServiceReservation*> auxService;
		vector <int> auxDuree;
		vector <int> auxCapacite;

		vector <int>indiceSalles;
		vector <int>indiceMat;

		Formation f;
		Date d;
		Temps t;
		Client cl;
		bool test = true;
		vector<Formation> FORMATIONS;
		Formateur F;
		vector <Reservation> RESERVATIONS;
		
		int i, choice;
		string nv_nomF, nv_niveau;
		float nv_prix,somprix=0;
		vector<Formation> Form;
		Reservation r;
		afficherChoixAdherent();

		cout << "    " << endl;
		cin >> choixAdherant;
		cout << " " << endl;
		try
		{
			if (choixAdherant > 5) throw - 1;
		}
		catch (int e)
		{
			cout << "choix invalide,veuillez retaper votre choix" << endl;
		}
		switch (choixAdherant)
		{
		case 1:
			afficherChoixFormateur();
			cout << "     " << endl;
			cin >> choixFormateur;
			cout << " " << endl;
			try
			{
				if (choixFormateur> 4) throw - 1;
			}
			catch (int e)
			{
				cout << "choix invalide, veuillez retaper votre choix" << endl;
			}
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
					indiceSalles.push_back(j);
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
						indiceMat.push_back(choixM);

					} while (choixM != 3);

					auxDateDebut.push_back(d);
					auxTempsDebut.push_back(t);
					auxTempsFin.push_back(t + du);
					auxDuree.push_back(du);
					auxCapacite.push_back(C.getSalles()[j].getCapacite());

				}


				if (test == false) { break; }
				f.saisirFormation();
				f.updateDate(auxDateDebut, auxTempsDebut, auxTempsFin, auxCapacite);
				reservation.ajoutService(auxService);
				reservation.ajouterIndiceSalle(indiceSalles);

				reservation.ajouterIndiceMat(indiceMat);
				reservation.ajouterFormation(f, C.getSizeReservation());
				C.ajouterReservation(reservation);
				C.updateformations(f);

				cout << "     " << endl;
				break;


			case 2:

				

				cout << "donner le numero de la formation a modifier";
				cin >> i;


				cout << "1-modifier nom de la formation :" << endl;
				cout << "2-modifier niveau de la formation :" << endl;
				cout << "3-modifier le prix de la formation" << endl;
				cout << "4-modifier les informations d'un formateur" << endl;
				cin >> choice;
				try
				{
					if (choice > 4) throw - 1;
				}
				catch (int e)
				{
					cout << "choix invalide,veuillez retaper votre choix" << endl;
				}
				switch (choice)
				{

				case 1:	cout << "nv_nomF" << endl;
					cin >> nv_nomF;
					r = C.getReservation()[i];

					f = (r.getFormation());
					f.setNomF(nv_nomF);
					//f.afficherFormation();
					r.setformation(f);
					//r.afficherReservation();
					C.setReservation(r, i);
					break;

				case 2: cout << "nv_niveau" << endl;
					cin >> nv_niveau;
					r = C.getReservation()[i];

					f = (r.getFormation());
					f.setNiveau(nv_niveau);
					//f.afficherFormation();
					r.setformation(f);
					//r.afficherReservation();
					C.setReservation(r, i);
					break;

				case 3: cout << "nv_prix" << endl;
					cin >> nv_prix;
					r = C.getReservation()[i];
					f = (r.getFormation());
					f.setPrix(nv_prix = 0.0);
					//f.afficherFormation();
					r.setformation(f);
					//r.afficherReservation();
					C.setReservation(r, i);
					break;
				case 4:  //C.formations[i].setFormateur(F);
					r = C.getReservation()[i];

					f = (r.getFormation());
					f.setFormateur(F);
					//f.afficherFormation();
					r.setformation(f);
					//r.afficherReservation();
					C.setReservation(r, i);
					break;


				}

				break;
			case 3:
				C.supprimerReservation();
				break;


			default:
				break;
			}
		case 77 : 
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
		case 88 : 
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
			//C.afficherFormations();
			
			break;

		case 888 : 
			break; 
		case 4:
			for (int i = 0; i < C.getSizeFormation(); i++)
			{
				float s = 0.0;
				tableau<float>t;
				t.ajouter(C.getFormation()[i].prix);
				//t.affichertemp();
				s = t.somme();
				somprix = somprix + s;
			}
			cout << "la somme est:" << endl;
			cout << somprix << endl;
			float revenu=0, depense=0,gainCentre;

			revenu = somprix * 30 / 100;
			cout << "entrer la depenses du centre" << endl;
			cin >> depense;
			cout << endl;
			gainCentre = revenu - depense;
			cout << "le gain du centre est"<<gainCentre << endl;
			if (gainCentre < depense)
				cout << "deficit" << endl;
			else
				cout << "succes" << endl;

		}
		
	} while (choixAdherant != 5);
	return 0;



}