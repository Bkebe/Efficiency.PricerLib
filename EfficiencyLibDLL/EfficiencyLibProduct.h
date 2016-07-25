#ifndef EFFICIENCYLIBPRODUCT_H
#define EFFICIENCYLIBPRODUCT_H
#pragma once
#include <C:/local/boost_1_60_0/boost/algorithm/string.hpp>
#include <string>
#include "Portefeuille.h"
#include "EfficiencyLibComponents.h"
#include "Mapping.h"
#include "DllHeader.h"

class EFFICIEBCYLIBDLL_API EfficiencyLibProduct{

public:
	//EfficiencyLibProduct(){}
	EfficiencyLibProduct(Date valuationDate, EfficiencyProduct::EfficiencyTypeProduct typeProd, string paths, EfficiencyProduct::EfficiencyModelProduct modelProd, TiXmlDocument hdoc, string trId) :today(valuationDate), typeProduct(typeProd), modelProduct(modelProd), doc(hdoc), trade_id(trId){
		tab_mapp = Mapping(paths, typeProd);
		}
	
	virtual ~EfficiencyLibProduct(){}
private: 
	EfficiencyProduct::EfficiencyTypeProduct typeProduct;
	EfficiencyProduct::EfficiencyModelProduct modelProduct;
	string trade_id;
	//TiXmlHandle Xmlhdldoc;
	TiXmlDocument doc;

