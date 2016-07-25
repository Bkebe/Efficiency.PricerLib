
/*
Classe EnumMust pour chercher les variables de type Enum
*/


#ifndef ENUMMUST_H
#define ENUMMUST_H

#include "ComponentMust.h"
#include "tinyxml.h"
#include <string>
#include "DllHeader.h"

using namespace std;
using namespace QuantLib;

class EFFICIEBCYLIBDLL_API EnumMust : public ComponentMust
{
public:
	EnumMust() {}
	void setComponent(TiXmlDocument doc, string nameEnum, string tradeId);


	//Attributs
	string valeur;

};

#endif