#pragma once
#include<iostream>
using namespace std;


class Temps
{
protected :
	int minute;
	int heure;
public: 
	Temps(int = 0, int = 0);
	~Temps(void);
	void operator =(const Temps&);
	bool operator ==(const Temps&);
	Temps operator +(int);
	bool operator <= (const Temps&);
	bool operator >=(const Temps&);
	void afficheTemps();
};