	/*Table de Mapping*/
	Mapping tab_mapp;

public:
	void EfficiencyLibProduct::setComponentsForSwap(){

		/* Mapping ... à voir  */
		string nominalMust = tab_mapp.search_mapping("NominalQuantLib");
		string startDateMust = tab_mapp.search_mapping("startDateQuantLib");
		string endDateMust = tab_mapp.search_mapping("endDateQuantLib");
		string fixedRateMust = tab_mapp.search_mapping("FixedRateQuantLib");
		string fixedLegMust = tab_mapp.search_mapping("FixedLegQuantLib");
		string floatingLegMust = tab_mapp.search_mapping("FloatingLegQuantLib");
		string indexMust = tab_mapp.search_mapping("IndexQuantLib");

		// nominal
		ComponentPrincipalMust.setComponent(doc, nominalMust, trade_id);
		Real nominal = ComponentPrincipalMust.nominal[0];

		// settlementDate
		startDateObj.setComponent(doc, startDateMust, trade_id);
		Date settlementDate = startDateObj.dateQ;

		// maturity
		endDateObj.setComponent(doc, endDateMust, trade_id);
		Date maturity = endDateObj.dateQ;

		// fixedRate
		fixedRateObj.setComponent(doc, fixedRateMust, trade_id);
		Rate fixedRate = fixedRateObj.rates[0];
		fixedRateObj.SetMatrixRate(settlementDate, maturity, fixedRateObj.rates);

		//=============FIXED LEG================
		fixedLegObj.setComponent(doc, fixedLegMust, trade_id);
		Frequency fixedLegFrequency = fixedLegObj.freqQ;
		DayCounter fixedLegDayCounter = fixedLegObj.basisQ;

		//=============FLOATING LEG================
		floatingLegObj.setComponent(doc, floatingLegMust, trade_id);
		Frequency floatingLegFrequency = floatingLegObj.freqQ;
		DayCounter floatingLegDayCounter = floatingLegObj.basisQ;

		// Index
		ComponentIndexMust.setComponent(doc, indexMust, trade_id);
		ComponentIndexMust.SetMatrixSpread(settlementDate, maturity, ComponentIndexMust.spreads);

	}
	void EfficiencyLibProduct::setComponentsForCapFloor(){
		/* Mapping .. à vvoir*/
		string nominalMust = tab_mapp.search_mapping("NominalQuantLib");
		string startDateMust = tab_mapp.search_mapping("startDateQuantLib");
		string endDateMust = tab_mapp.search_mapping("endDateQuantLib");
		string fixedRateMust = tab_mapp.search_mapping("StrikeQuantLib");
		string floatingLegMust = tab_mapp.search_mapping("FloatingLegQuantLib");
		string indexMust = tab_mapp.search_mapping("IndexQuantLib");


		// nominal
		ComponentPrincipalMust.setComponent(doc, nominalMust, trade_id);
		Real nominal = ComponentPrincipalMust.nominal[0];


		// settlementDate
		startDateObj.setComponent(doc, startDateMust, trade_id);
		Date settlementDate = startDateObj.dateQ;

		// maturity
		endDateObj.setComponent(doc, endDateMust, trade_id);
		Date maturity = endDateObj.dateQ;

		// fixedRate
		fixedRateObj.setComponent(doc, fixedRateMust, trade_id);
		Rate fixedRate = fixedRateObj.rates[0];
		fixedRateObj.SetMatrixRate(settlementDate, maturity, fixedRateObj.rates);


		//=============FLOATING LEG================
		floatingLegObj.setComponent(doc, floatingLegMust, trade_id);
		Frequency floatingLegFrequency = floatingLegObj.freqQ;
		DayCounter floatingLegDayCounter = floatingLegObj.basisQ;


		// Index
		ComponentIndexMust.setComponent(doc, indexMust, trade_id);
		ComponentIndexMust.SetMatrixSpread(settlementDate, maturity, ComponentIndexMust.spreads);
	}
	void EfficiencyLibProduct::setComponentsForSwaption(){
		string nominalMust = tab_mapp.search_mapping("NominalQuantLib");
		string startDateMust = tab_mapp.search_mapping("startDateQuantLib");
		string maturityOption = tab_mapp.search_mapping("maturityOptionQuantLib");
		string endDateMust = tab_mapp.search_mapping("endDateQuantLib");
		string option = tab_mapp.search_mapping("OptionQuantLib");
		string fixedLegMust = tab_mapp.search_mapping("FixedLegQuantLib");
		string floatingLegMust = tab_mapp.search_mapping("FloatingLegQuantLib");
		string fixedRateMust = tab_mapp.search_mapping("FixedRateQuantLib");
		string indexMust = tab_mapp.search_mapping("IndexQuantLib");
		string typeOp = tab_mapp.search_mapping("OptionType");
		
		// nominal
		ComponentPrincipalMust.setComponent(doc, nominalMust, trade_id);
		Real nominal = ComponentPrincipalMust.nominal[0];

		// style de l'option
		styleOptionObj.setComponent(doc, typeOp, trade_id);
		//string styleOption = styleOptionObj.valeur;
		style = EfficiencyProduct::stringToSwaptionStyle(styleOptionObj.valeur);

		//switch (style){
		//	case EfficiencyProduct::SwaptionStyle::EURO: /* stratOpDate; startSwpadate = endOpDate;  endOpSwapDate*/
		//	{
		//		// First Date : Option
		//		startDateObj.setComponent(doc, startDateMust, trade_id);

		//		// maturité de l'option
		//		maturityObj.setComponent(doc, maturityOption, trade_id);

		//		// date de fin de la swaption
		//		endDateObj.setComponent(doc, endDateMust, trade_id);
		//	}
		//	break;
		//	case EfficiencyProduct::SwaptionStyle::AMER: /* stratOpDate= startSwpaDate + 2j, endOpDate = EarliestDate;  endOpSwapDate*/
		//	{
		//		// First Date : Option
		//		startDateObj.setComponent(doc, startDateMust, trade_id);

		//		// maturité de l'option
		//		maturityObj.setComponent(doc, maturityOption, trade_id);

		//		// date de fin de la swaption
		//		endDateObj.setComponent(doc, endDateMust, trade_id);
		//	}
		//	break;
		//	case EfficiencyProduct::SwaptionStyle::BERM:
		//	{
		//		/*recupérer la freuquence*/
		//	}
		//	break;
		//	default:
		//	{

		//	}
		//	break;

		//}
		// First Date : Option
		startDateObj.setComponent(doc, startDateMust, trade_id);
		Date startDate = startDateObj.dateQ;

		// maturité de l'option
		maturityObj.setComponent(doc, maturityOption, trade_id);
		Date maturity = maturityObj.dateQ;

		// date de fin de la swaption
		endDateObj.setComponent(doc, endDateMust, trade_id);
		Date endDate = endDateObj.dateQ;

		// fixedRate
		fixedRateObj.setComponent(doc, fixedRateMust, trade_id);
		Rate fixedRate = fixedRateObj.rates[0];
		fixedRateObj.SetMatrixRate(maturity, endDate, fixedRateObj.rates);

		// Option
		componentOption.setComponents(doc, option, trade_id);


		//=============FIXED LEG================
		fixedLegObj.setComponent(doc, fixedLegMust, trade_id);
		Frequency fixedLegFrequency = fixedLegObj.freqQ;
		DayCounter fixedLegDayCounter = fixedLegObj.basisQ;

		//=============FLOATING LEG================
		floatingLegObj.setComponent(doc, floatingLegMust, trade_id);
		Frequency floatingLegFrequency = floatingLegObj.freqQ;
		DayCounter floatingLegDayCounter = floatingLegObj.basisQ;

		// Index
		ComponentIndexMust.setComponent(doc, indexMust, trade_id);
		ComponentIndexMust.SetMatrixSpread(startDate, endDate, ComponentIndexMust.spreads);

	}
	virtual Real price() = 0;//Just for tests
	public: Real npvFixedLeg = 0;
			Real npvFloatingLeg = 0;
			Real delta = 0;
			Real gamma = 0;
			Real vega = 0;
			Real theta = 0;
			Date today;




	/* Les Composantes Must*/
	ComponentCashFlowMust ComponentCFlowMust;
	ComponentCashFlowMust floatingLegObj;
	ComponentCashFlowMust fixedLegObj;
	 ComponentIndexMust ComponentIndexMust;
	 MatriceMust MatriceMust;
	 ComponentPrincipalMust ComponentPrincipalMust;
	 DateMust startDateObj;
	 DateMust endDateObj;
	 DateMust maturityObj;
	 RateMust fixedRateObj;
	 EnumMust styleOptionObj;

	 SwapFloatingLeg swapFloatingLeg;
	 SwapFixedLeg swapFixedLeg;
	 ComponentOptionMust componentOption;
	 EfficiencyProduct::SwaptionStyle style;




}; 
#endif