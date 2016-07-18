#pragma once
#include "RateMust.h"
RateMust::RateMust(){}

void RateMust::setComponent(TiXmlHandle docMUSTHandle, string nameRate, string tradeId)
{
	
	//rates = new vector<Rate> ();
	//matrixRate = new vector<std::tuple<Date, Date, Rate>>();
	int test = 0;

	TiXmlElement *Component;
	TiXmlElement *ComponentMatrix;
	TiXmlElement *Trade = docMUSTHandle.FirstChild("BODY").FirstChild("TRADELIST").FirstChild("MUST_TR").ToElement();

	while (Trade)
	{
		if (strcmp(Trade->FirstChild("TradeId")->ToElement()->GetText(), tradeId.c_str()) == 0)
		{
			Component = Trade->FirstChild("MPTradeData")->FirstChild("MPTRDATA")->FirstChild("MPTrDataXML")->FirstChild("MPTRDATAXML")->FirstChild("STRUCTURED_INSTRUMENT")->FirstChild("VARIABLE_LIST")->FirstChild("VARIABLE")->ToElement();

			while (Component)
			{
				// si on a un seul taux 
				if (strcmp(Component->Value(), "VARIABLE") == 0 && strcmp(Component->FirstChild("TYPE")->ToElement()->GetText(), "RATE") == 0)
				{
					if (strcmp(Component->FirstChild("NAME")->ToElement()->GetText(), nameRate.c_str()) == 0)
					{
						if (Component->FirstChild("FORMULA")->FirstChild("FORMULA_STRING")->ToElement()->GetText())
						{
							rateString = Component->FirstChild("FORMULA")->FirstChild("FORMULA_STRING")->ToElement()->GetText();

							if (this->check_matrix(rateString))
							{
								ComponentMatrix = Trade->FirstChild("MPTradeData")->FirstChild("MPTRDATA")->FirstChild("MPTrDataXML")->FirstChild("MPTRDATAXML")->FirstChild("STRUCTURED_INSTRUMENT")->FirstChild("VARIABLE_LIST")->FirstChild("VARIABLE")->ToElement();
								while (ComponentMatrix)
								{
									if (strcmp(ComponentMatrix->Value(), "VARIABLE") == 0 && strcmp(ComponentMatrix->FirstChild("TYPE")->ToElement()->GetText(), "MATRIX") == 0)
									{
										if (strcmp(ComponentMatrix->FirstChild("NAME")->ToElement()->GetText(), "MatrixRates") == 0)
										{
											MatriceMust* matrixOfRates = new MatriceMust();
											matrixOfRates->setComponent(docMUSTHandle, "MatrixRates", tradeId);
											matrixRate=this->eff_matice_rate(matrixOfRates->matrice);
											for (std::size_t sizeMat = 0; sizeMat < matrixOfRates->matrice.size(); sizeMat++)
											{

												rates.push_back((std::get<2>(matrixRate[sizeMat]))/100);
											}
											test++;
										}
									}
									ComponentMatrix = ComponentMatrix->NextSiblingElement();
								}
								test++;
							}
							else
							{
								rates.push_back(this->eff_convert_rate(rateString));
								test++;

							}

						}

					}
				}

				Component = Component->NextSiblingElement();
			}


		}
		Trade = Trade->NextSiblingElement();
	}


	if (test == 0)
	{
		throw string("Erreur de la variable de type Rate");
	}
}

//méthode
bool RateMust::check_matrix(string formule)
{
	int founder = formule.find("Lookup");
	if (founder != string::npos) return true; // si Lookup existe, alors c'est une matrice
	else return false; // sinon c'est une valeur constante

}


// si on a un taux constant =>remplir la matrice de taux par une seule ligne
void RateMust::SetMatrixRate(Date startDate, Date endDate, vector<Rate> rates)
{
	if (this->matrixRate.size() == 0)
	{
		vector<tuple<Date, Date, Rate>> matrix{ std::make_tuple(startDate, endDate, rates[0]) };
		matrixRate=(matrix);
	}

}

RateMust::~RateMust(){
	/*delete matrixRate;
	delete rates;*/
}