#include "Adherant.h"

Adherant::Adherant(string name ,  int cinn, int num , string mail):nom(name),cinn(cinn),numTel(num),email(mail)
{

}

Adherant::~Adherant(void)
{
}


void Adherant::operator=(const Adherant& a)
{
	nom = a.nom;

	numTel = a.numTel; 
	email = a.email; 
	cinn = a.cinn;

}

void Adherant::saisirAdherant()
{
	cout << "donner le nom" << endl;
	cin >> nom;
	cout << "donner le CIN" << endl;
	cin >> cinn;
	cout << "donner le numero de telephone" << endl;
	cin >> numTel;
	cout << "donner l'e-mail" << endl;
	cin >> email;



}

void Adherant::afficherAdherant()
{
	cout << "le nom est" << nom << endl;
	cout << "le CIN est " << cinn << endl;
	cout << "le numero de telephone est" << numTel << endl;
	cout << "l'email est " << email << endl;
}
