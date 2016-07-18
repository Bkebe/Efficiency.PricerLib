#ifndef CATALOGUE_H
#define CATALOGUE_H

#include "tinyxml.h"
#include <string>
#include <iostream>
#include <tuple>
#include <vector> 
#include "DllHeader.h"
using namespace std;

class EFFICIEBCYLIBDLL_API Catalogue
{
public:
	//Catalogue::Catalogue(){}
	 Catalogue();

	//=================================================================
	//===============   Attribut   =====================================
	//=================================================================
	vector<vector<string>> VecCatalogue; // nameProd, typeProd , activate et XML path

	vector<vector<string>>VecCatalogueType; // typeProd et XML path

	vector<string> VecCatalogueModel; // noms des modeles

	//=================================================================
	//===============   Méthodes   =====================================
	//=================================================================

	//SuppDoublons : pour supprimer les doublons dans un vecteur de string
	vector<string> SuppDoublons(vector<string> vec);



	// *******************
	// update catalogue par les noms de produits, les types et les chemins des XML

	void updateCatalogue(char* typeProd, char* nameProd, char* activated, char* modele);

	//*******************

	bool isInCatalogue(string typeProd, string nameProd);


	//*******************

	bool doublonsActifs(string nameProd, string activated, int indice);

	//**********************************
	void deleteCatalogue();

	//**********************************
	string SearchType(string nameProd);

	//**********************************
	string SearchModel(string nameProd);

};



#endif


