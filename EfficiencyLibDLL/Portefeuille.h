/*
Portefeuille :
Classe qui représente le portefeuille chargé (le MustML)

attribut :
- tableau de trades : nom et type de chaque trade

*/

#ifndef PORTEFEUILLE_H
#define PORTEFEUILLE_H
#include "TradeMust.h"
#include "Catalogue.h"
#include <string>
#include <iostream>
#include <vector>

#include "DllHeader.h"



class EFFICIEBCYLIBDLL_API  Portefeuille
{
public:
	// Constructeurs
	Portefeuille(){}
	Portefeuille(TiXmlHandle docMUSTHandle)
	{
		TradeMust* currentTrade;
		string prod_name;
		string trade_id;
	
		AllTrades = new vector<TradeMust*>();
			TiXmlElement *Component = docMUSTHandle.FirstChild("BODY").FirstChild("TRADELIST").FirstChild("MUST_TR").ToElement();

			while (Component)
			{
				prod_name = Component->FirstChild("MPTradeData")->FirstChild("MPTRDATA")->FirstChild("MPDefName")->ToElement()->GetText();
				trade_id = Component->FirstChild("MPTradeData")->FirstChild("MPTRDATA")->FirstChild("TradeId")->ToElement()->GetText();
				currentTrade = new TradeMust(prod_name, trade_id);
				AllTrades->push_back(currentTrade);
				Component = Component->NextSiblingElement();

			}
		
	}


	//==========================================================
	//============================= Attributs====================
	//===========================================================
	vector<TradeMust*>* AllTrades;

	//==========================================================
	//============================= Méthodes====================
	//===========================================================


	vector<string> vecTypes(string nameProd, Catalogue* cata)
	{
		vector <string> types;
		for (size_t indice = 0; indice < cata->VecCatalogue.size(); indice++)
		{
			if ((cata->VecCatalogue)[indice][0] == nameProd)
			{
				
				types.push_back(cata->VecCatalogue[indice][1]);
			}
		}
		return types;
	}

	vector<string> listTypes(string nameProd, Catalogue* cata)
	{
		vector<string> retour;
		for (size_t indice = 0; indice < cata->VecCatalogue.size(); indice++)
		{
			if (cata->VecCatalogue[indice][0] == nameProd)
			{
				retour.push_back(cata->VecCatalogue[indice][1]);
			}
		}
		return retour;
	}


};

#endif