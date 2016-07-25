#include "ComponentCashFlowMust.h"
void ComponentCashFlowMust::setComponent(TiXmlDocument doc, string nameLeg, string tradeId)
{
	TiXmlHandle docMUSTHandle(&doc);
	TiXmlElement *Component;
	TiXmlElement *Trade = docMUSTHandle.FirstChild("BODY").FirstChild("TRADELIST").FirstChild("MUST_TR").ToElement();

	while (Trade)
	{
		if (strcmp(Trade->FirstChild("TradeId")->ToElement()->GetText(), tradeId.c_str()) == 0)
		{
			Component = Trade->FirstChild("MPTradeData")->FirstChild("MPTRDATA")->FirstChild("MPTrDataXML")->FirstChild("MPTRDATAXML")->FirstChild("STRUCTURED_INSTRUMENT")->
				FirstChild("COMPONENT_LIST")->FirstChild("COMPONENT_CASHFLOW")->ToElement();
			while (Component)
			{
				if (strcmp(Component->Value(), "COMPONENT_CASHFLOW") == 0)
				{

					if (strcmp(Component->FirstChild("NAME")->ToElement()->GetText(), nameLeg.c_str()) == 0)
					{
						CashFlowCcy = Component->FirstChild("PAYOFF_CCY")->FirstChild("CCY")->ToElement()->GetText();

						CashFlowFreq = Component->FirstChild("PAY_SCHED")->FirstChild("BASIC_SCHED")->FirstChild("SCHED_DEF")->FirstChild("FREQ")->ToElement()->GetText();
						freqQ = this->eff_convert_frequency(CashFlowFreq.c_str()[0]);

						CashFlowBasis = Component->FirstChild("BASIS_DEF")->FirstChild("BASIS")->ToElement()->GetText();
						basisQ = this->eff_convert_basis(CashFlowBasis);


					}
				}
				Component = Component->NextSiblingElement();
			}
		}
		Trade = Trade->NextSiblingElement();
	}


}
