#include "Formation.h"

Formation::Formation()
{
}

Formation::Formation(string nom, string level, float price, int j, int m, int a, int j1, int m1, int a1,  Formateur f) :nom_formation(nom), niveau(level),prix(price), dateDebutFormation(j, m, a), dateFinFormation(j1, m1, a1)
{
	formateur = f;
}

void Formation::operator=(const Formation& f )
{
	nom_formation = f.nom_formation;
	niveau = f.niveau; 
	prix = f.prix; 
	dateDebutFormation = f.dateDebutFormation; 
	dateFinFormation = f.dateFinFormation;
	formateur = f.formateur; 
	for (int i = 0; i < f.heureDeDebutFormation.size(); i++)
	{
		heureDeDebutFormation.push_back(f.heureDeDebutFormation[i]);
		heureDeFinFormation.push_back(f.heureDeFinFormation[i]);
		datesFormation.push_back(f.datesFormation[i]);
		maxClient.push_back(f.maxClient[i]);
		nbrClientRestant.push_back(f.nbrClientRestant[i]);
	}
}



Formation::~Formation(void)
{
}

void Formation::saisirFormation()
{
	Date d,d1;


	cout << "taper nom formation" << endl; 
	cin >> nom_formation;
	cout << "taper niveau du formation " << endl;
	cin >> niveau;
	cout << "taper lr prix de la formation" << endl; 
	cin >> prix; 
	
	cout << "saisir le formateur" << endl; 
	formateur.saisirFormateur();




}

void Formation::afficherFormation()
{
	cout << "le nom de la formation est " << nom_formation << endl;;
	cout << "le niveau de la formation " << niveau << endl;
	cout << "le prix de la formation " << prix << endl;
	cout << "la date de debut de la formation" << endl;
	dateDebutFormation.afficher();
	cout << "la date de fin de la formation" << endl;
	dateFinFormation.afficher();
	cout << "les dates et les heures de la formation:" << endl; 
	for (int i = 0; i < heureDeDebutFormation.size(); i++)
	{
		datesFormation[i].afficher();
		heureDeDebutFormation[i].afficheTemps();
		heureDeFinFormation[i].afficheTemps();	
	}


	//cout << "information sur le formateur :" << endl; 
	//formateur.afficherFormateur();
	
}

void Formation::updateDate(vector<Date> dateDebut, vector<Temps> tempsDebut, vector<Temps> tempsFin,vector <int> capMax)
{

	dateDebutFormation = dateDebut[0];
	dateFinFormation = dateDebut[dateDebut.size()-1];


	for (int i = 0; i < dateDebut.size(); i++) 
	{
		datesFormation.push_back(dateDebut[i]);
		heureDeDebutFormation.push_back(tempsDebut[i]);
		heureDeFinFormation.push_back(tempsFin[i]);
		maxClient.push_back(capMax[i]);
		nbrClientRestant.push_back(capMax[i]);
		
	}


}

string Formation::getNom()
{
	return nom_formation;
}

void Formation::afficherNomFormation()
{
	cout << "Le nom de la formation est" << nom_formation;
}


void Formation::updateClient(Client& cl )
{
	tab.push_back(cl);

	for (int j = 0; j < nbrClientRestant.size(); j++)
	{
		nbrClientRestant[j] -= 1;
	}
}

void Formation::afficherClients()
{
	for (int i = 0; i < tab.size(); i++)
	{
		tab[i].afficherClient();
	}
}

vector<Client> Formation::getClient()
{
	return tab;
}



bool Formation::rechercheComplet()
{
	for (int i = 0; i < nbrClientRestant.size();i++) {
		if (nbrClientRestant[i] == 0) {
			return true; 
			break;
		}
	}
	return false; 
}
