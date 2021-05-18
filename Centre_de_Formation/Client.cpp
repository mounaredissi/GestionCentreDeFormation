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
	cout << "entrer la fonction du client" << endl;
	cin >> fonction;
}

void Client::afficherClient()
{
	afficherAdherant();
	cout << "la fonction est " << fonction << endl;
}

