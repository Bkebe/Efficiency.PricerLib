/*
Mapping :
Classe qui fait le mapping entre Must et QuantLib

Constructeur :
-Appelle le fichier XML de param�trage du produit 

-Remplit les attributs par les �l�ments du XML de param�trage


vecteur de triplets:
- nom de la composante MUST
- type de la composante MUST
- nom correspond dans QuantLib
*/

#ifndef MAPPING_H
#define MAPPING_H

#include "tinyxml.h"
#include <string>
#include <iostream>
#include <tuple>
#include <vector> 
#include "EnumsProducts.h"

//#include <sstream>
//#include <set>
//#include <iterator>
//#include <algorithm>

using namespace std;
using namespace System;
using namespace System::Runtime::InteropServices; // marshal : conversion
using namespace System::Windows::Forms;
#include "DllHeader.h"

EXPIMP_TEMPLATE template class EFFICIEBCYLIBDLL_API vector<vector<string>>;
EXPIMP_TEMPLATE template class EFFICIEBCYLIBDLL_API vector<std::tuple<std::string, std::string, std::string>>;

class EFFICIEBCYLIBDLL_API Mapping
{
public:
	// Constructeurs

	Mapping();
	~Mapping();
	Mapping(string path, EfficiencyProduct::EfficiencyTypeProduct typePrduct);

	// ========================================================
	// =================Attributs==============================
	// ========================================================

	string typeProd; // type du produit
	//map contient la matrice qui, pour chaque param�tre Must  affecte son equivalent QuantLib
	std::vector<std::tuple<std::string, std::string, std::string>> map;





	// ========================================================
	// =================M�thodes===============================
	// ========================================================

	//Input : le nom de la composante sur QuantLib
	//Output : le nom de la composante sur le MustML

	std::string  search_mapping(std::string valSearch);


	//Input : nom de la variable QuantLib  , et nom de la variable Must qu'on veut modifier
	//le fichier XML de param�trage
	void  updateXML(char* valQuantLib, char* newVal);


	////Afficher la table de mapping du produit choisi dans le combobox dans la dataGrid
	//void  affiche_data(System::Windows::Forms::ComboBox^  comboBox1, System::Windows::Forms::DataGridView^  dataG);


	////remplir une matrice par les �l�ments de la nouvelle table de mapping
	//	vector<vector<string>>  tableVector(System::Windows::Forms::DataGridView^  dataG);


	//creat_Table : pour cr�er une nouvelle table de mapping
	//enregistrer les donn�es dans un nouveau xml
	void  creat_Table(string nameProd, vector<vector<string>> vecTable);



	// updateCatalogue : pour ajouter le type et et le chemin du xml

	void  updateCatalogue(char* typeProd);


};



#endif


