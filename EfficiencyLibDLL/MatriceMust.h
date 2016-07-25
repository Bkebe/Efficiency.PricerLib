/*
MatriceMust :
Classe qui cherche les variables(sur le MustML) d�clar�es comme matrices
cr�e une matrice de m�me taille et remplit les cases par les donn�es sur MustML
les donn�es qui seront stock�es sont de type string
Constructeur :
- prend en param�tre le chamin du MustML et le nom de la variable matrice

Attributs :
- vector<vector<string>> matrice  : Matrice de 2 dimensions, sa taille n'est pas fix� au d�but, sa taille est d�finie dans le constructeur.
*/


#ifndef MATRICEMUST_H
#define MATRICEMUST_H

#include "tinyxml.h"
#include <string>
#include <iostream>
#include <vector> 
#include "ComponentMust.h"

using namespace std;


#include "DllHeader.h"


	public class EFFICIEBCYLIBDLL_API  MatriceMust : public ComponentMust
{
public:
	// Constructeurs
	MatriceMust() {}
	void setComponent(TiXmlDocument doc, std::string nameMatrix, std::string tradeId);

	//map contient la matrice qui, pour chaque param�tre Must  affecte son equivalent QuantLib
	vector<vector<string>> matrice;

};
#endif