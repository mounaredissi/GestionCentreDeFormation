#include "Client.h"


Client::Client(string name,  int cinn, int num, string mail, string occupation) :Adherant(name, cinn, num, mail), fonction(occupation)
{
	
}

Client::~Client(void)
{
}

void Client::saisirClient()
{
	saisirAdherant();
	cout << "___________________Entrez la fonction du client :  " << endl;
	cin >> fonction;
	cout << "    " << endl;
}

void Client::afficherClient()
{
	afficherAdherant();
	cout << "___________________la fonction est :  " << fonction << endl;
	cout << "    " << endl;
}

