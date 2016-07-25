#ifndef EFFICIENCYLIBPRODUCTS_H
#define EFFICIENCYLIBPRODUCTS_H
#pragma once
//disable warnings on 255 char debug symbols
#pragma warning (disable : 4786)
//disable warnings on extern before template instantiation
#pragma warning (disable : 4231)


#include "MustVanilleSwap.h"
#include "MustCapFloor.h"
#include "MustSwaption.h"
#include "DllHeader.h"


using namespace std;
EXPIMP_TEMPLATE template class EFFICIEBCYLIBDLL_API std::vector<EfficiencyLibProduct*>;

class EFFICIEBCYLIBDLL_API EfficiencyLibProducts{

public:
	//EfficiencyLibProducts(){}
	EfficiencyLibProducts(Date valuationdate, TiXmlDocument hdldoc) : today(valuationdate), doc(hdldoc), portefeuille(hdldoc), catalogue(new Catalogue()){}
	/*Parametrage des modèles et des types de produits*/
	void  setModelsProductsTypes();

	/* Construction de tous les produits "Must Trade" qui sont dans le portefeuille*/
	void  makeProducts();


	void setMarketData(boost::shared_ptr<QuantLib::YieldTermStructure> yieldTermStructure);
	/* tous les trades du portefeuille*/
	std::vector<EfficiencyLibProduct*> AllProducts;
	
	RelinkableHandle<YieldTermStructure> forwardingTermStructure;
public:
	Portefeuille portefeuille;
private:
	//TiXmlHandle Xmlhdldoc;
	TiXmlDocument doc;
	Catalogue* catalogue;
	Date today; /* valuation date*/

}; 

#endif