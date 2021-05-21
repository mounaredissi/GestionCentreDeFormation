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
		cout << "___________________Donnez le nom :";
		cin >> nom;
		cout << "    " << endl;

		cout << "___________________Donnez le CIN :";
		cin >> cinn;
		cout << "    " << endl;

		cout << "___________________Donnez le numero de telephone :";
		cin >> numTel;
		cout << "    " << endl;

		cout << "___________________Donnez l'e-mail :";
		cin >> email;
		cout << "    " << endl;




	}

	void Adherant::afficherAdherant()
	{
		cout << "___________________le nom est " << nom << endl;
		cout << "    " << endl;
		cout << "___________________le CIN est " << cinn << endl;
		cout << "    " << endl;

		cout << "___________________le numero de telephone est" << numTel << endl;
		cout << "    " << endl;

		cout << "___________________l'email est " << email << endl;
		cout << "    " << endl;

	}




