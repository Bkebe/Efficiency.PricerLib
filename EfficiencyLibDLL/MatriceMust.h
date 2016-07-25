/*
MatriceMust :
Classe qui cherche les variables(sur le MustML) déclarées comme matrices
crée une matrice de même taille et remplit les cases par les données sur MustML
les données qui seront stockées sont de type string
Constructeur :
- prend en paramètre le chamin du MustML et le nom de la variable matrice

Attributs :
- vector<vector<string>> matrice  : Matrice de 2 dimensions, sa taille n'est pas fixé au début, sa taille est définie dans le constructeur.
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

	//map contient la matrice qui, pour chaque paramètre Must  affecte son equivalent QuantLib
	vector<vector<string>> matrice;

};
#endif