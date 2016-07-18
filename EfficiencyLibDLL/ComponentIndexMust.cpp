
#pragma once
#include "ComponentIndexMust.h"

void ComponentIndexMust::setComponent(TiXmlHandle docMUSTHandle, string nameIndex, string tradeId)
{
	int test = 0;
	TiXmlElement *Component;
	TiXmlElement *ComponentSpread;
	TiXmlNode *IndexPointer;

	TiXmlNode *SpreadPointer;

	spreadString = "";
	// le Id du trade qu'on cherche
	TiXmlElement *Trade = docMUSTHandle.FirstChild("BODY").FirstChild("TRADELIST").FirstChild("MUST_TR").ToElement();

	while (Trade)
	{
		if (strcmp(Trade->FirstChild("TradeId")->ToElement()->GetText(), tradeId.c_str()) == 0)
		{
			Component = Trade->FirstChild("MPTradeData")->FirstChild("MPTRDATA")->FirstChild("MPTrDataXML")->FirstChild("MPTRDATAXML")->
				FirstChild("STRUCTURED_INSTRUMENT")->FirstChild("COMPONENT_LIST")->ToElement();

			IndexPointer = Component->FirstChild("COMPONENT_INDEX");
			while (IndexPointer)
			{
				if (strcmp(IndexPointer->ToElement()->Value(), "COMPONENT_INDEX") == 0) // pour se limiter à la composante index
				{

					if (strcmp(IndexPointer->ToElement()->FirstChild("NAME")->ToElement()->GetText(), nameIndex.c_str()) == 0)
					{

						if (IndexPointer->ToElement()->FirstChild("INDEX_CHAR")->FirstChild("CCY") &&
							IndexPointer->ToElement()->FirstChild("INTBASIS")->ToElement() &&
							IndexPointer->ToElement()->FirstChild("RESET_SCHED")->FirstChild("BASIC_SCHED")->FirstChild("SCHED_DEF")->FirstChild("FREQ")->ToElement() &&
							IndexPointer->ToElement()->FirstChild("INDEX_CHAR")->FirstChild("INDEX")->ToElement() &&
							IndexPointer->ToElement()->FirstChild("INDEX_CHAR")->FirstChild("TERM")->ToElement())
						{
							IndexCcy = IndexPointer->ToElement()->FirstChild("INDEX_CHAR")->FirstChild("CCY")->ToElement()->GetText();

							IndexBasis = IndexPointer->ToElement()->FirstChild("INTBASIS")->ToElement()->GetText();

							IndexFreq = IndexPointer->ToElement()->FirstChild("RESET_SCHED")->FirstChild("BASIC_SCHED")->FirstChild("SCHED_DEF")->FirstChild("FREQ")->ToElement()->GetText();

							IndexIndex = IndexPointer->ToElement()->FirstChild("INDEX_CHAR")->FirstChild("INDEX")->ToElement()->GetText();
							IndexTerm = IndexPointer->ToElement()->FirstChild("INDEX_CHAR")->FirstChild("TERM")->ToElement()->GetText();

						}
						SpreadPointer = IndexPointer->ToElement()->FirstChild("SPREAD_DEF")->FirstChild("BP");
						if (SpreadPointer)
						{
							spreadString = SpreadPointer->ToElement()->GetText();
						}

						if (spreadString == "")
						{
							ComponentSpread = Trade->FirstChild("MPTradeData")->FirstChild("MPTRDATA")->FirstChild("MPTrDataXML")->FirstChild("MPTRDATAXML")->FirstChild("STRUCTURED_INSTRUMENT")->FirstChild("VARIABLE_LIST")->FirstChild("VARIABLE")->ToElement();
							while (ComponentSpread)
							{
								if (strcmp(ComponentSpread->Value(), "VARIABLE") == 0 && strcmp(ComponentSpread->FirstChild("TYPE")->ToElement()->GetText(), "MATRIX") == 0)
								{
									if (strcmp(ComponentSpread->FirstChild("NAME")->ToElement()->GetText(), "MatrixSpread") == 0)
									{
										MatriceMust* matrixOfSpread = new MatriceMust();
										matrixOfSpread->setComponent(docMUSTHandle, "MatrixSpread", tradeId);
										matrixSpread = this->eff_matice_spread(matrixOfSpread->matrice);
										for (std::size_t sizeMat = 0; sizeMat < matrixOfSpread->matrice.size(); sizeMat++)
										{

											spreads.push_back(std::get<2>(matrixSpread[sizeMat]));
										}
										test++;
									}
								}
								ComponentSpread = ComponentSpread->NextSiblingElement();
							}
							test++;
						}
						else
						{
							spreads.push_back(this->eff_convert_rate(spreadString));
							test++;
						}

					}

				}
				IndexPointer = IndexPointer->NextSibling();
			}


		}
		Trade = Trade->NextSiblingElement();
	}

	if (IndexCcy != "" && IndexBasis != "" && IndexFreq != "" && IndexIndex != "" && IndexTerm != "")
	{
		IndexBasisQ = this->eff_convert_basis(IndexBasis);
		IndexFreqQ = this->eff_convert_frequency(IndexFreq.c_str()[0]);
		IndexTermQ = boost::lexical_cast<int>(IndexTerm[0]);

	}
	else
	{
		throw string("Erreur dans la composante INDEX !");
	}
}


boost::shared_ptr<IborIndex> ComponentIndexMust::ConstructIndex(Handle<QuantLib::YieldTermStructure> forwardingTermStructure)  {

	boost::shared_ptr<IborIndex> myIndex(new IborIndex(IndexIndex, IndexTermQ*Months, 2, EURCurrency(), TARGET(), ModifiedFollowing, 1, Actual360(), forwardingTermStructure));
	return myIndex;
}
//attributs

string ComponentIndexMust::convertIndexName(string mustNameString){
	if (mustNameString == "EURIB") return "Euribor";
	else{
		if (mustNameString == "Libor") return "Libor";
		else return "Euribor";
	}
}

Currency ComponentIndexMust::currencyConvert(string currencyName){
	if (currencyName == "EUR") return EURCurrency();
	if (currencyName == "USD") return USDCurrency();
	return EURCurrency();
}


// si on a un spread constant =>remplir la matrice de spread par une seule ligne
void ComponentIndexMust::SetMatrixSpread(Date startDate, Date endDate, vector<Spread> spreads)
{
	if (this->matrixSpread.size() == 0 && this->spreads.size() != 0)
	{
		vector<tuple<Date, Date, Rate>> matrix{ std::make_tuple(startDate, endDate, spreads[0]) };
		matrixSpread = matrix;
	}

}