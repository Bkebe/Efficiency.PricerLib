#include "TradeMust.h"


TradeMust::TradeMust(std::string prodName, std::string trade_id)
{
	this->nameProduct = prodName;
	this->tradeID = trade_id;
}

// ordreTrade le numéro d'ordre du trade dans le MUSTML lu
TradeMust::TradeMust(char* path, int ordreTrade)
{
	int trade_counter = 0;
	TiXmlDocument doc(path);
	if (doc.LoadFile())
	{
		TiXmlHandle docMUSTHandle(&doc);
		TiXmlElement *Component = docMUSTHandle.FirstChild("BODY").FirstChild("TRADELIST").FirstChild("MUST_TR").FirstChild("MPTradeData")
			.FirstChild("MPTRDATA").ToElement();

		while (Component)
		{
			if (trade_counter == ordreTrade)
			{
				nameProduct = Component->FirstChild("MPDefName")->ToElement()->GetText();
				tradeID = Component->FirstChild("TradeId")->ToElement()->GetText();
			}
			trade_counter++;
			Component = Component->NextSiblingElement();

		}
	}
}

