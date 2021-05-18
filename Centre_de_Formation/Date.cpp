#include "Date.h"

Date::Date(int j, int m, int a):jour(j),mois(m),annee(a)
{
}

Date::~Date(void)
{
}

void Date::afficher()
{
    cout << "le " << jour << "/" << mois << "/" << annee << endl;

}

void Date::saisirdate()
{
        cout<<"saisir le jour"<<endl;
        cin>>jour;
        cout<<"saisir le mois"<<endl;
        cin>>mois;
        cout<<"saisir l'annee"<<endl;
        cin>>annee;
    
}

void Date::operator=(const Date& d)
{
    jour = d.jour;
    mois = d.mois; 
    annee = d.annee; 
}

bool Date::operator==(const Date&d)
{
    return (jour == d.jour && mois == d.mois && annee == d.annee);
}
