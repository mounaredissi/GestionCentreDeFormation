#include "Temps.h"

Temps::Temps(int h, int m):minute(m),heure(h)
{
}

Temps::~Temps(void)
{
}

void Temps::operator=(const Temps& t)
{
	minute = t.minute; 
	heure = t.heure; 
}

bool Temps::operator==(const Temps&t)
{

	return (minute == t.minute && heure == t.heure);
}

Temps Temps::operator+(int c)
{
	return Temps(heure+c,minute);
}

bool Temps::operator<=(const Temps& t)
{
	return (heure <= t.heure && minute <= t.minute);
}

bool Temps::operator>=(const Temps&t)
{
	return (heure >= t.heure && minute >= t.minute);
}
void Temps::afficheTemps()
{
	cout << heure << ":" << minute << endl;;
}



