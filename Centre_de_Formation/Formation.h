#pragma once
#include<string>
#include<iostream>
#include "Date.h"
#include"Temps.h"
#include"Client.h"
#include<vector>
#include "Formateur.h"
using namespace std;



class Formation
{
    string nom_formation;
    string niveau;
    vector <Client> tab;
    float prix;
    Date dateDebutFormation;
    Date dateFinFormation;
    vector<Temps> heureDeDebutFormation;
    vector <Temps> heureDeFinFormation;
    vector<Date> datesFormation; 
    Formateur formateur;
    vector<int> maxClient;
    vector <int>nbrClientRestant; 

public:
    Formation();
    Formation(string , string , float,  int, int, int,int,int, int,Formateur);
   
    void operator=(const Formation&); 

    ~Formation(void);
    void saisirFormation();
    void afficherFormation();
    void updateDate(vector<Date>,vector<Temps>, vector<Temps>,vector<int>);
    string getNom();
    void afficherNomFormation();
    void updateClient(Client&  );
    void afficherClients();
    vector<Client> getClient();
 
    bool rechercheComplet(); 
};

