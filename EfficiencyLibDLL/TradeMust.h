/*
TradeMust :
Classe du trade

Constructeur :
A comme argument le chemin du fichier XML (le MUSTML)
remplit les attributs par les données récupérées du MustML
attributs :
-	std::string nameProduct; :	 Le nom du produit
-	std::string tradeID;	: le ID du trade

*/

#ifndef TRADEMUST_H
#define TRADEMUST_H
#include "tinyxml.h"
#include <string>
#include "DllHeader.h"
//using namespace std;

//EXPIMP_TEMPLATE template class EFFICIEBCYLIBDLL_API string;

EXPIMP_TEMPLATE template class EFFICIEBCYLIBDLL_API std::allocator<char>;
EXPIMP_TEMPLATE template class EFFICIEBCYLIBDLL_API std::basic_string<char, std::char_traits<char>, std::allocator<char> >;

class EFFICIEBCYLIBDLL_API TradeMust //: public ComponentMust
{
public:
	// Constructeurs
	TradeMust(std::string prodName, std::string trade_id);

	// ordreTrade le numéro d'ordre du trade dans le MUSTML lu
	TradeMust(char* path, int ordreTrade);



	//attributs

	std::string nameProduct;
	std::string tradeID;
	std::string typeProduct;
	std::string modele;



};

#endif