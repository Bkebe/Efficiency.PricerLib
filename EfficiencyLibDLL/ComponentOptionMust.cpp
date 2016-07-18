#include "ComponentOptionMust.h"

void ComponentOptionMust::setComponents(TiXmlHandle docMUSTHandle, string nameOption, string tradeId)
{

	TiXmlElement *Component;
	TiXmlElement *elem;

	TiXmlElement *Trade = docMUSTHandle.FirstChild("BODY").FirstChild("TRADELIST").FirstChild("MUST_TR").ToElement();

	while (Trade)
	{
		if (strcmp(Trade->FirstChild("TradeId")->ToElement()->GetText(), tradeId.c_str()) == 0)
		{
			Component = Trade->FirstChild("MPTradeData")->FirstChild("MPTRDATA")->FirstChild("MPTrDataXML")->FirstChild("MPTRDATAXML")->FirstChild("STRUCTURED_INSTRUMENT")->
				FirstChild("COMPONENT_LIST")->FirstChild("COMPONENT_OPTION")->ToElement();
			while (Component)
			{
				if (strcmp(Component->Value(), "COMPONENT_OPTION") == 0)
				{

					if (strcmp(Component->FirstChild("NAME")->ToElement()->GetText(), nameOption.c_str()) == 0)
					{
						payOrSell = Component->FirstChild("PORS")->ToElement()->GetText();
						freqString = Component->FirstChild("EXPIRY_SCHED")->FirstChild("BASIC_SCHED")->FirstChild("SCHED_DEF")->FirstChild("FREQ")->ToElement()->GetText();
						settlementType = Component->FirstChild("EXPIRY_SCHED")->FirstChild("ACTUAL_SETTLE_MODE")->ToElement()->GetText();

						//firstExpiry = Component->FirstChild("EXPIRY_SCHED")->FirstChild("BASIC_SCHED")->FirstChild("START_DATE")->FirstChild("DATE_FORMULA")->FirstChild("TARGET")->FirstChild("ATTRIBUTE")->ToElement()->GetText();
						//lastExpiry = Component->FirstChild("EXPIRY_SCHED")->FirstChild("BASIC_SCHED")->FirstChild("END_DATE")->FirstChild("DATE_FORMULA")->FirstChild("TARGET")->FirstChild("ATTRIBUTE")->ToElement()->GetText();

					}
				}
				break;
				Component = Component->NextSiblingElement();
			}

			//****** recherche du type de l'option

			elem = Trade->FirstChild("MPTradeData")->FirstChild("MPTRDATA")->FirstChild("MPTrDataXML")->FirstChild("MPTRDATAXML")->FirstChild("STRUCTURED_INSTRUMENT")->
				FirstChild("VARIABLE_LIST")->FirstChild("VARIABLE")->ToElement();

			while (elem)
			{
				if (strcmp(elem->Value(), "VARIABLE") == 0)
				{

					if (strcmp(elem->FirstChild("NAME")->ToElement()->GetText(), "OptionStyle") == 0)
					{
						typeOption = elem->FirstChild("FORMULA")->FirstChild("FORMULA_STRING")->ToElement()->GetText();
					}
					break;
				}
				elem = elem->NextSiblingElement();
			}

			break;
		}
		Trade = Trade->NextSiblingElement();
	}

}