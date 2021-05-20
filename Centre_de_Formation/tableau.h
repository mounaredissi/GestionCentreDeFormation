#pragma once
#include<iostream>
using namespace std;
template<class T>
class tableau
{
	T tab[100];
	int nb;
public:
	float somme();
	tableau(int =1);
	void ajouter(T);
	T operator[](int);
	void affichertemp();
};

template<class T>
inline float tableau<T>::somme()
{
	float s = 0.0;
	for (int i = 1; i < nb; i++)
	{
		s = s + tab[i];
	}
	return s;
}

template<class T>
inline tableau<T>::tableau(int n)
{
	nb = n;
}

template<class T>
inline void tableau<T>::ajouter(T a)
{
	if (nb < 100)
	{
		tab[nb] = a;
		nb++;
	}
}

template<class T>
inline T tableau<T>::operator[](int i)
{
	return tab[i];
}

template<class T>
inline void tableau<T>::affichertemp()
{
	float s = 0.0;
	for (int i = 1; i <nb ; i++)
	{
		cout << "les prix de l'indice" << endl;
		cout <<tab[i] << endl;
	}
}
