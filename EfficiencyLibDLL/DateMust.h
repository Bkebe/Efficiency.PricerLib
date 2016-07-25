#ifndef DATEMUST_H
#define DATEMUST_H

#include "ComponentMust.h"
#include "tinyxml.h"
#include <string>
#include "DllHeader.h"
using namespace std;
using namespace QuantLib;




public class  EFFICIEBCYLIBDLL_API DateMust : public ComponentMust
{
public:
	// Constructeurs
	DateMust() {}
	void setComponent(TiXmlDocument doc, string nameDate, string tradeId);

	//attributs
	string dateString;
	Date dateQ;


};
#endif