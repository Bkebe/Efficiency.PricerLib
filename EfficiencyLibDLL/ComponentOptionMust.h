#ifndef COMPONENTOPTIONMUST_H
#define COMPONENTOPTIONMUST_H

#include "ComponentMust.h"
#include "tinyxml.h"
#include <string>
#include "DllHeader.h"
using namespace std;
using namespace QuantLib;



public class EFFICIEBCYLIBDLL_API ComponentOptionMust : public ComponentMust
{
public:
	// Constructeurs
	ComponentOptionMust() :ComponentMust(){}
	void setComponents(TiXmlDocument doc, string nameOption, string tradeId);
	//attributs
	string typeOption;
	string payOrSell;
	string freqString;
	string settlementType;
	Frequency freqQ; // type QuantLib
	DayCounter basisQ; // type QuantLib
	//string firstExpiry;
	//string lastExpiry;


};

#endif