#include "Formateur.h"

Formateur::~Formateur(void)
{
}


Formateur::Formateur(string name,  int cinn, int num, string mail, string occupation) :Adherant(name, cinn, num, mail), profession(occupation)
{
}

void Formateur::operator=(const Formateur& f)
{
	Adherant::operator=(f);
	profession = f.profession;
}

void Formateur::saisirFormateur()
{
	saisirAdherant();
	cout << "donner la profession" << endl;
	cin >> profession;
}

void Formateur::afficherFormateur()
{
	afficherAdherant();
	cout << "la profession est" << profession << endl;

}
void Formateur::setProfession(string PROF)
{
	profession = PROF;
}
void Formateur::setNom(string NOM)
{
	nom = NOM;
}
void Formateur::setCIN(int CIN = 0)
{
	cinn = CIN;
}
void Formateur::setTEL(int TEL = 0)
{
	numTel = TEL;
}
void Formateur::setMAIL(string MAIL)
{
	email = MAIL;
}