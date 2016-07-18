#ifndef RATEMUST_H
#define RATEMUST_H

#include "ComponentMust.h"
#include "tinyxml.h"
#include <string>
#include "MatriceMust.h"

using namespace std;
using namespace QuantLib;
#include "DllHeader.h"



	public class EFFICIEBCYLIBDLL_API RateMust : public ComponentMust
{
public:
	// Constructeurs
	RateMust();
	~RateMust();
	void setComponent(TiXmlHandle docMUSTHandle, string nameRate, string tradeId);

	//Attributs
	string rateString;


	vector<Rate>  rates;
	vector<std::tuple<Date, Date, Rate>> matrixRate;


	//méthode
	bool check_matrix(string formule);


	// si on a un taux constant =>remplir la matrice de taux par une seule ligne
	void SetMatrixRate(Date startDate, Date endDate, vector<Rate> rates);

};
#endif