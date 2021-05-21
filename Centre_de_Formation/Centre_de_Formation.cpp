#include <iostream>
#include <vector>
#include<map>
#include "Centre.h"
#include "tableau.h"
using namespace std;
void afficherChoixAdherent() {

	cout << "___________________Entrez votre choix :" << endl;
	cout << "   " << endl;
	cout << "----------     1- Formateur             ----------" << endl;
	cout << "----------     2- Client                ----------" << endl;
	cout << "----------     3- Afficher Reservation  ----------" << endl;
	cout << "----------     4-Afficher depenses      ----------" << endl;
	cout << "----------     5- Quitter               ----------" << endl;
	cout << "              " << endl;

}
void afficherChoixFormateur() {
	system("cls");

	cout << "___________________Entrez votre choix : " << endl;
	cout << "   " << endl;
	cout << "----------    1- Reserver                ---------- " << endl;
	cout << "----------    2- Modifier la reservation ----------" << endl;
	cout << "----------    3- Annuler la reservation  ----------" << endl;
	cout << "----------    4- Retour                  ----------" << endl;
	cout << "              " << endl;
}
void saisirFormateurReservation(Date& d, Temps& t, int& duree)
{
	int a, m, j;
	int h, min, d1;
	cout << "   " << endl;
	cout << "___________________Entrez la date de reservation : " << endl;
	cout << "   " << endl;
	cin >> j;
	cin >> m;
	cin >> a;
	cout << "   " << endl;
	cout << "___________________Entrez l'heure de la formation : " << endl;
	cout << "   " << endl;
	cin >> h;
	cin >> min;
	cout << "   " << endl;
	cout << "___________________Entrez la duree : " << endl;
	cout << "   " << endl;
	cin >> d1;
	d = Date(j, m, a);
	t = Temps(h, min);
	duree = d1;
}
void ReAffiche(int& rep) {
	cout << "     " << endl;
	cout << "___________________________________________" << endl;
	cout << "    " << endl;
	cout << "****Veuillez vous entrez une autre date****" << endl;
	cout << "           1- OUI" << endl;
	cout << "           2- NON" << endl;
	cout << "   " << endl;
	cout << "___________________________________________" << endl;

	cin >> rep;
}



