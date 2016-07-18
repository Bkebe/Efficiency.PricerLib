#ifndef COMPONENTCASHFLOWLMUST_H
#define COMPONENTCASHFLOWLMUST_H

#include "ComponentMust.h"
#include "tinyxml.h"
#include <string>
#include "DllHeader.h"
using namespace std;
using namespace QuantLib;



public class EFFICIEBCYLIBDLL_API  ComponentCashFlowMust : public ComponentMust
{
public:
	ComponentCashFlowMust(){}
	// Constructeurs
	void setComponent(TiXmlHandle docMUSTHandle, string nameLeg, string tradeId);

	//attributs
	string CashFlowCcy;
	string CashFlowFreq;
	string CashFlowBasis;
	Frequency freqQ; // type QuantLib
	DayCounter basisQ; // type QuantLib

};
#endif