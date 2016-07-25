#ifndef COMPONENTINDEXMUST_H
#define COMPONENTINDEXMUST_H

#include "tinyxml.h"
#include "ComponentMust.h"
#include "MatriceMust.h"
#include "DllHeader.h"
using namespace std;
using namespace QuantLib;



public class EFFICIEBCYLIBDLL_API ComponentIndexMust : public ComponentMust
{
public:
	// Constructeurs
	ComponentIndexMust() :ComponentMust(){}
	void setComponent(TiXmlDocument doc, string nameIndex, string tradeId);

	boost::shared_ptr<IborIndex> ConstructIndex(Handle<QuantLib::YieldTermStructure> forwardingTermStructure);
	//attributs

	string convertIndexName(string mustNameString);

	Currency currencyConvert(string currencyName);


	// si on a un spread constant =>remplir la matrice de spread par une seule ligne
	void SetMatrixSpread(Date startDate, Date endDate, vector<Spread> spreads);

public:
	string IndexCcy;
	string IndexFreq;
	string IndexBasis;
	string IndexTerm;
	string IndexIndex;
	int IndexTermQ;
	Frequency IndexFreqQ; // type QuantLib
	DayCounter IndexBasisQ; // type QuantLib
	string spreadString; // formule du spread
	vector<Spread> spreads; // vacteur contenant les spreads
	std::vector<std::tuple<Date, Date, Spread>> matrixSpread; // matrice avec les dates et les spreads


};
#endif