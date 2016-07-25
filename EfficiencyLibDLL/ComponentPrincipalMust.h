#ifndef COMPONENTPRINCIPALMUST_H
#define COMPONENTPRINCIPALMUST_H

#include "tinyxml.h"
#include "ComponentMust.h"
#include "DateMust.h"
#include "DllHeader.h"
using namespace std;
using namespace QuantLib;




public class EFFICIEBCYLIBDLL_API  ComponentPrincipalMust : ComponentMust
{
public:
	// Constructeurs
	ComponentPrincipalMust(){}
	void setComponent(TiXmlDocument doc, string namePrincipal, string tradeId);

	//*** Méthode d'amortissement

	void AmortNotional(Date startDate, Date endDate, int periodicite, string formule);
	//attributs
	std::vector<Real> nominal;
	string principalCcy;
	string tauxAmort;
	Rate amortRate;

	string amortYorN;
	string freq;
	Frequency freqQ;

	string startDate;
	Date startDateQ;

	string endDate;
	Date endDateQ;
	string formuleAmort;


};
#endif