int main()
{
	int choixAdherant, nb;
	Centre C;
	Salle s;
	fstream fiche;
	string pseudo, mot_de_passe,ch;
	map<string, string>m;
	map<string, string>::iterator it;
	bool trouv;
	m["Nesrine"] = "n1920";
	m["Ezer"] = "e1999";
	m["Mouna"] = "m1999";
	cout << "\n\n\n";
	cout << "\n ------------------------------------------------------------------------\n";

	cout << "__________________________Centre EMN______________________________";
	cout << "\n\n------------------------------------------------------------------------\n";
	cout << "\n\n\n";
	while (1)
	{
		trouv = false;
		cout << "   " << endl;
		cout << "\n___________________entrez votre pseudo" << endl;
		cin >> pseudo;
		cout << "   " << endl;
		cout << "\n___________________entrez votre mot de passe" << endl;
		cin >> mot_de_passe;

		for (it = m.begin(); it != m.end(); it++)
		{
			if ((it->first == pseudo) && (it->second == mot_de_passe))
			{
				trouv = true;

			}

		}
		if (trouv == true) break;
		cout << "   " << endl;
		system("cls");
		cout << "***verifier le pseudo et le mot de passe***" << endl;
		cout << "   " << endl;

	}
	system("cls");
	cout << "\n------------------------------------------------------------------------\n";

	cout << "\n__________________________BIENVENUE______________________________\n";
	cout << "\n\n------------------------------------------------------------------------\n";
	cout << "\n\n\n";

	C.creer(fiche);
	cout << "   " << endl;
	cout << "___________________Donnez les informations de la salle " << endl;
	cout << "   " << endl;
	cin >> C;
	fiche << C;
	cout << "   " << endl;

	cout << "___________________Les Salles sont :" << endl;
	cout << "   " << endl;
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
		float nv_prix, somprix = 0;
		vector<Formation> Form;
		Reservation r;
		first:{afficherChoixAdherent(); }
		

		cout << "    " << endl;
		cin >> choixAdherant;
		cout << " " << endl;
		try
		{
			if (choixAdherant > 5) throw - 1;
		}
		catch (int e)
		{
			cout << " * *********choix invalide, veuillez retaper votre choix**********  " << endl;
		}
		switch (choixAdherant)
		{
		case 1:
			afficherChoixFormateur();
			cout << "     " << endl;
			cin >> choixFormateur;
			cout << "      " << endl;
			try
			{
				if (choixFormateur > 4) throw - 1;
			}
			catch (int e)
			{
				cout << "********** choix invalide,veuillez retaper votre choix **********" << endl;
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
						cout << "   " << endl;
						cout << "___________________Entrez votre choix de materiels :" << endl;
						cin >> choixM;

						while (C.getMateriels().size() < choixM)
						{
							cout << "   " << endl;
							cout << "********** choix invalide retaper votre choix **********" << endl;
							cout << "   " << endl;
							cin >> choixM;
						}

						if (choixM == 3) {
							break;
						}

						cout << "   " << endl;
						cout << "___________________entrez quantite :" << endl;
						cout << "   " << endl;
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

				system("cls");

				cout << "   " << endl;
				cout << "___________________donner le numero de la formation a modifier" << endl;
				cout << "   " << endl;
				cin >> i;

				cout << "_____________________________________________________________" << endl;
				cout << "   " << endl;
				cout << "----------         1-modifier nom de la formation              ----------" << endl;
				cout << "----------         2-modifier niveau de la formation           ----------" << endl;
				cout << "----------         3-modifier le prix de la formation          ----------" << endl;
				cout << "----------         4-modifier les informations d'un formateur  ----------" << endl;
				cout << "   " << endl;
				cout << "_____________________________________________________________" << endl;
				cin >> choice;
				try
				{
					if (choice > 4) throw - 1;
				}
				catch (int e)
				{
					cout << "********** choix invalide,veuillez retaper votre choix **********" << endl;
					cout << "   " << endl;
				}
				switch (choice)
				{

				case 1:	cout << "___________________nv_nomF" << endl;
					cout << "   " << endl;
					cin >> nv_nomF;
					r = C.getReservation()[i];

					f = (r.getFormation());
					f.setNomF(nv_nomF);
					cout << "Le nom de la formation est modifie" << endl;
					//f.afficherFormation();
					r.setformation(f);
					//r.afficherReservation();
					C.setReservation(r, i);
					break;

				case 2:
					cout << "___________________nv_niveau" << endl;
					cout << "   " << endl;
					cin >> nv_niveau;
					r = C.getReservation()[i];

					f = (r.getFormation());
					f.setNiveau(nv_niveau);
					//f.afficherFormation();
					r.setformation(f);
					//r.afficherReservation();
					C.setReservation(r, i);
					break;

				case 3:
					cout << "___________________nv_prix" << endl;
					cout << "   " << endl;
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

				cout << "entrer votre nom" << endl;
				cout << "    " << endl;
				cin >> ch;
				for (int i = 0; i < C.getFormation().size(); i++)
				{
					if (C.getFormation()[i].getnomF() == ch)
					{
						C.getFormation()[i].afficherFormation();
					}
				}
				C.supprimerReservation();
				cout << "Reservation supprimee" << endl;
				break;
				case 4:
					goto first;
					break;

			default:
				break;
			}
		case 77:
			break;
		case 2:


			if (C.getSizeReservation() != 0) {
				cl.saisirClient();
				//cl.afficherClient();
				cout << "   " << endl;
				cout << "********** les formations sont **********" << endl;
				cout << "   " << endl;
				C.afficherFormations();

				cout << "   " << endl;
				cout << "___________________" << C.getSizeFormation() << "- quitter " << endl;
				cout << "   " << endl;

				cout << "___________________Entrez le nombre de formation desiree " << endl;
				cout << "   " << endl;
				cin >> nbre;
				for (int i = 0; i < nbre; i++)
				{

					cout << "___________________Entrez votre choix de formation  " << endl;
					cout << "   " << endl;
					cin >> choixClient;
					if (choixClient == C.getSizeFormation())
					{
						break;
					}
					while (C.getSizeFormation() < choixClient)
					{
						cout << "   " << endl;
						cout << "********* choix invalide retaper votre choix **********" << endl;
						cout << "   " << endl;
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
				cout << "   " << endl;
				cout << "********** aucune reservation disponible **********" << endl;
				cout << " " << endl;
			}

			break;
		case 88:
			break;
		case 3:
			if (C.getSizeReservation() != 0)
			{
				cout << "   " << endl;


				cout << "----------  Les reservations  ----------" << endl;

				C.afficherReservation();
				cout << " " << endl;
			}
			else {
				cout << "   " << endl;
				cout << "********** aucune reservation disponible **********" << endl;
				cout << " " << endl;
			}
			//C.afficherFormations();

			break;

		case 888:
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
			cout << "   " << endl;


			cout << "---------- la somme est  ----------" << endl;
			cout << "   " << endl;
			cout << somprix << endl;
			float revenu = 0, depense = 0, gainCentre;

			revenu = somprix * 30 / 100;
			cout << "   " << endl;
			cout << "___________________Entrez la depenses du centre :" << endl;
			cout << "   " << endl;
			cin >> depense;
			cout << endl;
			gainCentre = revenu - depense;
			cout << "   " << endl;
			cout << "___________________le gain du centre est : " << gainCentre << endl;
			cout << "   " << endl;
			if (gainCentre < depense)
			{
				cout << "   " << endl;
				cout << "******************************" << endl;
				cout << "---------  deficit  ----------" << endl;
				cout << "******************************" << endl;
				cout << "   " << endl;
			}
			else
			{
				cout << "   " << endl;
				cout << "******************************" << endl;
				cout << "----------  succes  ----------" << endl;
				cout << "******************************" << endl;
				cout << "   " << endl;

			}

		}
	} while (choixAdherant != 5);
	return 0;



}