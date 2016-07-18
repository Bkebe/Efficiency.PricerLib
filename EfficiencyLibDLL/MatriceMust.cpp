#include "MatriceMust.h"
void MatriceMust::setComponent(TiXmlHandle docMUSTHandle, string nameMatrix, string tradeId) // constructeur
{
	int height; // nombre de lignes
	int width;  // nombre de colonnes

	// création de la matrice
	TiXmlElement *Component;


	TiXmlElement *Trade = docMUSTHandle.FirstChild("BODY").FirstChild("TRADELIST").FirstChild("MUST_TR").ToElement();

	while (Trade)
	{
		if (strcmp(Trade->FirstChild("TradeId")->ToElement()->GetText(), tradeId.c_str()) == 0)
		{

			Component = Trade->FirstChild("MPTradeData")->FirstChild("MPTRDATA")->FirstChild("MPTrDataXML")->FirstChild("MPTRDATAXML")->FirstChild("STRUCTURED_INSTRUMENT")->FirstChild("VARIABLE_LIST")->FirstChild("VARIABLE")->ToElement();

			while (Component)
			{
				if (strcmp(Component->FirstChild("NAME")->ToElement()->GetText(), nameMatrix.c_str()) == 0 && strcmp(Component->Value(), "VARIABLE") == 0)
				{
					height = boost::lexical_cast<int>(Component->FirstChild("META")->FirstChild("HEIGHT")->ToElement()->GetText());
					width = boost::lexical_cast<int>(Component->FirstChild("META")->FirstChild("WIDTH")->ToElement()->GetText());
					vector<vector<string>> mat(height, vector<string>(width));
					matrice = mat;
					int row, col;
					TiXmlElement *Item = Component->FirstChild("VALUES")->FirstChild("ITEM")->ToElement();
					while (Item)
					{
						row = boost::lexical_cast<int>(Item->FirstChild("ROW")->ToElement()->GetText());
						col = boost::lexical_cast<int>(Item->FirstChild("COL")->ToElement()->GetText());
						matrice[row - 1][col - 1] = Item->FirstChild("FORMULA")->ToElement()->GetText();
						Item = Item->NextSiblingElement();
					}

				}
				Component = Component->NextSiblingElement();
			}

		}
		Trade = Trade->NextSiblingElement();
	}// fin de while(Trade)

}