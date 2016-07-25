#include "EnumMust.h"

void EnumMust::setComponent(TiXmlDocument doc, string nameEnum, string tradeId)
{
	    int test = 0;
		TiXmlHandle docMUSTHandle(&doc);
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
					if (strcmp(Component->Value(), "VARIABLE") == 0 && strcmp(Component->FirstChild("TYPE")->ToElement()->GetText(), "ENUM") == 0)
					{

						if (strcmp(Component->FirstChild("NAME")->ToElement()->GetText(), nameEnum.c_str()) == 0)
						{
							if (Component->FirstChild("FORMULA")->FirstChild("FORMULA_STRING")->ToElement()->GetText())
							{
								valeur = Component->FirstChild("FORMULA")->FirstChild("FORMULA_STRING")->ToElement()->GetText();
								//SuppDoubleQuotes(&valeur);
								test = 1;
							}
						}
					}

					Component = Component->NextSiblingElement();
				}
			}
			Trade = Trade->NextSiblingElement();
		}
	
	

}
